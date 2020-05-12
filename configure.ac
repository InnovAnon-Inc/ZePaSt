AC_INIT([libzepast], [0.0], [laurence.a.maddox@gmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AM_PROG_AR
LT_INIT([])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
])

AC_ARG_ENABLE([use-submodules],
    AS_HELP_STRING([--enable-use-submodules], [Enable use submodules]))
AM_CONDITIONAL([USE_SUBMODULES], [test x"$enable_use_submodules" = "xyes"])

AC_CONFIG_MACRO_DIR([m4])
#AC_CONFIG_SUBDIRS([glitter iSqrt])

AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([pthread.h])
AC_CHECK_HEADERS([glitter.h isqrt.h thpool.h])

#AC_CHECK_LIB([stdlib],[])
AC_CHECK_LIB([pthread],[pthread_create,pthread_join])
AC_CHECK_LIB([isqrt],[isqrt_size_t])
AC_CHECK_LIB([thpool],[thpool_init,thpool_add_work,thpool_wait,thpool_pause,thpool_resume,thpool_destroy,thpool_num_threads_working])

srcdir = @srcdir@
LIBPSTAT_LIBADD="`PATH=$(srcdir)src:$PATH libpstat_config --libs`"
AC_SUBST(LIBPSTAT_LIBADD)

#LIBPSTAT_OFF_LIBADD="libpstat.la `PATH=$(srcdir)src:$PATH libpstat_config --libs`"
LIBPSTAT_OFF_LIBADD="`PATH=$(srcdir)src:$PATH libpstat_config --libs`"
AC_SUBST(LIBPSTAT_OFF_LIBADD)

LIBSTAT_LIBADD="`PATH=$(srcdir)src:$PATH libstat_config --libs`"
AC_SUBST(LIBSTAT_LIBADD)

#LIBSTAT_OFF_LIBADD="libstat.la `PATH=src:$PATH libstat_off_config --libs`"
LIBSTAT_OFF_LIBADD="`PATH=$(srcdir)src:$PATH libstat_off_config --libs`"
AC_SUBST(LIBSTAT_OFF_LIBADD)

#LIBSTAT_OFF_DIFF_LIBADD="libstat_off.la `PATH=src:$PATH libstat_off_diff_config --libs`"
LIBSTAT_OFF_DIFF_LIBADD="`PATH=$(srcdir)src:$PATH libstat_off_diff_config --libs`"
AC_SUBST(LIBSTAT_OFF_DIFF_LIBADD)

#LIBSUM_LIBADD="libstat.la `PATH=src:$PATH libsum_config --libs`"
LIBSUM_LIBADD="`PATH=$(srcdir)src:$PATH libsum_config --libs`"
AC_SUBST(LIBSUM_LIBADD)

#LIBPSTAT_NGRAM_LIBADD="libpstat.la `PATH=src:$PATH libpstat_ngram_config --libs`"
LIBPSTAT_NGRAM_LIBADD="`PATH=$(srcdir)src:$PATH libpstat_ngram_config --libs`"
AC_SUBST(LIBPSTAT_NGRAM_LIBADD)

#LIBPSTAT_MULVAR_LIBADD="libpstat.la `PATH=src:$PATH libpstat_mulvar_config --libs`"
LIBPSTAT_MULVAR_LIBADD="`PATH=$(srcdir)src:$PATH libpstat_mulvar_config --libs`"
AC_SUBST(LIBPSTAT_MULVAR_LIBADD)

#LIBZEPAST_LIBADD="libstat.la libpstat.la `PATH=src:$PATH libzepast_config --libs`"
LIBZEPAST_LIBADD="`PATH=$(srcdir)src:$PATH libzepast_config --libs`"
AC_SUBST(LIBZEPAST_LIBADD)

#LIBMEAN_LIBADD="libsum.la `PATH=src:$PATH libmean_config --libs`"
LIBMEAN_LIBADD="`PATH=$(srcdir)src:$PATH libmean_config --libs`"
AC_SUBST(LIBMEAN_LIBADD)

#LIBVARIANCE_LIBADD="libstat.la `PATH=src:$PATH libvariance_config --libs`"
LIBVARIANCE_LIBADD="`PATH=$(srcdir)src:$PATH libvariance_config --libs`"
AC_SUBST(LIBVARIANCE_LIBADD)

#LIBABSDEV_LIBADD="libstat.la `PATH=src:$PATH libabsdev_config --libs`"
LIBABSDEV_LIBADD="`PATH=$(srcdir)src:$PATH libabsdev_config --libs`"
AC_SUBST(LIBABSDEV_LIBADD)

#LIBIVARIANCE_LIBADD="libstat.la `PATH=src:$PATH libivariance_config --libs`"
LIBIVARIANCE_LIBADD="`PATH=$(srcdir)src:$PATH libivariance_config --libs`"
AC_SUBST(LIBIVARIANCE_LIBADD)

STAT_OFF_DIFF_TEST_LIBADD="libstat_off_diff.la libmean.la libvariance.la `PATH=$(srcdir)src:$PATH stat_off_diff_test_config --libs`"
AC_SUBST(STAT_OFF_DIFF_TEST_LIBADD)

ZEPAST_TEST_LIBADD="libzepast.la libmean.la libvariance.la libabsdev.la `PATH=$(srcdir)src:$PATH zepast_test_config --libs`"
AC_SUBST(ZEPAST_TEST_LIBADD)

SUM_TEST_LIBADD="libsum.la `PATH=$(srcdir)src:$PATH sum_test_config --libs`"
AC_SUBST(SUM_TEST_LIBADD)

MEAN_TEST_LIBADD="libmean.la `PATH=$(srcdir)src:$PATH mean_test_config --libs`"
AC_SUBST(MEAN_TEST_LIBADD)

VARIANCE_TEST_LIBADD="libvariance.la libmean.la `PATH=$(srcdir)src:$PATH variance_test_config --libs`"
AC_SUBST(VARIANCE_TEST_LIBADD)

IVARIANCE_TEST_LIBADD="libivariance.la libmean.la `PATH=$(srcdir)src:$PATH ivariance_test_config --libs`"
AC_SUBST(IVARIANCE_TEST_LIBADD)

ABSDEV_TEST_LIBADD="libabsdev.la libmean.la `PATH=$(srcdir)src:$PATH absdev_test_config --libs`"
AC_SUBST(ABSDEV_TEST_LIBADD)



INNOVANON_WARNINGS([])

AC_OUTPUT
