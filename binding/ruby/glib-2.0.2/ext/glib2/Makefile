
SHELL = /bin/sh

# V=0 quiet, V=1 verbose.  other values don't work.
V = 0
Q1 = $(V:1=)
Q = $(Q1:0=@)
n=$(NULLCMD)
ECHO1 = $(V:1=@$n)
ECHO = $(ECHO1:0=@echo)

#### Start of system configuration section. ####

srcdir = /home/kenji/wc/milter-manager/binding/ruby/glib-2.0.2/ext/glib2
topdir = /usr/include/ruby-1.9.1
hdrdir = /usr/include/ruby-1.9.1
arch_hdrdir = /usr/include/ruby-1.9.1/$(arch)
VPATH = $(srcdir):$(arch_hdrdir)/ruby:$(hdrdir)/ruby
prefix = $(DESTDIR)/usr
rubylibprefix = $(libdir)/$(RUBY_BASE_NAME)
exec_prefix = $(prefix)
vendorhdrdir = $(rubyhdrdir)/vendor_ruby
sitehdrdir = $(rubyhdrdir)/site_ruby
rubyhdrdir = $(includedir)/$(RUBY_BASE_NAME)-$(ruby_version)
vendordir = $(DESTDIR)/usr/lib/ruby/vendor_ruby
sitedir = $(DESTDIR)/usr/local/lib/site_ruby
ridir = $(datarootdir)/$(RI_BASE_NAME)
mandir = $(prefix)/share/man
localedir = $(datarootdir)/locale
libdir = $(exec_prefix)/lib
psdir = $(docdir)
pdfdir = $(docdir)
dvidir = $(docdir)
htmldir = $(docdir)
infodir = $(prefix)/share/info
docdir = $(datarootdir)/doc/$(PACKAGE)
oldincludedir = $(DESTDIR)/usr/include
includedir = $(prefix)/include
localstatedir = $(DESTDIR)/var
sharedstatedir = $(prefix)/com
sysconfdir = $(DESTDIR)/etc
datadir = $(datarootdir)
datarootdir = $(prefix)/share
libexecdir = $(prefix)/lib/ruby1.9.1
sbindir = $(exec_prefix)/sbin
bindir = $(exec_prefix)/bin
rubylibdir = $(rubylibprefix)/$(ruby_version)
archdir = $(rubylibdir)/$(arch)
sitelibdir = $(sitedir)/$(ruby_version)
sitearchdir = $(sitelibdir)/$(sitearch)
vendorlibdir = $(vendordir)/$(ruby_version)
vendorarchdir = $(vendorlibdir)/$(sitearch)

NULLCMD = :

CC = gcc
CXX = g++
LIBRUBY = $(LIBRUBY_SO)
LIBRUBY_A = lib$(RUBY_SO_NAME)-static.a
LIBRUBYARG_SHARED = -l$(RUBY_SO_NAME)
LIBRUBYARG_STATIC = -l$(RUBY_SO_NAME)-static
OUTFLAG = -o 
COUTFLAG = -o 

RUBY_EXTCONF_H = 
cflags   =  $(optflags) $(debugflags) $(warnflags)
optflags = -O3
debugflags = -ggdb
warnflags = -Wextra -Wno-unused-parameter -Wno-parentheses -Wno-long-long -Wno-missing-field-initializers -Wpointer-arith -Wwrite-strings -Wdeclaration-after-statement -Wimplicit-function-declaration
CFLAGS   = -fPIC -g -O2 -fstack-protector --param=ssp-buffer-size=4 -Wformat -Werror=format-security -Wall -fno-strict-aliasing -fPIC -Wall -Waggregate-return -Wcast-align -Wextra -Wformat=2 -Winit-self -Wlarger-than-65500 -Wmissing-declarations -Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn -Wmissing-prototypes -Wnested-externs -Wold-style-definition -Wpacked -Wp,-D_FORTIFY_SOURCE=2 -Wpointer-arith -Wswitch-default -Wswitch-enum -Wundef -Wunsafe-loop-optimizations -Wwrite-strings -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -pthread -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include $(ARCH_FLAG)
INCFLAGS = -I. -I$(arch_hdrdir) -I$(hdrdir)/ruby/backward -I$(hdrdir) -I$(srcdir) -I$(sitearchdir) 
DEFS     = 
CPPFLAGS =  -DHAVE_RB_DEFINE_ALLOC_FUNC -DHAVE_RB_BLOCK_PROC -DHAVE_OBJECT_ALLOCATE -DHAVE_UNISTD_H -DHAVE_G_SPAWN_CLOSE_PID -DHAVE_G_THREAD_INIT -DHAVE_G_MAIN_DEPTH -DHAVE_G_LISTENV -DHAVE_RB_CHECK_ARRAY_TYPE -DHAVE_RB_CHECK_HASH_TYPE -DHAVE_RB_EXEC_RECURSIVE -DHAVE_RB_ERRINFO -DHAVE_RB_SOURCEFILE -DHAVE_RB_SOURCELINE -DHAVE_RB_THREAD_BLOCKING_REGION -DHAVE_RUBY_NATIVE_THREAD_P -DHAVE_RB_THREAD_CALL_WITH_GVL -DHAVE_RB_STR_NEW_CSTR -DHAVE_RB_GC_REGISTER_MARK_OBJECT -DRUBY_GLIB2_COMPILATION -D_FORTIFY_SOURCE=2 $(DEFS) $(cppflags)
CXXFLAGS = $(CFLAGS) -g -O2 -fstack-protector --param=ssp-buffer-size=4 -Wformat -Werror=format-security -Wall -fno-strict-aliasing
ldflags  = -L. -Wl,-z,relro -rdynamic -Wl,-export-dynamic -L/usr/lib/x86_64-linux-gnu -L/usr/lib/x86_64-linux-gnu -pthread
dldflags = 
ARCH_FLAG = 
DLDFLAGS = $(ldflags) $(dldflags) $(ARCH_FLAG)
LDSHARED = $(CC) -shared
LDSHAREDXX = $(CXX) -shared
AR = ar
EXEEXT = 

