require 'pathname'

require 'test/unit/testsuite'
require 'test/unit/collector'

module Test
  module Unit
    module Collector
      class Load
        include Collector

        attr_reader :patterns, :excludes, :base

        def initialize
          super
          @system_excludes = [/~\z/, /\A\.\#/]
          @system_directory_excludes = [/\A(?:CVS|\.svn|\.git)\z/]
          @patterns = [/\Atest[_\-].+\.rb\z/m, /[_\-]test\.rb\z/]
          @excludes = []
          @base = nil
          @require_failed_infos = []
        end

        def base=(base)
          base = Pathname(base) unless base.nil?
          @base = base
        end

        def collect(*froms)
          add_load_path(@base) do
            froms = ["."] if froms.empty?
            test_suites = []
            already_gathered = find_test_cases
            froms.each do |from|
              from = resolve_path(from)
              if from.directory?
                test_suite = collect_recursive(from, already_gathered)
                test_suites << test_suite unless test_suite.tests.empty?
              else
                collect_file(from, test_suites, already_gathered)
              end
            end
            add_require_failed_test_suite(test_suites)

            if test_suites.size > 1
              test_suite = TestSuite.new("[#{froms.join(', ')}]")
              sort(test_suites).each do |sub_test_suite|
                test_suite << sub_test_suite
              end
            else
              test_suite = test_suites.first
            end

            test_suite
          end
        end

        def find_test_cases(ignore=[])
          test_cases = []
          TestCase::DESCENDANTS.each do |test_case|
            test_cases << test_case unless ignore.include?(test_case)
          end
          ignore.concat(test_cases)
          test_cases
        end

        private
        def collect_recursive(path, already_gathered)
          sub_test_suites = []

          if path.directory?
            directories, files = path.children.partition do |child|
              child.directory?
            end

            files.each do |child|
              next if excluded_file?(child.basename.to_s)
              collect_file(child, sub_test_suites, already_gathered)
            end

            directories.each do |child|
              next if excluded_directory?(child.basename.to_s)
              sub_test_suite = collect_recursive(child, already_gathered)
              sub_test_suites << sub_test_suite unless sub_test_suite.empty?
            end
          else
            unless excluded_file?(path.basename.to_s)
              collect_file(path, sub_test_suites, already_gathered)
            end
          end

          test_suite = TestSuite.new(path.basename.to_s)
          sort(sub_test_suites).each do |sub_test_suite|
            test_suite << sub_test_suite
          end
          test_suite
        end

        def collect_file(path, test_suites, already_gathered)
          @program_file ||= File.expand_path($0)
          expanded_path = path.expand_path
          return if @program_file == expanded_path.to_s
          add_load_path(expanded_path.dirname) do
            begin
              require(path.basename.to_s)
            rescue LoadError
              @require_failed_infos << {:path => expanded_path, :exception => $!}
            end
            add_test_cases(test_suites, find_test_cases(already_gathered))
          end
        end

        def resolve_path(path)
          if @base
            @base + path
          else
            Pathname(path)
          end
        end

        def add_load_path(path)
          $LOAD_PATH.unshift(path.to_s) if path
          yield
        ensure
          $LOAD_PATH.delete_at($LOAD_PATH.index(path.to_s)) if path
        end

        def excluded_directory?(base)
          @system_directory_excludes.any? {|pattern| pattern =~ base}
        end

        def excluded_file?(base)
          return true if @system_excludes.any? {|pattern| pattern =~ base}

          patterns = @patterns || []
          unless patterns.empty?
            return true unless patterns.any? {|pattern| pattern =~ base}
          end

          excludes = @excludes || []
          unless excludes.empty?
            return true if excludes.any? {|pattern| pattern =~ base}
          end

          false
        end

        def add_require_failed_test_suite(test_suites)
          return if @require_failed_infos.empty?

          require_failed_infos = @require_failed_infos
          require_failed_omissions = Class.new(Test::Unit::TestCase)
          require_failed_omissions.class_eval do
            class << self
              def name
                "RequireFailedOmissions"
              end
            end

            require_failed_infos.each do |info|
              path = info[:path]
              normalized_path = path.to_s.gsub(/[^a-z0-9\_]+/i, '_')
              normalized_path = normalized_path.gsub(/\A_+/, '')
              exception = info[:exception]
              define_method("test_require_#{normalized_path}") do
                @require_failed_exception = exception
                omit("failed to load: <#{path}>: <#{exception.message}>")
              end
            end

            def priority
              100
            end

            def filter_backtrace(location)
              super(@require_failed_exception.backtrace)
            end
          end

          add_suite(test_suites, require_failed_omissions.suite)
        end
      end
    end
  end
end
