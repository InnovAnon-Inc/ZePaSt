#ifndef _ZEPAST_H_
#define _ZEPAST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#include <glitter.h>

typedef uint8_t unigram_t;

typedef __attribute__ ((nonnull (1)))
void (*init_stat_cb_t) (void *restrict stat) ;

typedef __attribute__ ((nonnull (1)))
void (*update_stat_cb_t) (void *restrict stat, unigram_t val) ;

typedef __attribute__ ((nonnull (1)))
void (*finish_stat_cb_t) (void *restrict stat) ;

typedef struct {
   init_stat_cb_t   init;
   update_stat_cb_t update;
   finish_stat_cb_t finish;
   void *restrict   res;
} stat_cbs_t;

void zepast (
   stat_cbs_t cbs[], size_t ncb,
   unigram_t vals[], size_t nval)
__attribute__ ((leaf, nonnull (1, 3), nothrow, warn_unused_result)) ;

#ifdef __cplusplus
}
#endif

#endif /* _ZEPAST_H_ */