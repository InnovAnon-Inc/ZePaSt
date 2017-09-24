lib_LTLIBRARIES =
include_HEADERS =
bin_PROGRAMS    =

include_HEADERS += stat-common.h

lib_LTLIBRARIES += libstat.la
libstat_la_SOURCES = stat.c
libstat_la_LIBADD = -lm
include_HEADERS += stat.h
#bin_PROGRAMS += stat-test

lib_LTLIBRARIES += libpstat.la
libpstat_la_SOURCES = pstat.c
libpstat_la_LIBADD = -lm
include_HEADERS += pstat.h
#bin_PROGRAMS += pstat-test

lib_LTLIBRARIES += libzepast.la
libzepast_la_SOURCES = zepast.c stats.c
libzepast_la_LIBADD = libstat.la libpstat.la -lm
include_HEADERS += zepast.h stats.h
bin_PROGRAMS += zepast

lib_LTLIBRARIES += libisqrt.la
libisqrt_la_SOURCES = isqrt.c
libisqrt_la_LIBADD = -lm
include_HEADERS += isqrt.h
bin_PROGRAMS += isqrt
isqrt_SOURCES = isqrt-test.c
isqrt_LDADD = libisqrt.la -lm

lib_LTLIBRARIES += libsum.la
libsum_la_SOURCES = sum.c
libsum_la_LIBADD = libzepast.la libstat.la -lm
include_HEADERS += sum.h
bin_PROGRAMS += sum
sum_SOURCES = sum-test.c
sum_LDADD = libzepast.la libstat.la libsum.la -lm

lib_LTLIBRARIES += libmean.la
libmean_la_SOURCES = mean.c
libmean_la_LIBADD = libsum.la libzepast.la libstat.la -lm
include_HEADERS += mean.h
bin_PROGRAMS += mean
mean_SOURCES = mean-test.c
mean_LDADD = libzepast.la libmean.la libsum.la libstat.la -lm

lib_LTLIBRARIES += libvariance.la
libvariance_la_SOURCES = variance.c
libvariance_la_LIBADD = libzepast.la libstat.la -lm
include_HEADERS += variance.h
bin_PROGRAMS += variance
variance_SOURCES = variance-test.c
variance_LDADD = libzepast.la libstat.la libvariance.la libsum.la -lm

lib_LTLIBRARIES += libivariance.la
libivariance_la_SOURCES = ivariance.c
libivariance_la_LIBADD = libzepast.la libstat.la libisqrt.la -lm
include_HEADERS += ivariance.h
bin_PROGRAMS += ivariance
ivariance_SOURCES = ivariance-test.c
ivariance_LDADD = libzepast.la libstat.la libivariance.la libisqrt.la libsum.la -lm

lib_LTLIBRARIES += libabsdev.la
libabsdev_la_SOURCES = absdev.c
libabsdev_la_LIBADD = libzepast.la -lm
include_HEADERS += absdev.h
bin_PROGRAMS += absdev
absdev_SOURCES = absdev-test.c
# TODO libmedian.la
absdev_LDADD = libzepast.la libstat.la libabsdev.la libmean.la libsum.la -lm

# variance/stddev
# absdev/MAD

zepast_SOURCES = main.c
zepast_LDADD = libzepast.la libstat.la libmean.la libvariance.la libabsdev.la -lm

stat_test_SOURCES = stat-test.c
stat_test_LDADD = libzepast.la libstat.la libmean.la libvariance.la libabsdev.la -lm

# trololol
#dist_doc_DATA += src/Makefile.am

AM_CPPFLAGS = -D__STDC_INT64__
