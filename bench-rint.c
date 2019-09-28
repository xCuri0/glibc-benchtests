#include <math.h>

#define CALL_BENCH_FUNC(v, i, x) rint (x variants[v].in[i].arg0)

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


struct args in0[4] = {
  {78.5, 0},
  {-78.5, 0},
  {4503599627370497.0, 0},
  {-4503599627370497.0, 0},
};


struct _variants variants[1] = {
  {"", 4, in0},
};

#define NUM_VARIANTS 1
#define NUM_SAMPLES(i) (variants[i].count)
#define VARIANT(i) (variants[i].name)

static double volatile ret;
static double zero __attribute__((used)) = 0;

#define RESULT(__v, __i) (variants[(__v)].in[(__i)].timing)
#define RESULT_ACCUM(r, v, i, old, new) \
        ((RESULT ((v), (i))) = (RESULT ((v), (i)) * (old) + (r)) / ((new) + 1))
#define BENCH_FUNC(i, j) ({ret = func_res =  CALL_BENCH_FUNC (i, j, );})
#define BENCH_FUNC_LAT(i, j) ({ret = func_res =  CALL_BENCH_FUNC (i, j, func_res * zero +);})
#define BENCH_VARS double func_res = 0;
#define FUNCNAME "rint"
#include "bench-skeleton.c"
