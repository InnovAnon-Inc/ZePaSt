#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

#define NDEBUG 1

#ifndef NDEBUG
#include <stdio.h>
#endif

#include <pstat.h>

/*
stat_off_update (val1, val2):
	val = diff (val1, val2);
	stat_update (val);

stat_ngram_update (vals[], nval):
	ngram = combine (vals, nval)
	pstat_update (&ngram)

stat_mulvar_update (vals[], nval):
	ngram = combine (vals, nval)
	pstat_update (&ngram)
*/

__attribute__ ((leaf, nonnull (1), nothrow))
void init_pstat (pstat_t *restrict s) {
   s->init (s->stat);
}

__attribute__ ((leaf, nonnull (1), nothrow))
void update_pstat (pstat_t *restrict s, unigram_t const vals[]) {
   s->update (s->stat, vals);
}

__attribute__ ((leaf, nonnull (1), nothrow))
void finish_pstat (pstat_t *restrict s) {
   s->finish (s->stat);
}

__attribute__ ((nonnull (1, 2), nothrow))
void ez_pstat_offset (
   pstat_t *restrict s,
   unigram_t const vals[], size_t nval, size_t offset) {
   size_t vi;
   init_pstat (s);
   /* offset must evenly divide nval */
   for (vi = 0; vi != nval - offset; vi++) {
      unigram_t p[2];
#ifndef NDEBUG
      printf ("vals[%d]:%d %c\n", (int) vi, (int) (vals[vi]), (char) (vals[vi])); fflush (stdout);
      printf ("vals[%d]:%d %c\n", (int) (vi + offset), (int) (vals[vi + offset]), (char) (vals[vi + offset])); fflush (stdout);
#endif
      p[0] = vals[vi];
      p[1] = vals[vi + offset];
      update_pstat (s, p);
      /*stat_off_update (vals[vi], vals[vi + offset]);*/
      /*update_stat (s, vals[vi]);*/
   }
   /* otherwise */
   /*for ( ;      vi != nval;          vi++)
      update_stat (s, vals[vi]);*/
   finish_pstat (s);
}

__attribute__ ((nonnull (1, 2), nothrow))
void ez_pstat_ngram (
   pstat_t *restrict s,
   unigram_t const vals[], size_t nval, size_t n) {
   size_t vi, vj;
   init_pstat (s);
   /* n must evenly divide nval */
   for (vi = 0; vi != nval - n; vi += n) {
      update_pstat (s, vals + vi);
      /*stat_ngram_update (vals + vi, n);*/
      /*for (vj = 0; vj != n; vj++)
         update_stat (s, vals[vi + vj]);*/
   }
   /* otherwise */
   /*for ( ;      vi != nval;     vi++)
      update_stat (s, vals[vi]);*/
   finish_pstat (s);
}

__attribute__ ((nonnull (1, 2, 4), nothrow))
void ez_pstat_mulvar (
   pstat_t *restrict s,
   unigram_t const *restrict vals[], size_t nval,
   unigram_t vars[], size_t nvar) {
   size_t vali, vari;
   TODO (e.g., cache-aware loop-blocking)
   TODO (if nval is really big... i.e., vals[*][vali])
   TODO (then it will be slow to load the models vals)
   init_pstat (s);
   for (vali = 0; vali != nval; vali++)
      for (vari = 0; vari != nvar; vari++) {
         vars[i] = vals[vari][vali];
         pstat_update (s, vars);
         /*stat_update (s, vals[0][vali]);*/
      }
   finish_pstat (s);
}
