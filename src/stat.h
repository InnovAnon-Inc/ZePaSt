#ifndef _STAT_H_
#define _STAT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <sys/types.h>

#include <glitter.h>

typedef uint8_t unigram_t;

typedef __attribute__ ((nonnull (1)))
void (*init_stat_t) (
   void *restrict stat, size_t nval) ;

typedef __attribute__ ((nonnull (1)))
void (*update_stat_t) (
   void *restrict stat, unigram_t val, size_t nval) ;

/*typedef __attribute__ ((nonnull (1, 2)))
void (*updates_stat_t) (
   void *restrict stat, unigram_t val[], size_t nval) ;*/

typedef __attribute__ ((nonnull (1)))
void (*finish_stat_t) (
   void *restrict stat, size_t nval) ;

TODO (validate(stat_t*) functions)

typedef struct {
   init_stat_t    init;
   update_stat_t  update;
   /*updates_stat_t updates;*/
   finish_stat_t  finish;
   void *restrict stat;
} stat_t;

void init_stat (stat_t *restrict s, size_t nval)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

void update_stat (
   stat_t *restrict s,
   unigram_t val, size_t nval)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

/* stat_t->updates = updates_stat_naive
 * so updates_stat() wrapper can invoke it */
/*void updates_stat_naive (
   stat_t *restrict s,
   unigram_t val[], size_t nval)
__attribute__ ((leaf, nonnull (1, 2), nothrow)) ;*/

/*void updates_stat (
   stat_t *restrict s,
   unigram_t val[], size_t nval)
__attribute__ ((leaf, nonnull (1, 2), nothrow)) ;*/

void finish_stat (stat_t *restrict s, size_t nval)
__attribute__ ((leaf, nonnull (1), nothrow)) ;

void ez_stat (
   stat_t *restrict s,
   unigram_t vals, size_t nval)
__attribute__ ((nonnull (1), nothrow)) ;

#ifdef __cplusplus
}
#endif

#endif /* _STAT_H_ */