AM_CPPFLAGS = -D__STDC_INT64__

lib_LTLIBRARIES =
include_HEADERS =
bin_PROGRAMS    =

include_HEADERS += stat-common.h

lib_LTLIBRARIES += libstat.la
libstat_la_CPPFLAGS = $(GLITTER_CFLAGS)
libstat_la_LIBADD   = $(GLITTER_LIBS)
include_HEADERS += stat.h

#Bin_PROGRAMS += stat-test

lib_LTLIBRARIES += libstat_off.la
libstat_off_la_CPPFLAGS =        $(GLITTER_CFLAGS)
libstat_off_la_LIBADD   = -lstat $(GLITTER_LIBS)
include_HEADERS += stat_off.h
EXTRA_libstat_off_la_DEPENDENCIES = libstat.la

#Bin_PROGRAMS += stat_off-test

lib_LTLIBRARIES += libstat_off_diff.la
libstat_off_diff_la_CPPFLAGS =                   $(GLITTER_CFLAGS)
libstat_off_diff_la_LIBADD   = -lstat_off -lstat $(GLITTER_LIBS)
EXTRA_libstat_off_diff_la_DEPENDENCIES = libstat_off.la
include_HEADERS += stat_off_diff.h

bin_PROGRAMS += stat_off_diff-test
stat_off_diff_test_CPPFLAGS =                                                     $(GLITTER_CFLAGS)
stat_off_diff_test_LDADD    = -lstat_off_diff -lstat_off -lstat -lmean -lvariance $(GLITTER_LIBS)
EXTRA_stat_off_diff_test_DEPENDENCIES = libstat_off_diff.la libmean.la libvariance.la

# TODO libdstat (i.e., doubles as unigrams)
# TODO libdstat_ngram (i.e., able to represent RGB values and such)

# TODO libnstat (i.e., void * as unigram, size_t bytesz, use memcpy; see CAQ)

lib_LTLIBRARIES += libpstat.la
libpstat_la_CPPFLAGS = $(GLITTER_CFLAGS)
libpstat_la_LIBADD   = $(GLITTER_LIBS)
include_HEADERS += pstat.h

#Bin_PROGRAMS += pstat-test

lib_LTLIBRARIES += libpstat_off.la
libpstat_off_la_CPPFLAGS =         $(GLITTER_CFLAGS)
libpstat_off_la_LIBADD   = -lpstat $(GLITTER_LIBS)
include_HEADERS += pstat_off.h
EXTRA_libpstat_off_la_DEPENDENCIES = libpstat.la

#Bin_PROGRAMS += pstat_off-test

lib_LTLIBRARIES += libpstat_ngram.la
libpstat_ngram_la_CPPFLAGS =         $(GLITTER_CFLAGS)
libpstat_ngram_la_LIBADD   = -lpstat $(GLITTER_LIBS)
include_HEADERS += pstat_ngram.h
EXTRA_libpstat_ngram_la_DEPENDENCIES = libpstat.la

#Bin_PROGRAMS += pstat_ngram-test

# TODO libpstat_ngram_off.la
# i.e., differences of ngramgs at different offsets

lib_LTLIBRARIES += libpstat_mulvar.la
libpstat_mulvar_la_CPPFLAGS =         $(GLITTER_CFLAGS)
libpstat_mulvar_la_LIBADD   = -lpstat $(GLITTER_LIBS)
include_HEADERS += pstat_mulvar.h
EXTRA_libpstat_mulvar_la_DEPENDENCIES = libpstat.la

#Bin_PROGRAMS += pstat_mulvar-test

# TODO libpstat_mulvar_off.la
# i.e., multivariate analysis of differences of unigrams at different offsets

# TODO libpstat_mulvar_ngram.la
# i.e., multivariate analysis of ngrams

# TODO libpstat_mulvar_ngram_off.la
# i.e., multivariate analysis of differences of ngrams at different offsets

