lib_LTLIBRARIES = libzepast.la
libzepast_la_SOURCES = zepast.c
include_HEADERS = zepast.h
libzepast_la_LIBADD = -lthpool -lpthread

bin_PROGRAMS = zepast
zepast_SOURCES = main.c
zepast_LDADD = libzepast.la -lthpool -lpthread

AM_CPPFLAGS = -D__STDC_INT64__
