lib_LTLIBRARIES = libzepast.la libsum.la libmean.la libvariance.la libabsdev.la

libzepast_la_SOURCES = zepast.c stats.c stat.c
libzepast_la_LIBADD = -lm

libsum_la_SOURCES = sum.c
libsum_la_LIBADD = -lzepast -lm

libmean_la_SOURCES = mean.c
libmean_la_LIBADD = libsum.la -lzepast -lm

libvariance_la_SOURCES = variance.c
libvariance_la_LIBADD = -lzepast -lm

libabsdev_la_SOURCES = absdev.c
libabsdev_la_LIBADD = -lzepast -lm

include_HEADERS = zepast.h stats.h stat.h sum.h mean.h variance.h absdev.h

# variance/stddev
# absdev/MAD
bin_PROGRAMS = zepast stat-test sum mean variance absdev

zepast_SOURCES = main.c
zepast_LDADD = libzepast.la libmean.la libvariance.la libabsdev.la -lm

stat_test_SOURCES = stat-test.c
stat_test_LDADD = libzepast.la libmean.la libvariance.la libabsdev.la -lm

sum_SOURCES = sum-test.c
sum_LDADD = libzepast.la libsum.la -lm

mean_SOURCES = mean-test.c
mean_LDADD = libzepast.la libmean.la libsum.la -lm

variance_SOURCES = variance-test.c
variance_LDADD = libzepast.la libvariance.la libmean.la libsum.la -lm

absdev_SOURCES = absdev-test.c
# TODO libmedian.la
absdev_LDADD = libzepast.la libabsdev.la libmean.la libsum.la -lm

# trololol
#dist_doc_DATA += src/Makefile.am

AM_CPPFLAGS = -D__STDC_INT64__
