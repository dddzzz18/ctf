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
AC_CHECK_LIB(elf, gelf_getshdr)
AC_CHECK_LIB(dwarf, dwarf_elf_init, [
  AC_MSG_RESULT([you got dwarves])
],[
  AC_ERROR([Need libdwarf for ctfconvert to operate])
])

AC_CHECK_LIB(pthread, pthread_create)

AC_CHECK_HEADERS([ \
ctype.h \
dwarf.h \
errno.h \
fcntl.h \
gelf.h \
libdwarf.h \
libelf.h \
libgen.h \
limits.h \
pthread.h \
stdint.h \
string.h \
strings.h \
sys/elf.h \
sys/errno.h \
sys/mman.h \
sys/stat.h \
sys/sysmacros.h \
unistd.h \
zlib.h \
])

AC_CONFIG_HEADERS(pctf_config.h)
AC_CONFIG_FILES(Makefile)
AC_OUTPUT

