lib_LTLIBRARIES = libzepast.la libstats.la
libzepast_la_SOURCES = zepast.c
libzepast_la_LIBADD = -lm -lthpool -lpthread
libstats_la_SOURCES = mean.c
libstats_la_LIBADD = -lm -lthpool -lpthread

include_HEADERS = zepast.h mean.h

bin_PROGRAMS = zepast
zepast_SOURCES = main.c
zepast_LDADD = libzepast.la libstats.la -lm -lthpool -lpthread

AM_CPPFLAGS = -D__STDC_INT64__
