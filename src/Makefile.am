lib_LTLIBRARIES =
include_HEADERS =
bin_PROGRAMS    =

lib_LTLIBRARIES += libzepast.la
libzepast_la_SOURCES = zepast.c stats.c stat.c isqrt.c
libzepast_la_LIBADD = -lm
include_HEADERS += zepast.h stats.h stat.h isqrt.h
bin_PROGRAMS += zepast stat-test

lib_LTLIBRARIES += libsum.la
libsum_la_SOURCES = sum.c
libsum_la_LIBADD = -lzepast -lm
include_HEADERS += sum.h
bin_PROGRAMS += sum
sum_SOURCES = sum-test.c
sum_LDADD = libzepast.la libsum.la -lm

lib_LTLIBRARIES += libmean.la
libmean_la_SOURCES = mean.c
libmean_la_LIBADD = libsum.la -lzepast -lm
include_HEADERS += mean.h
bin_PROGRAMS += mean
mean_SOURCES = mean-test.c
mean_LDADD = libzepast.la libmean.la libsum.la -lm

lib_LTLIBRARIES += libvariance.la
libvariance_la_SOURCES = variance.c
libvariance_la_LIBADD = -lzepast -lm
include_HEADERS += variance.h
bin_PROGRAMS += variance
variance_SOURCES = variance-test.c
variance_LDADD = libzepast.la libvariance.la libmean.la libsum.la -lm

lib_LTLIBRARIES += libivariance.la
libivariance_la_SOURCES = ivariance.c
libivariance_la_LIBADD = -lzepast -lm
include_HEADERS += ivariance.h
bin_PROGRAMS += ivariance
ivariance_SOURCES = ivariance-test.c
ivariance_LDADD = libzepast.la libivariance.la libmean.la libsum.la -lm

lib_LTLIBRARIES += libabsdev.la
libabsdev_la_SOURCES = absdev.c
libabsdev_la_LIBADD = -lzepast -lm
include_HEADERS += absdev.h
bin_PROGRAMS += absdev
absdev_SOURCES = absdev-test.c
# TODO libmedian.la
absdev_LDADD = libzepast.la libabsdev.la libmean.la libsum.la -lm

# variance/stddev
# absdev/MAD

zepast_SOURCES = main.c
zepast_LDADD = libzepast.la libmean.la libvariance.la libabsdev.la -lm

stat_test_SOURCES = stat-test.c
stat_test_LDADD = libzepast.la libmean.la libvariance.la libabsdev.la -lm

# trololol
#dist_doc_DATA += src/Makefile.am

AM_CPPFLAGS = -D__STDC_INT64__
