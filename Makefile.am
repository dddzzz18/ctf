AUTOMAKE_OPTIONS = subdir-objects
bin_PROGRAMS = ctfconvert ctfmerge ctfdump
CFLAGS += -I$(top_srcdir)
lib_LTLIBRARIES = libpctf.la
noinst_LTLIBRARIES = libpctfcommon.la libcvt.la
#noinst_PROGRAMS = ctfcompare
man1_MANS = man/ctfconvert.1 man/ctfmerge.1 man/ctfdump.1
nobase_include_HEADERS = pctf/libctf.h pctf/ctf_api.h pctf/ctf.h pctf/pctf_config.h

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
if BUILD_ELF
libpctf_la_SOURCES += \
	libelf/elf_begin.c libelf/elf_cntl.c libelf/elf_data.c libelf/elf_end.c \
	libelf/elf_errmsg.c libelf/elf_errno.c libelf/elf_fill.c \
	libelf/elf_flag.c libelf/elf_getarhdr.c libelf/elf_getarsym.c \
	libelf/elf_getbase.c libelf/elf_getident.c libelf/elf_hash.c \
	libelf/elf_kind.c libelf/elf_memory.c libelf/elf_next.c \
	libelf/elf_phnum.c libelf/elf_rand.c libelf/elf_rawfile.c \
	libelf/elf_scn.c libelf/elf_shnum.c libelf/elf_shstrndx.c \
	libelf/elf_strptr.c libelf/elf_update.c libelf/elf_version.c \
	libelf/gelf_cap.c libelf/gelf_checksum.c libelf/gelf_dyn.c \
	libelf/gelf_ehdr.c libelf/gelf_fsize.c libelf/gelf_getclass.c \
	libelf/gelf_move.c libelf/gelf_phdr.c libelf/gelf_rel.c \
	libelf/gelf_rela.c libelf/gelf_shdr.c libelf/gelf_sym.c \
	libelf/gelf_syminfo.c libelf/gelf_symshndx.c libelf/gelf_xlate.c \
	libelf/libelf.c libelf/libelf_align.c libelf/libelf_allocate.c \
	libelf/libelf_ar.c libelf/libelf_ar_util.c libelf/libelf_checksum.c \
	libelf/libelf_data.c libelf/libelf_ehdr.c libelf/libelf_extended.c \
	libelf/libelf_phdr.c libelf/libelf_shdr.c libelf/libelf_xlate.c \
	libelf/libelf_fsize.c libelf/libelf_msize.c libelf/libelf_convert.c

libelf/libelf_fsize.c: libelf/libelf_fsize.m4
	m4 libelf/libelf_fsize.m4 > libelf/libelf_fsize.c

libelf/libelf_msize.c: libelf/libelf_msize.m4
	m4 libelf/libelf_msize.m4 > libelf/libelf_msize.c

libelf/libelf_convert.c: libelf/libelf_convert.m4
	m4 libelf/libelf_convert.m4 > libelf/libelf_convert.c

endif

ctfdump_SOURCES = dump/dump.c
ctfdump_LDADD = libpctfcommon.la libpctf.la

libcvt_la_SOURCES = \
	cvt/alist.c \
	cvt/barrier.c \
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

if BUILD_DWARF
libcvt_la_SOURCES += \
	libdwarf/dwarf_abbrev.c \
	libdwarf/dwarf_attr.c \
	libdwarf/dwarf_attrval.c \
	libdwarf/dwarf_cu.c \
	libdwarf/dwarf_dealloc.c \
	libdwarf/dwarf_die.c \
	libdwarf/dwarf_dump.c \
	libdwarf/dwarf_errmsg.c \
	libdwarf/dwarf_errno.c \
	libdwarf/dwarf_finish.c \
	libdwarf/dwarf_form.c \
	libdwarf/dwarf_init.c \
	libdwarf/dwarf_loc.c
endif

ctfconvert_SOURCES = cvt/ctfconvert.c 
ctfconvert_LDADD = libcvt.la libpctfcommon.la libpctf.la

ctfmerge_SOURCES = cvt/ctfmerge.c 
ctfmerge_LDADD = libcvt.la libpctfcommon.la libpctf.la

#ctfcompare_SOURCES = cvt/compare.c 
#ctfcompare_LDADD = libcvt.la libpctfcommon.la libpctf.la


