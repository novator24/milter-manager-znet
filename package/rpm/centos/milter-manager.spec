%if 0%{?centos} >= 6
%define ruby_command ruby1.9
%define ruby_package ruby1.9
%define ruby_build_requires ruby1.9
%else
%define ruby_command ruby
%define ruby_package ruby
%define ruby_build_requires ruby ruby-devel
%endif

%define ruby_version %(%{ruby_command} -e "print RUBY_VERSION.tr('.', '')")
%define ruby_libdir %(%{ruby_command} -rrbconfig -e 'print Config::CONFIG["rubylibdir"]')

Summary: A milter to use milters effectively
Name: milter-manager
Version: 2.0.0
Release: 0%{?dist}
License: GPLv3+, LGPL3+, AGPL3+, GFDL, Public Domain
URL: http://milter-manager.sourceforge.net/
Group: System Environment/Daemons
Source: http://downloads.sourceforge.net/milter-manager/milter-manager-2.0.0.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-%(%{__id_u} -n)
BuildRequires: intltool
BuildRequires: gettext
BuildRequires: gcc
BuildRequires: make
BuildRequires: glib2-devel
BuildRequires: %{ruby_build_requires}
Requires: ruby-milter-client = %{version}-%{release}
Requires: ruby-milter-server = %{version}-%{release}
Requires(pre): /usr/bin/getent, /usr/sbin/useradd
Requires(pre): /usr/bin/id, /usr/sbin/groupadd
Requires(post): /sbin/chkconfig
Requires(preun): /sbin/service, /sbin/chkconfig
Requires(postun): /sbin/service, /sbin/chkconfig, /usr/sbin/userdel

%description
milter manager administrates milters instead of MTA to reduce milter
administration cost and combine milters flexibly.

%package -n libmilter-core
Summary: A common library for milter protocol libraries
Group: System Environment/Libraries
Obsoletes: libmilter-toolkit < 1.6.6-0
Requires: glib2

%description -n libmilter-core
Common libraries for both of client-side and server-side milter protocol
libraries.
This package contains the library files required for libmilter-client
and libmilter-server.

%package -n libmilter-core-devel
Summary: Development files for libmilter-core
Group: Development/Libraries
Obsoletes: libmilter-toolkit-devel < 1.6.6-0
Requires: glib2-devel
Requires: libmilter-core = %{version}-%{release}

%description -n libmilter-core-devel
This package contains the headers, and other support files
required for developing applications against libmilter-core.

%package -n libmilter-client
Summary: A client-side milter protocol library
Group: System Environment/Libraries
Obsoletes: libmilter-toolkit < 1.6.6-0
Requires: libmilter-core = %{version}-%{release}

%description -n libmilter-client
Client-side milter protocol is implemented.
This package contains the library files required for running services
built using libmilter-client.

%package -n libmilter-client-devel
Summary: Development files for libmilter-client
Group: Development/Libraries
Obsoletes: libmilter-toolkit-devel < 1.6.6-0
Requires: libmilter-core-devel = %{version}-%{release}
Requires: libmilter-client = %{version}-%{release}

%description -n libmilter-client-devel
This package contains the headers, and other support files
required for developing applications against libmilter-client.

%package -n libmilter-server
Summary: A server-side milter protocol library
Group: System Environment/Libraries
Obsoletes: libmilter-toolkit < 1.6.6-0
Requires: libmilter-server = %{version}-%{release}

%description -n libmilter-server
Server-side milter protocol is implemented.
This package contains the library files required for running services
built using libmilter-server.

%package -n libmilter-server-devel
Summary: Development files for libmilter-server
Group: Development/Libraries
Obsoletes: libmilter-toolkit-devel < 1.6.6-0
Requires: libmilter-core-devel = %{version}-%{release}
Requires: libmilter-server = %{version}-%{release}

%description -n libmilter-server-devel
This package contains the headers, and other support files
required for developing applications against libmilter-server.

