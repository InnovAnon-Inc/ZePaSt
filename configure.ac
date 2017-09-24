AC_INIT([libzepast], [0.0], [laurence.a.maddox@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AM_PROG_AR
LT_INIT([])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
])
AC_CONFIG_MACRO_DIR([m4])

AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([pthread.h])
AC_CHECK_HEADERS([glitter.h isqrt.h thpool.h])

#AC_CHECK_LIB([stdlib],[])
AC_CHECK_LIB([pthread],[pthread_create,pthread_join])
AC_CHECK_LIB([isqrt],[isqrt_size_t])
AC_CHECK_LIB([thpool],[thpool_init,thpool_add_work,thpool_wait,thpool_pause,thpool_resume,thpool_destroy,thpool_num_threads_working])

INNOVANON_WARNINGS([])

AC_OUTPUT