RUBY_BASE_NAME = ruby
RUBY_INSTALL_NAME = ruby1.9.1
RUBY_SO_NAME = ruby-1.9.1
arch = x86_64-linux
sitearch = $(arch)
ruby_version = 1.9.1
ruby = /usr/bin/ruby1.9.1
RUBY = $(ruby)
RM = rm -f
RM_RF = $(RUBY) -run -e rm -- -rf
RMDIRS = rmdir --ignore-fail-on-non-empty -p
MAKEDIRS = /bin/mkdir -p
INSTALL = /usr/bin/install -c
INSTALL_PROG = $(INSTALL) -m 0755
INSTALL_DATA = $(INSTALL) -m 644
COPY = cp

#### End of system configuration section. ####

preload = 

libpath = . $(libdir)
LIBPATH =  -L. -L$(libdir)
DEFFILE = 

CLEANFILES = mkmf.log
DISTCLEANFILES = ruby-glib2.pc glib-enum-types.h glib-enum-types.c
DISTCLEANDIRS = 

extout = 
extout_prefix = 
target_prefix = 
LOCAL_LIBS = 
LIBS = $(LIBRUBYARG_SHARED)  -lgobject-2.0 -lglib-2.0 -lgthread-2.0 -lglib-2.0 -lpthread -lrt -ldl -lcrypt -lm   -lc
SRCS = rbglib_convert.c rbgutil_callback.c rbgobj_closure.c rbgobj_flags.c rbgobj_boxed.c rbgobj_typeinstance.c rbglib_error.c rbgobj_typeinterface.c rbglib_fileutils.c rbglib_iochannel_win32_socket.c rbgobj_enums.c rbgutildeprecated.c rbgobj_convert.c rbglib_i18n.c rbglibdeprecated.c rbgobj_strv.c rbglib_iochannel.c rbgobj_signal.c rbglib_unichar.c rbgobj_enumflags.c rbglib_timer.c rbglib_mainloop.c rbgobj_type.c rbglib_messages.c rbglib_iochannelerror.c rbgobj_valuetypes.c rbglib_source.c rbgutil.c rbglib_spawn.c rbglib_spawnerror.c rbglib_int64.c rbgobj_object.c rbglib_win32.c rbglib_bookmarkfile.c rbgobj_valuearray.c rbglib_pollfd.c rbgobj_typeplugin.c rbgobj_paramspecs.c rbglib_keyfile.c rbglib_io_constants.c rbglib_utf8.c rbglib_ucs4.c rbglib_shell.c rbgutil_list.c rbglib_threads.c glib-enum-types.c rbglib_unicode.c rbglib.c rbgobject.c rbgobj_typemodule.c rbglib_shellerror.c rbglib_utils.c rbglib_maincontext.c rbglib_utf16.c rbgobj_param.c rbgobj_value.c
OBJS = rbglib_convert.o rbgutil_callback.o rbgobj_closure.o rbgobj_flags.o rbgobj_boxed.o rbgobj_typeinstance.o rbglib_error.o rbgobj_typeinterface.o rbglib_fileutils.o rbglib_iochannel_win32_socket.o rbgobj_enums.o rbgutildeprecated.o rbgobj_convert.o rbglib_i18n.o rbglibdeprecated.o rbgobj_strv.o rbglib_iochannel.o rbgobj_signal.o rbglib_unichar.o rbgobj_enumflags.o rbglib_timer.o rbglib_mainloop.o rbgobj_type.o rbglib_messages.o rbglib_iochannelerror.o rbgobj_valuetypes.o rbglib_source.o rbgutil.o rbglib_spawn.o rbglib_spawnerror.o rbglib_int64.o rbgobj_object.o rbglib_win32.o rbglib_bookmarkfile.o rbgobj_valuearray.o rbglib_pollfd.o rbgobj_typeplugin.o rbgobj_paramspecs.o rbglib_keyfile.o rbglib_io_constants.o rbglib_utf8.o rbglib_ucs4.o rbglib_shell.o rbgutil_list.o rbglib_threads.o glib-enum-types.o rbglib_unicode.o rbglib.o rbgobject.o rbgobj_typemodule.o rbglib_shellerror.o rbglib_utils.o rbglib_maincontext.o rbglib_utf16.o rbgobj_param.o rbgobj_value.o
TARGET = glib2
DLLIB = $(TARGET).so
EXTSTATIC = 
STATIC_LIB = 