%package -n ruby-milter-core
Summary: Ruby bindings for libmilter-core
Group: Development/Libraries
Obsoletes: ruby-milter-toolkit < 1.6.6-0
Requires: %{ruby_package}
Requires: libmilter-core = %{version}-%{release}

%description -n ruby-milter-core
This package contains the Ruby bindings for libmilter-core.

%package -n ruby-milter-client
Summary: Ruby bindings for libmilter-client
Group: Development/Libraries
Obsoletes: ruby-milter-toolkit < 1.6.6-0
Requires: %{ruby_package}
Requires: libmilter-client = %{version}-%{release}
Requires: ruby-milter-core = %{version}-%{release}

%description -n ruby-milter-client
This package contains the Ruby bindings for libmilter-client.

%package -n ruby-milter-server
Summary: Ruby bindings for libmilter-server
Group: Development/Libraries
Obsoletes: ruby-milter-toolkit < 1.6.6-0
Requires: %{ruby_package}
Requires: libmilter-server = %{version}-%{release}

%description -n ruby-milter-server
This package contains the Ruby bindings for libmilter-server.

%package -n libmilter-compatible
Summary: libmilter API and ABI compatible milter library
Group: System Environment/Libraries
Requires: libmilter-client = %{version}-%{release}
Requires: ruby-milter-core = %{version}-%{release}

%description -n libmilter-compatible
A libmilter API and ABI compatible library based on libmilter-toolkit.
This package contains the library files required for running services
built using Sendmail libmilter or libmilter-compatible.

%package -n libmilter-compatible-devel
Summary: Development files for libmilter-compatible
Group: Development/Libraries
Requires: libmilter-client-devel = %{version}-%{release}
Requires: libmilter-compatible = %{version}-%{release}

%description -n libmilter-compatible-devel
This package contains the headers, and other support files
required for developing applications against libmilter-compatible.

%package -n milter-manager-munin-plugins
Summary: Munin plugins for milter manager
Group: System Environment/Libraries
Requires: munin-node
Requires: milter-manager = %{version}-%{release}

%description -n milter-manager-munin-plugins
This package contains the munin plugins for munin-node.

%package -n milter-manager-log-analyzer
Summary: Analyze milter-manager's log.
Group: Applications/System
Requires: milter-manager = %{version}-%{release}
Requires: %{ruby_package}
Requires: rrdtool

%description -n milter-manager-log-analyzer
This provides a Ruby script to generate some graphs from
milter-manager's log.


%prep
%setup -q

%build
%configure								\
    --with-default-effective-user=milter-manager			\
    --with-default-effective-group=milter-manager			\
    --with-default-socket-group=milter-manager				\
    --with-default-pid-file=/var/run/milter-manager/milter-manager.pid	\
    --with-default-connection-spec=unix:/var/run/milter-manager/milter-manager.sock \
    --with-ruby=/usr/bin/%{ruby_command}			\
    --with-bundled-ruby-glib2						\
    --enable-ruby-milter=%{ruby_libdir}

make %{?_smp_mflags}

%install
rm -rf %{buildroot}
make install DESTDIR=%{buildroot}

chmod 600 %{buildroot}%{_sysconfdir}/cron.d/milter-manager-log

mkdir -p %{buildroot}%{_localstatedir}/run/milter-manager/

mkdir -p %{buildroot}%{_sysconfdir}/httpd/conf.d/
cat <<EOC > %{buildroot}%{_sysconfdir}/httpd/conf.d/milter-manager-log.conf
Alias /milter-manager-log/ /var/lib/milter-manager/public_html/log/
EOC

mv %{buildroot}%{_datadir}/milter-manager/munin/ %{buildroot}%{_datadir}/
mkdir -p %{buildroot}%{_sysconfdir}/munin/plugin-conf.d/
cat <<EOC > %{buildroot}%{_sysconfdir}/munin/plugin-conf.d/milter-manager
[milter_manager_*]
  user milter-manager
  env.logdir /var/lib/milter-manager/public_html/log
