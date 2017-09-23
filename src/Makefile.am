lib_LTLIBRARIES = libzepast.la libmean.la libvariance.la

libzepast_la_SOURCES = zepast.c stats.c stat.c
libzepast_la_LIBADD = -lm

libmean_la_SOURCES = mean.c
libmean_la_LIBADD = -lzepast -lm

libvariance_la_SOURCES = variance.c
libvariance_la_LIBADD = -lzepast -lm

include_HEADERS = zepast.h stats.h stat.h mean.h variance.h

bin_PROGRAMS = zepast stat-test mean-test

zepast_SOURCES = main.c
zepast_LDADD = libzepast.la libmean.la libvariance.la -lm

stat_test_SOURCES = stat-test.c
stat_test_LDADD = libzepast.la libmean.la libvariance.la -lm

mean_test_SOURCES = mean-test.c
mean_test_LDADD = libzepast.la libmean.la -lm

# trololol
#dist_doc_DATA += src/Makefile.am

AM_CPPFLAGS = -D__STDC_INT64__
