# vim:ts=2:sw=2:et:
AC_INIT(pctf,1.1,,pctf)
AM_INIT_AUTOMAKE([foreign])
AC_PROG_CC
AM_PROG_CC_C_O
AC_C_INLINE
AC_C_BIGENDIAN
AC_PROG_LIBTOOL

AC_CHECK_SIZEOF(void*)

AC_CHECK_TYPE(ulong_t, unsigned long)
AC_CHECK_TYPE(u_longlong_t, unsigned long long)
AC_CHECK_TYPE(ushort_t, unsigned short)
AC_CHECK_TYPE(uint_t, unsigned int)
AC_CHECK_TYPE(off64_t, off_t)
AC_CHECK_TYPE(uchar_t, unsigned char)

AC_CHECK_FUNCS([ \
getexecname \
getprogname \
])

AC_CHECK_LIB(z, uncompress)
AC_CHECK_LIB(elf, gelf_getshdr, [],[
  build_gelf=true
])
AM_CONDITIONAL([BUILD_ELF], [test "$build_gelf" = true])

AC_CHECK_LIB(dwarf, dwarf_elf_init, [], [
  build_dwarf=true
])
AM_CONDITIONAL([BUILD_DWARF], [test "$build_dwarf" = true])

AC_CHECK_LIB(pthread, pthread_create)

AC_CHECK_HEADERS([ \
ctype.h \
dwarf.h \
errno.h \
fcntl.h \
gelf.h \
libdwarf.h \
libgen.h \
limits.h \
pthread.h \
stdint.h \
string.h \
strings.h \
sys/cdefs.h \
sys/errno.h \
sys/mman.h \
sys/param.h \
sys/stat.h \
unistd.h \
zlib.h \
])

AC_CONFIG_HEADERS(pctf/pctf_config.h)
AC_CONFIG_FILES(Makefile)
AC_OUTPUT