EOC

%clean
rm -rf %{buildroot}

%pre
if ! /usr/bin/getent group milter-manager &>/dev/null; then
    /usr/sbin/groupadd -r milter-manager || \
        %logmsg "Unexpected error adding group \"milter-manager\". Aborting installation."
fi
if ! /usr/bin/id milter-manager &>/dev/null; then
    /usr/sbin/useradd -r -s /sbin/nologin -c 'milter manager' \
	-d %{_localstatedir}/lib/milter-manager --create-home \
	-g milter-manager milter-manager || \
        %logmsg "Unexpected error adding user \"milter-manager\". Aborting installation."
fi

%post
/sbin/chkconfig --add milter-manager
/bin/mkdir -p /var/run/milter-manager
/bin/chown -R milter-manager:milter-manager /var/run/milter-manager

%post -n milter-manager-munin-plugins
/usr/sbin/munin-node-configure --shell --remove-also | \
    grep -e '\(milter_manager_\|\(postfix\|sendmail\)_processes\)' | \
    sh
[ -f /var/lock/subsys/munin-node ] && \
    /sbin/service munin-node restart > /dev/null 2>&1
:

%preun
if [ $1 -eq 0 ] ; then
    /sbin/service milter-manager stop > /dev/null 2>&1
    /sbin/chkconfig --del milter-manager
fi

%postun
if [ $1 -ge 1 ] ; then
    /sbin/service milter-manager condrestart > /dev/null 2>&1
fi

if [ $1 -eq 0 ]; then
    /usr/sbin/userdel -r milter-manager || \
	%logmsg "User \"milter-manager\" could not be deleted."
fi

%postun -n milter-manager-munin-plugins
if [ $1 -eq 0 ]; then
    rm %{_sysconfdir}/munin/plugins/milter_manager_* > /dev/null 2>&1
    rm %{_sysconfdir}/munin/plugins/postfix_processes > /dev/null 2>&1
    rm %{_sysconfdir}/munin/plugins/sendmail_processes > /dev/null 2>&1
    [ -f /var/lock/subsys/munin-node ] && \
	/sbin/service munin-node restart > /dev/null 2>&1
    :
fi

%files
%defattr(-, root, root, -)
%doc README README.ja NEWS NEWS.ja TODO
%doc %{_datadir}/milter-manager/license/
%doc %{_datadir}/gtk-doc/html/milter-manager/
%{_bindir}/milter-performance-check
%{_bindir}/milter-report-statistics
%{_sbindir}/milter-manager
%{_includedir}/milter-manager/milter/manager.h
%{_includedir}/milter-manager/milter/manager/
%{_libdir}/libmilter-manager.*
%{_libdir}/milter-manager/binding/ext/milter_manager.*
%{_libdir}/milter-manager/binding/lib/milter/manager.rb
%{_libdir}/milter-manager/binding/lib/milter/manager/
%{_libdir}/milter-manager/module/
%{_libdir}/pkgconfig/milter-manager.pc
%{_mandir}/man1/milter-performance-check.*
%{_mandir}/man1/milter-report-statistics.*
%{_mandir}/man1/milter-manager.*
%{_mandir}/ja/man1/milter-performance-check.*
%{_mandir}/ja/man1/milter-report-statistics.*
%{_mandir}/ja/man1/milter-manager.*
%{_initrddir}/milter-manager
%{_sysconfdir}/rc.d/init.d/
%config(noreplace) %{_sysconfdir}/sysconfig/milter-manager
%config(noreplace) %{_sysconfdir}/milter-manager/milter-manager.conf
%config %{_sysconfdir}/milter-manager/defaults/
%config %{_sysconfdir}/milter-manager/applicable-conditions/
%config %{_sysconfdir}/milter-manager/models/
%config(noreplace) %{_sysconfdir}/httpd/conf.d/milter-manager-log.conf

