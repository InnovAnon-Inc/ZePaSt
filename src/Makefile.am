lib_LTLIBRARIES = libzepast.la libstats.la

libzepast_la_SOURCES = zepast.c stats.c stat.c
libzepast_la_LIBADD = -lm -lthpool -lpthread

libstats_la_SOURCES = mean.c variance.c
libstats_la_LIBADD = -lm -lthpool -lpthread

include_HEADERS = zepast.h stats.h stat.h mean.h variance.h

bin_PROGRAMS = zepast stat-test mean-test

zepast_SOURCES = main.c
zepast_LDADD = libzepast.la libstats.la -lm -lthpool -lpthread

stat_test_SOURCES = stat-test.c
stat_test_LDADD = libzepast.la libstats.la -lm -lthpool -lpthread

mean_test_SOURCES = mean-test.c
mean_test_LDADD = libzepast.la libstats.la -lm -lthpool -lpthread

AM_CPPFLAGS = -D__STDC_INT64__