lib_LTLIBRARIES += libzepast.la
libzepast_la_CPPFLAGS =        $(GLITTER_CFLAGS)
libzepast_la_LIBADD   = -lstat $(GLITTER_LIBS)
include_HEADERS += zepast.h stats.h
EXTRA_libzepast_la_DEPENDENCIES = libstat.la libpstat.la
#zepast_test_LDADD = libzepast.la $(LIBZEPAST_LIBADD) libmean.la $(LIBMEAN_LIBADD) libvariance.la $(LIBVARIANCE_LIBADD) libabsdev.la $(LIBABSDEV_LIBADD)

bin_PROGRAMS += zepast-test
zepast_test_CPPFLAGS =                                            $(GLITTER_CFLAGS)
zepast_test_LDADD    = -lzepast -lstat -lmean -lvariance -labsdev $(GLITTER_LIBS)
EXTRA_zepast_test_DEPENDENCIES = libzepast.la libmean.la libvariance.la libabsdev.la

lib_LTLIBRARIES += libsum.la
libsum_la_CPPFLAGS =        $(GLITTER_CFLAGS)
libsum_la_LIBADD   = -lstat $(GLITTER_LIBS)
EXTRA_libsum_la_DEPENDENCIES = libstat.la
include_HEADERS += sum.h

bin_PROGRAMS += sum-test
sum_test_CPPFLAGS =              $(GLITTER_CFLAGS)
sum_test_LDADD    = -lsum -lstat $(GLITTER_LIBS)
EXTRA_sum_test_DEPENDENCIES = libsum.la

lib_LTLIBRARIES += libmean.la
libmean_la_CPPFLAGS =              $(GLITTER_CFLAGS)
libmean_la_LIBADD   = -lsum -lstat $(GLITTER_LIBS)
EXTRA_libmean_la_DEPENDENCIES = libsum.la
include_HEADERS += mean.h

bin_PROGRAMS += mean-test
mean_test_CPPFLAGS =                     $(GLITTER_CFLAGS)
mean_test_LDADD    = -lmean -lsum -lstat $(GLITTER_LIBS)
EXTRA_mean_test_DEPENDENCIES = libmean.la

lib_LTLIBRARIES += libvariance.la
libvariance_la_CPPFLAGS =        $(GLITTER_CFLAGS)
libvariance_la_LIBADD   = -lstat $(GLITTER_LIBS)
EXTRA_libvariance_la_DEPENDENCIES = libstat.la
include_HEADERS += variance.h

bin_PROGRAMS += variance-test
variance_test_CPPFLAGS =                  $(GLITTER_CFLAGS)
variance_test_LDADD    = -lsum -lvariance $(GLITTER_LIBS)
EXTRA_variance_test_DEPENDENCIES = libvariance.la libmean.la

lib_LTLIBRARIES += libivariance.la
libivariance_la_CPPFLAGS =                $(GLITTER_CFLAGS)
libivariance_la_LIBADD   = -lisqrt -lstat $(GLITTER_LIBS)
EXTRA_libivariance_la_DEPENDENCIES = libstat.la
include_HEADERS += ivariance.h

bin_PROGRAMS += ivariance-test
ivariance_test_CPPFLAGS =                            $(GLITTER_CFLAGS)
ivariance_test_LDADD    = -livariance -lisqrt -lstat $(GLITTER_LIBS)
EXTRA_ivariance_test_DEPENDENCIES = libivariance.la libmean.la

lib_LTLIBRARIES += libabsdev.la
libabsdev_la_CPPFLAGS =        $(GLITTER_CFLAGS)
libabsdev_la_LIBADD   = -lstat $(GLITTER_LIBS)
EXTRA_libabsdev_la_DEPENDENCIES = libstat.la
include_HEADERS += absdev.h

bin_PROGRAMS += absdev-test
# TODO libmedian.la
absdev_test_CPPFLAGS =                       $(GLITTER_CFLAGS)
absdev_test_LDADD    = -labsdev -lmean -lsum $(GLITTER_LIBS)
EXTRA_absdev_test_DEPENDENCIES = libabsdev.la libmean.la

# variance/stddev
# absdev/MAD

#stat_test_SOURCES = stat-test.c
#stat_test_LDADD = libzepast.la libstat.la libmean.la libvariance.la libabsdev.la -lm

# trololol
#dist_doc_DATA += src/Makefile.am

