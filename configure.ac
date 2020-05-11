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

LIBPSTAT_LIBADD="`PATH=src:$PATH libpstat_config --libs`"
AC_SUBST(LIBPSTAT_LIBADD)

LIBPSTAT_OFF_LIBADD="libpstat.la `PATH=src:$PATH libpstat_config --libs`"
AC_SUBST(LIBPSTAT_OFF_LIBADD)

LIBSTAT_LIBADD="`PATH=src:$PATH libstat_config --libs`"
AC_SUBST(LIBSTAT_LIBADD)

LIBSTAT_OFF_LIBADD="libstat.la `PATH=src:$PATH libstat_off_config --libs`"
AC_SUBST(LIBSTAT_OFF_LIBADD)

LIBSTAT_OFF_DIFF_LIBADD="libstat_off.la `PATH=src:$PATH libstat_off_diff_config --libs`"
AC_SUBST(LIBSTAT_OFF_DIFF_LIBADD)

LIBSUM_LIBADD="libstat.la `PATH=src:$PATH libsum_config --libs`"
AC_SUBST(LIBSUM_LIBADD)

LIBPSTAT_NGRAM_LIBADD="libpstat.la `PATH=src:$PATH libpstat_ngram_config --libs`"
AC_SUBST(LIBPSTAT_NGRAM_LIBADD)

LIBPSTAT_MULVAR_LIBADD="libpstat.la `PATH=src:$PATH libpstat_mulvar_config --libs`"
AC_SUBST(LIBPSTAT_MULVAR_LIBADD)

LIBZEPAST_LIBADD="libstat.la libpstat.la `PATH=src:$PATH libzepast_config --libs`"
AC_SUBST(LIBZEPAST_LIBADD)

LIBMEAN_LIBADD="libsum.la `PATH=src:$PATH libmean_config --libs`"
AC_SUBST(LIBMEAN_LIBADD)

LIBVARIANCE_LIBADD="libstat.la `PATH=src:$PATH libvariance_config --libs`"
AC_SUBST(LIBVARIANCE_LIBADD)

LIBABSDEV_LIBADD="libstat.la `PATH=src:$PATH libabsdev_config --libs`"
AC_SUBST(LIBABSDEV_LIBADD)

LIBIVARIANCE_LIBADD="libstat.la `PATH=src:$PATH libivariance_config --libs`"
AC_SUBST(LIBIVARIANCE_LIBADD)

INNOVANON_WARNINGS([])

AC_OUTPUT