BINDIR        = $(bindir)
RUBYCOMMONDIR = $(sitedir)$(target_prefix)
RUBYLIBDIR    = $(sitelibdir)$(target_prefix)
RUBYARCHDIR   = $(sitearchdir)$(target_prefix)
HDRDIR        = $(rubyhdrdir)/ruby$(target_prefix)
ARCHHDRDIR    = $(rubyhdrdir)/$(arch)/ruby$(target_prefix)

TARGET_SO     = $(DLLIB)
CLEANLIBS     = $(TARGET).so 
CLEANOBJS     = *.o  *.bak

all:    $(DLLIB)
static: $(STATIC_LIB)
.PHONY: all install static install-so install-rb
.PHONY: clean clean-so clean-rb

clean-rb-default::
clean-rb::
clean-so::
clean: clean-so clean-rb-default clean-rb
		@-$(RM) $(CLEANLIBS) $(CLEANOBJS) $(CLEANFILES)

distclean-rb-default::
distclean-rb::
distclean-so::
distclean: clean distclean-so distclean-rb-default distclean-rb
		@-$(RM) Makefile $(RUBY_EXTCONF_H) conftest.* mkmf.log
		@-$(RM) core ruby$(EXEEXT) *~ $(DISTCLEANFILES)
		@-$(RMDIRS) $(DISTCLEANDIRS) 2> /dev/null || true

realclean: distclean
install: install-so install-rb

install-so: $(RUBYARCHDIR)
install-so: $(RUBYARCHDIR)/$(DLLIB)
$(RUBYARCHDIR)/$(DLLIB): $(DLLIB)
	@-$(MAKEDIRS) $(@D)
	$(INSTALL_PROG) $(DLLIB) $(@D)
install-rb: pre-install-rb install-rb-default
install-rb-default: pre-install-rb-default
pre-install-rb: Makefile
pre-install-rb-default: Makefile
pre-install-rb-default:
	$(ECHO) installing default glib2 libraries
$(RUBYARCHDIR):
	$(Q) $(MAKEDIRS) $@

site-install: site-install-so site-install-rb
site-install-so: install-so
site-install-rb: install-rb

.SUFFIXES: .c .m .cc .mm .cxx .cpp .C .o

.cc.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $<

.mm.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $<

.cxx.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $<

.cpp.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $<

.C.o:
	$(ECHO) compiling $(<)
	$(Q) $(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) $(COUTFLAG)$@ -c $<

.c.o:
	$(ECHO) compiling $(<)
	$(Q) $(CC) $(INCFLAGS) $(CPPFLAGS) $(CFLAGS) $(COUTFLAG)$@ -c $<

.m.o:
	$(ECHO) compiling $(<)
	$(Q) $(CC) $(INCFLAGS) $(CPPFLAGS) $(CFLAGS) $(COUTFLAG)$@ -c $<

$(DLLIB): $(OBJS) Makefile
	$(ECHO) linking shared-object $(DLLIB)
	@-$(RM) $(@)
	$(Q) $(LDSHARED) -o $@ $(OBJS) $(LIBPATH) $(DLDFLAGS) $(LOCAL_LIBS) $(LIBS)



###
install-so: install-headers
install-headers:
	$(INSTALL_DATA) $(srcdir)/rbglib.h $(RUBYARCHDIR)
	$(INSTALL_DATA) $(srcdir)/rbglibdeprecated.h $(RUBYARCHDIR)
	$(INSTALL_DATA) $(srcdir)/rbglib2conversions.h $(RUBYARCHDIR)
	$(INSTALL_DATA) $(srcdir)/rbgutil.h $(RUBYARCHDIR)
	$(INSTALL_DATA) $(srcdir)/rbgutil_list.h $(RUBYARCHDIR)
	$(INSTALL_DATA) $(srcdir)/rbgutildeprecated.h $(RUBYARCHDIR)
	$(INSTALL_DATA) $(srcdir)/rbgobject.h $(RUBYARCHDIR)
	$(INSTALL_DATA) $(srcdir)/rbgcompat.h $(RUBYARCHDIR)
	$(INSTALL_DATA) glib-enum-types.h $(RUBYARCHDIR)

install: install-pc
install-pc:
	if test -n "$(pkgconfigdir)"; then			\
	  $(MAKEDIRS) $(pkgconfigdir);				\
	  $(INSTALL_DATA) ruby-glib2.pc $(pkgconfigdir);	\
	fi