%defattr(-, milter-manager, milter-manager, 0755)
%dir %{_localstatedir}/run/milter-manager/

%files -n libmilter-core
%defattr(-,root,root)
%doc README README.ja NEWS NEWS.ja TODO
%doc %{_datadir}/milter-manager/license/
%{_libdir}/libmilter-core.so.*

%files -n libmilter-core-devel
%defattr(-,root,root)
%doc README README.ja NEWS NEWS.ja TODO
%doc %{_datadir}/milter-manager/license/
%doc %{_datadir}/gtk-doc/html/milter-manager/
%{_includedir}/milter-manager/milter/core.h
%{_includedir}/milter-manager/milter/core/
%{_libdir}/libmilter-core.so
%{_libdir}/libmilter-core.la
%{_libdir}/pkgconfig/milter-core.pc

%files -n libmilter-client
%defattr(-,root,root)
%doc README README.ja NEWS NEWS.ja TODO
%doc %{_datadir}/milter-manager/license/
%{_bindir}/milter-test-client
%{_libdir}/libmilter-client.so.*
%{_mandir}/man1/milter-test-client.*
%{_mandir}/ja/man1/milter-test-client.*

%files -n libmilter-client-devel
%defattr(-,root,root)
%doc README README.ja NEWS NEWS.ja TODO
%doc %{_datadir}/milter-manager/license/
%doc %{_datadir}/gtk-doc/html/milter-manager/
%{_includedir}/milter-manager/milter/client.h
%{_includedir}/milter-manager/milter/client/
%{_libdir}/libmilter-client.so
%{_libdir}/libmilter-client.la
%{_libdir}/pkgconfig/milter-client.pc

%files -n libmilter-server
%defattr(-,root,root)
%doc README README.ja NEWS NEWS.ja TODO
%doc %{_datadir}/milter-manager/license/
%{_bindir}/milter-test-server
%{_libdir}/libmilter-server.so.*
%{_mandir}/man1/milter-test-server.*
%{_mandir}/ja/man1/milter-test-server.*

%files -n libmilter-server-devel
%defattr(-,root,root)
%doc README README.ja NEWS NEWS.ja TODO
%doc %{_datadir}/milter-manager/license/
%doc %{_datadir}/gtk-doc/html/milter-manager/
%{_includedir}/milter-manager/milter/server.h
%{_includedir}/milter-manager/milter/server/
%{_libdir}/libmilter-server.so
%{_libdir}/libmilter-server.la
%{_libdir}/pkgconfig/milter-server.pc

