#include <math.h>

#define CALL_BENCH_FUNC(v, i, x) modf (x variants[v].in[i].arg0,  &out1)

struct args
{
  double volatile arg0;
  double timing;
};

struct _variants
{
  const char *name;
  int count;
  struct args *in;
};


struct args in0[2] = {
  {42.0, 0},
  {-42.0, 0},
};


struct _variants variants[1] = {
  {"", 2, in0},
};

#define NUM_VARIANTS 1
#define NUM_SAMPLES(i) (variants[i].count)
#define VARIANT(i) (variants[i].name)

static double  out1 __attribute__((used));

#define RESULT(__v, __i) (variants[(__v)].in[(__i)].timing)
#define RESULT_ACCUM(r, v, i, old, new) \
        ((RESULT ((v), (i))) = (RESULT ((v), (i)) * (old) + (r)) / ((new) + 1))
#define BENCH_FUNC(i, j) ({ CALL_BENCH_FUNC (i, j, );})
#define BENCH_FUNC_LAT(i, j) ({ CALL_BENCH_FUNC (i, j, );})
#define BENCH_VARS 
#define FUNCNAME "modf"
#include "bench-skeleton.c"
