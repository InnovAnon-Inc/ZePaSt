#ifndef _STATS_H_
#define _STATS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <sys/types.h>

#include <glitter.h>

typedef uint8_t unigram_t;

typedef __attribute__ ((nonnull (1)))
void (*init_stat_t) (
   void *restrict stats, size_t nval) ;

typedef __attribute__ ((nonnull (1)))
void (*update_stat_t) (
   void *restrict stats, unigram_t val, size_t nval) ;

typedef __attribute__ ((nonnull (1)))
void (*finish_stat_t) (
   void *restrict stats, size_t nval) ;

typedef __attribute__ ((nonnull (1, 3)))
void (*all_stats_t) (
   stats_t s[], size_t nstats,
   unigram_t vals[], size_t nval) ;

typedef struct {
   init_stat_t   init;
   update_stat_t update;
   finish_stat_t finish;
   all_stats_t all_stats;
   void *restrict stats;
   /*size_t nstat; if size is dynamic */
   TODO (mask output)
} stats_t;

TODO (breakout to separate source file)

void stats (
   stats_t s[],      size_t nstats,
   unigram_t vals[], size_t nval)
__attribute__ ((leaf, nonnull (1, 3), nothrow)) ;

#ifdef __cplusplus
}
#endif

#endif /* _STATS_H_ */