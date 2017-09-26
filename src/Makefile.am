lib_LTLIBRARIES =
include_HEADERS =
bin_PROGRAMS    =

include_HEADERS += stat-common.h

lib_LTLIBRARIES += libstat.la
libstat_la_SOURCES = stat.c
libstat_la_LIBADD = -lm
include_HEADERS += stat.h
#bin_PROGRAMS += stat-test

lib_LTLIBRARIES += libstat_off.la
libstat_off_la_SOURCES = stat_off.c
libstat_off_la_LIBADD = libstat.la -lm
include_HEADERS += stat_off.h
#bin_PROGRAMS += stat_off-test

lib_LTLIBRARIES += libstat_off_diff.la
libstat_off_diff_la_SOURCES = stat_off_diff.c
libstat_off_diff_la_LIBADD = libstat_off.la libstat.la -lm
include_HEADERS += stat_off_diff.h
bin_PROGRAMS += stat_off_diff-test
stat_off_diff_test_SOURCES = stat_off_diff-test.c
stat_off_diff_test_LDADD = libstat_off_diff.la libstat_off.la libstat.la libmean.la libsum.la libvariance.la -lm

# TODO libdstat (i.e., doubles as unigrams)
# TODO libdstat_ngram (i.e., able to represent RGB values and such)

# TODO libnstat (i.e., void * as unigram, size_t bytesz, use memcpy; see CAQ)

lib_LTLIBRARIES += libpstat.la
libpstat_la_SOURCES = pstat.c
libpstat_la_LIBADD = -lm
include_HEADERS += pstat.h
#bin_PROGRAMS += pstat-test

lib_LTLIBRARIES += libpstat_off.la
libpstat_off_la_SOURCES = pstat_off.c
libpstat_off_la_LIBADD = libpstat.la -lm
include_HEADERS += pstat_off.h
#bin_PROGRAMS += pstat_off-test

lib_LTLIBRARIES += libpstat_ngram.la
libpstat_ngram_la_SOURCES = pstat_ngram.c
libpstat_ngram_la_LIBADD = libpstat.la -lm
include_HEADERS += pstat_ngram.h
#bin_PROGRAMS += pstat_ngram-test

# TODO libpstat_ngram_off.la
# i.e., differences of ngramgs at different offsets

lib_LTLIBRARIES += libpstat_mulvar.la
libpstat_mulvar_la_SOURCES = pstat_mulvar.c
libpstat_mulvar_la_LIBADD = libpstat.la -lm
include_HEADERS += pstat_mulvar.h
#bin_PROGRAMS += pstat_mulvar-test

# TODO libpstat_mulvar_off.la
# i.e., multivariate analysis of differences of unigrams at different offsets

# TODO libpstat_mulvar_ngram.la
# i.e., multivariate analysis of ngrams

# TODO libpstat_mulvar_ngram_off.la
# i.e., multivariate analysis of differences of ngrams at different offsets

lib_LTLIBRARIES += libzepast.la
libzepast_la_SOURCES = zepast.c stats.c
libzepast_la_LIBADD = libstat.la libpstat.la -lm
include_HEADERS += zepast.h stats.h
bin_PROGRAMS += zepast
zepast_SOURCES = main.c
zepast_LDADD = libzepast.la libstat.la libmean.la libvariance.la libabsdev.la -lm

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
libivariance_la_LIBADD = libzepast.la libstat.la -lisqrt -lm
include_HEADERS += ivariance.h
bin_PROGRAMS += ivariance
ivariance_SOURCES = ivariance-test.c
ivariance_LDADD = libzepast.la libstat.la libivariance.la -lisqrt libsum.la -lm

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

#stat_test_SOURCES = stat-test.c
#stat_test_LDADD = libzepast.la libstat.la libmean.la libvariance.la libabsdev.la -lm

# trololol
#dist_doc_DATA += src/Makefile.am

AM_CPPFLAGS = -D__STDC_INT64__
