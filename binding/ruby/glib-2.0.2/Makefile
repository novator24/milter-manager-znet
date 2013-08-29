all:
	(cd ext/glib2 && $(MAKE))
	$(MAKE) -f Makefile.lib

install:
	(cd ext/glib2 && $(MAKE) RUBYARCHDIR=$(binding_extdir) RUBYLIBDIR=$(binding_libdir) libdir=$(libdir) install)
	$(MAKE) -f Makefile.lib RUBYARCHDIR=$(binding_extdir) RUBYLIBDIR=$(binding_libdir) libdir=$(libdir) install

site-install:
	(cd ext/glib2 && $(MAKE) site-install)
	$(MAKE) -f Makefile.lib site-install

clean:
	(cd ext/glib2 && $(MAKE) clean)
	$(MAKE) -f Makefile.lib clean

distclean:
	(cd ext/glib2 && $(MAKE) distclean)
	$(MAKE) -f Makefile.lib distclean
	@rm -f Makefile.lib

srcdir_prefix = 
exec_prefix = /tmp/local
libdir = $(DESTDIR)${exec_prefix}/lib
pkglibdir = $(libdir)/milter-manager
bindingdir = $(pkglibdir)/binding
binding_extdir = $(bindingdir)/ext
binding_libdir = $(bindingdir)/lib
RUBY = /usr/bin/ruby

check:
# 	$(RUBY) $(srcdir_prefix)test/run-test.rb

distdir:

dist:

uninstall:
