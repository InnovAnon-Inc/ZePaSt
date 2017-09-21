lib_LTLIBRARIES = libzepast.la
libzepast_la_SOURCES = zepast.c stats.c
include_HEADERS = zepast.h stats.h
libzepast_la_LIBADD = -lm -lthpool -lpthread

bin_PROGRAMS = zepast
zepast_SOURCES = main.c
zepast_LDADD = libzepast.la -lm -lthpool -lpthread

AM_CPPFLAGS = -D__STDC_INT64__
