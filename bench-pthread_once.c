#include <pthread.h>
#include "pthread_once-source.c"

#define CALL_BENCH_FUNC(v, i, x) pthread_once (x variants[v].in[i].arg0, variants[v].in[i].arg1)

struct args
{
  pthread_once_t * volatile arg0;
  void * volatile arg1;
  double timing;
};

struct _variants
{
  const char *name;
  int count;
  struct args *in;
};


struct args in0[1] = {
  {&once, once_handler, 0},
};


struct _variants variants[1] = {
  {"", 1, in0},
};

#define NUM_VARIANTS 1
#define NUM_SAMPLES(i) (variants[i].count)
#define VARIANT(i) (variants[i].name)


#define RESULT(__v, __i) (variants[(__v)].in[(__i)].timing)
#define RESULT_ACCUM(r, v, i, old, new) \
        ((RESULT ((v), (i))) = (RESULT ((v), (i)) * (old) + (r)) / ((new) + 1))
#define BENCH_FUNC(i, j) ({ CALL_BENCH_FUNC (i, j, );})
#define BENCH_FUNC_LAT(i, j) ({ CALL_BENCH_FUNC (i, j, );})
#define BENCH_VARS 
#define FUNCNAME "pthread_once"
#include "bench-skeleton.c"
