AUTOMAKE_OPTIONS = subdir-objects
bin_PROGRAMS = ctfconvert ctfmerge ctfdump
CFLAGS += -I$(top_srcdir)
lib_LTLIBRARIES = libpctf.la
noinst_LTLIBRARIES = libpctfcommon.la libcvt.la
man1_MANS = man/ctfconvert.1 man/ctfmerge.1 man/ctfdump.1
include_HEADERS = pctf/libctf.h pctf/ctf_api.h pctf/ctf.h

libpctfcommon_la_SOURCES = \
	common/list.c \
	common/memory.c \
	common/symbol.c \
	common/utils.c

libpctf_la_SOURCES = \
	libctf/ctf_create.c \
	libctf/ctf_decl.c \
	libctf/ctf_error.c \
	libctf/ctf_hash.c \
	libctf/ctf_labels.c \
	libctf/ctf_lib.c \
	libctf/ctf_lookup.c \
	libctf/ctf_open.c \
	libctf/ctf_subr.c \
	libctf/ctf_types.c \
	libctf/ctf_util.c

ctfdump_SOURCES = dump/dump.c
ctfdump_LDADD = libpctfcommon.la

libcvt_la_SOURCES = \
	cvt/alist.c \
	cvt/barrier.c \
	cvt/compare.c \
	cvt/ctf.c \
	cvt/dwarf.c \
	cvt/fifo.c \
	cvt/fixup_tdescs.c \
	cvt/hash.c \
	cvt/iidesc.c \
	cvt/input.c \
	cvt/merge.c \
	cvt/output.c \
	cvt/st_parse.c \
	cvt/stabs.c \
	cvt/stack.c \
	cvt/strtab.c \
	cvt/tdata.c \
	cvt/traverse.c \
	cvt/util.c 

ctfconvert_SOURCES = cvt/ctfconvert.c 
ctfconvert_LDADD = libcvt.la libpctfcommon.la libpctf.la -ldwarf

ctfmerge_SOURCES = cvt/ctfmerge.c 
ctfmerge_LDADD = libcvt.la libpctfcommon.la libpctf.la


