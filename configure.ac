AC_INIT([libzepast], [1.0], [InnovAnon-Inc@protonmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AM_PROG_AR
LT_INIT([])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
 src/libabsdev.pc
 src/libivariance.pc
 src/libmean.pc
 src/libpstat.pc
 src/libpstat_mulvar.pc
 src/libpstat_ngram.pc
 src/libpstat_off.pc
 src/libstat.pc
 src/libstat_off.pc
 src/libstat_off_diff.pc
 src/libsum.pc
 src/libvariance.pc
 src/libzepast.pc
 src/absdev_test.pc
 src/ivariance_test.pc
 src/mean_test.pc
 src/stat_off_diff_test.pc
 src/sum_test.pc
 src/variance_test.pc
 src/zepast_test.pc
])

PKG_PROG_PKG_CONFIG

AC_ARG_ENABLE([use-submodules],
    AS_HELP_STRING([--enable-use-submodules], [Enable use submodules]))
AM_CONDITIONAL([USE_SUBMODULES], [test x"$enable_use_submodules" = "xyes"])

AC_CONFIG_MACRO_DIR([m4])

AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([pthread.h])
#AC_CHECK_HEADERS([glitter.h isqrt.h thpool.h])

#AC_CHECK_LIB([stdlib],[])
AC_CHECK_LIB([pthread],[pthread_create,pthread_join])
AC_CHECK_LIB([m],[fabs])
#AC_CHECK_LIB([isqrt],[isqrt_size_t])
#AC_CHECK_LIB([thpool],[thpool_init,thpool_add_work,thpool_wait,thpool_pause,thpool_resume,thpool_destroy,thpool_num_threads_working])

PKG_CHECK_MODULES([GLITTER],[glitter],,)
PKG_CHECK_MODULES([ISQRT],[libisqrt],,)

INNOVANON_WARNINGS([])

AC_OUTPUT

