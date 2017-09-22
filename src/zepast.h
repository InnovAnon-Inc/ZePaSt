#ifndef _ZEPAST_H_
#define _ZEPAST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#include <glitter.h>

typedef uint8_t unigram_t;

/* one statistical measurement */
/*typedef union {
   size_t n;
   double d;
} stat_t;*/

typedef __attribute__ ((nonnull (1)))
void (*init_stat_t) (
   void *restrict stats, size_t nval) ;

typedef __attribute__ ((nonnull (1)))
void (*update_stat_t) (
   void *restrict stats, unigram_t val, size_t nval) ;

typedef __attribute__ ((nonnull (1)))
void (*finish_stat_t) (
   void *restrict stats, size_t nval) ;

/* one cb to update some statistical measurements */
typedef struct {
   init_stat_t   init;
   update_stat_t update;
   finish_stat_t finish;
   void *restrict stats;
   /*size_t nstat;*/
   TODO (mask output)
} stats_t;

void stats (
   stats_t s[],      size_t nstats,
   unigram_t vals[], size_t nval)
__attribute__ ((leaf, nonnull (1, 3), nothrow)) ;

typedef struct {
   stats_t stats;
   void (*cb) ();
} stats_clj_t;

/* modular collections of stats */
typedef struct {
   stats_clj_t *restrict statss;
   size_t nstats;
   TODO (mask output)
} zepast_t;

void zepast (
   zepast_t z[],     size_t nzepast,
   unigram_t vals[], size_t nval)
__attribute__ ((leaf, nonnull (1, 3), nothrow)) ;

#ifdef __cplusplus
}
#endif

#endif /* _ZEPAST_H_ */