%files -n ruby-milter-core
%defattr(-,root,root)
%doc README README.ja NEWS NEWS.ja TODO
%doc %{_datadir}/milter-manager/license/
%doc %{_datadir}/gtk-doc/html/milter-manager/
%{ruby_libdir}/milter/core.rb
%{_libdir}/milter-manager/binding/ext/glib2.so
%{_libdir}/milter-manager/binding/ext/rbg*.h
%{_libdir}/milter-manager/binding/ext/glib*.h
%{_libdir}/milter-manager/binding/ext/milter_core.so
%{_libdir}/milter-manager/binding/ext/milter_core.la
%{_libdir}/milter-manager/binding/ext/rb-milter-core.h
%{_libdir}/milter-manager/binding/lib/milter.rb
%{_libdir}/milter-manager/binding/lib/milter/core.rb
%{_libdir}/milter-manager/binding/lib/milter/core/
%{_libdir}/milter-manager/binding/lib/glib*.rb
%if %ruby_version > 185
%{_libdir}/milter-manager/binding/lib/glib2/*.rb
%endif
%if %ruby_version > 191
%{_libdir}/milter-manager/binding/lib/gnome2/rake/*.rb
%endif
%{_libdir}/milter-manager/binding/lib/*gnome2*.rb
%{_libdir}/milter-manager/binding/lib/pkg-config.rb
%{_libdir}/pkgconfig/ruby-milter-core.pc

%files -n ruby-milter-client
%defattr(-,root,root)
%doc README README.ja NEWS NEWS.ja TODO
%doc %{_datadir}/milter-manager/license/
%doc %{_datadir}/gtk-doc/html/milter-manager/
%{ruby_libdir}/milter.rb
%{ruby_libdir}/milter/client.rb
%{_libdir}/milter-manager/binding/ext/milter_client.so
%{_libdir}/milter-manager/binding/ext/milter_client.la
%{_libdir}/milter-manager/binding/ext/rb-milter-client.h
%{_libdir}/milter-manager/binding/lib/milter/client.rb
%{_libdir}/milter-manager/binding/lib/milter/client/
%{_datadir}/milter-manager/sample/ruby/*
%{_libdir}/pkgconfig/ruby-milter.pc
%{_libdir}/pkgconfig/ruby-milter-client.pc

%files -n ruby-milter-server
%defattr(-,root,root)
%doc README README.ja NEWS NEWS.ja TODO
%doc %{_datadir}/milter-manager/license/
%doc %{_datadir}/gtk-doc/html/milter-manager/
%{ruby_libdir}/milter/server.rb
%{_libdir}/milter-manager/binding/ext/milter_server.so
%{_libdir}/milter-manager/binding/ext/milter_server.la
%{_libdir}/milter-manager/binding/ext/rb-milter-server.h
%{_libdir}/milter-manager/binding/lib/milter/server.rb
%{_libdir}/milter-manager/binding/lib/milter/server/
%{_libdir}/pkgconfig/ruby-milter-server.pc

%files -n libmilter-compatible
%defattr(-,root,root)
%doc README README.ja NEWS NEWS.ja TODO
%doc %{_datadir}/milter-manager/license/
%{_bindir}/milter-test-client-libmilter
%{_libdir}/milter-manager/libmilter.so.*

%files -n libmilter-compatible-devel
%defattr(-,root,root)
%doc README README.ja NEWS NEWS.ja TODO
%doc %{_datadir}/milter-manager/license/
%doc %{_datadir}/gtk-doc/html/milter-manager/
%{_includedir}/milter-manager/libmilter/
%{_libdir}/milter-manager/libmilter.so
%{_libdir}/milter-manager/libmilter.la
%{_libdir}/pkgconfig/libmilter.pc

%files -n milter-manager-munin-plugins
%defattr(-,root,root)
%doc README README.ja NEWS NEWS.ja TODO
%doc %{_datadir}/milter-manager/license/
%{_datadir}/munin/
%config %{_sysconfdir}/munin/plugin-conf.d/

%files -n milter-manager-log-analyzer
%defattr(-,root,root)
%doc README README.ja NEWS NEWS.ja TODO
%doc %{_datadir}/milter-manager/license/
%{_bindir}/milter-manager-log-analyzer
%{_mandir}/man1/milter-manager-log-analyzer.*
%{_mandir}/ja/man1/milter-manager-log-analyzer.*
%{_sysconfdir}/cron.d/

%changelog
* Thu Jul 25 2013 Kenji Okimoto <okimoto@clear-code.com> - 2.0.0-1
- new upstream release.

* Fri Jun 28 2013 Kenji Okimoto <okimoto@clear-code.com> - 1.8.9-1
- new upstream release.

* Tue Jun 25 2013 Kenji Okimoto <okimoto@clear-code.com> - 1.8.8-0
- new upstream release.

* Fri Jun 14 2013 Kenji Okimoto <okimoto@clear-code.com> - 1.8.7-0
- new upstream release.

* Thu Mar 07 2013 HAYASHI Kentaro <hayashi@clear-code.com> - 1.8.6-0
- new upstream release.

* Mon Dec 03 2012 Kenji Okimoto <okimoto@clear-code.com> - 1.8.5-0
- new upstream release.

* Wed Nov 21 2012 Kenji Okimoto <okimoto@clear-code.com> - 1.8.4-0
- new upstream release.

* Tue May 22 2012 Kenji Okimoto <okimoto@clear-code.com> - 1.8.3-0
- new upstream release.

* Mon May 07 2012 Kouhei Sutou <kou@clear-code.com> - 1.8.2-1
- change the default socket group to milter-manager.

* Tue Nov 29 2011 Kenji Okimoto <okimoto@clear-code.com> - 1.8.2-0
- new upstream release.

* Sat Nov 12 2011 Kenji Okimoto <okimoto@clear-code.com> - 1.8.1-0
- new upstream release.

* Fri Jun 10 2011 Kouhei Sutou <kou@clear-code.com> - 1.8.0-0
- new upstream release.

* Tue Apr 26 2011 Kouhei Sutou <kou@clear-code.com> - 1.6.9-0
- new upstream release.

* Fri Apr 15 2011 Kouhei Sutou <kou@clear-code.com> - 1.6.8-0
- new upstream release.

* Fri Apr 08 2011 Kouhei Sutou <kou@clear-code.com> - 1.6.7-0
- new upstream release.

* Fri Apr 08 2011 Kouhei Sutou <kou@clear-code.com> - 1.6.6-2
- add missing dependencies.

* Fri Apr 08 2011 Kouhei Sutou <kou@clear-code.com> - 1.6.6-1
- fix init.d/ path.
- add Obsoletes.

* Wed Apr 06 2011 Kouhei Sutou <kou@clear-code.com> - 1.6.6-0
- new upstream release.
- split toolkit to core, client and server.

* Wed Jan 26 2011 Kouhei Sutou <kou@clear-code.com> - 1.6.5-0
- new upstream release.

* Fri Jan 21 2011 Kouhei Sutou <kou@clear-code.com> - 1.6.4-0
- new upstream release.

* Thu Jan 20 2011 Kouhei Sutou <kou@clear-code.com> - 1.6.3-0
- new upstream release.

* Tue Nov 23 2010 Kouhei Sutou <kou@clear-code.com>
- (1.6.2-0)
- new upstream release

* Sat Aug 21 2010 Kouhei Sutou <kou@clear-code.com>
- (1.6.1-0)
- new upstream release

* Wed Aug 11 2010 Kouhei Sutou <kou@clear-code.com>
- (1.6.0-0)
- new upstream release

* Tue Aug 03 2010 Kouhei Sutou <kou@clear-code.com>
- (1.5.3-1)
- new upstream release

* Sat May 29 2010 Kouhei Sutou <kou@clear-code.com>
- (1.5.2-2)
- new upstream release

* Wed Apr 20 2010 Kouhei Sutou <kou@clear-code.com>
- (1.5.1-2)
- new upstream release

* Mon Mar 29 2010 Kouhei Sutou <kou@clear-code.com>
- (1.5.0-16)
- new upstream release

* Thu Oct 29 2009 Kouhei Sutou <kou@clear-code.com>
- (1.4.1-0)
- new upstream release

* Thu Oct 13 2009 Kouhei Sutou <kou@clear-code.com>
- (1.4.0-0)
- new upstream release

* Wed Sep 16 2009 Kouhei Sutou <kou@clear-code.com>
- (1.3.1-0)
- new upstream release

* Wed Aug 12 2009 Kouhei Sutou <kou@clear-code.com>
- (1.3.0-0)
- new upstream release

* Fri Jul 17 2009 Kouhei Sutou <kou@clear-code.com>
- (1.2.0-0)
- new upstream release

* Fri Jul 03 2009 Kouhei Sutou <kou@clear-code.com>
- (1.1.1-0)
- new upstream release

* Tue Jun 02 2009 Kouhei Sutou <kou@clear-code.com>
- (1.1.0-0)
- initial 1.1.x development seriese release

* Thu Apr 16 2009 Kouhei Sutou <kou@clear-code.com>
- (1.0.0-1)
- initial stable release
