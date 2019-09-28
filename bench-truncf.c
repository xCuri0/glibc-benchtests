#include <math.h>

#define CALL_BENCH_FUNC(v, i, x) truncf (x variants[v].in[i].arg0)

struct args
{
  float volatile arg0;
  double timing;
};

struct _variants
{
  const char *name;
  int count;
  struct args *in;
};


struct args in0[18] = {
  {0.0f, 0},
  {-0.0f, 0},
  {0.001f, 0},
  {-0.001f, 0},
  {0.5f, 0},
  {-0.5f, 0},
  {0.999f, 0},
  {-0.999f, 0},
  {1.0f, 0},
  {-1.0f, 0},
  {1.001f, 0},
  {-1.001f, 0},
  {123.5f, 0},
  {-123.5f, 0},
  {12345.1f, 0},
  {-1000000.5f, 0},
  {1e15f, 0},
  {-1e30f, 0},
};


struct _variants variants[1] = {
  {"", 18, in0},
};

#define NUM_VARIANTS 1
#define NUM_SAMPLES(i) (variants[i].count)
#define VARIANT(i) (variants[i].name)

static float volatile ret;
static float zero __attribute__((used)) = 0;

#define RESULT(__v, __i) (variants[(__v)].in[(__i)].timing)
#define RESULT_ACCUM(r, v, i, old, new) \
        ((RESULT ((v), (i))) = (RESULT ((v), (i)) * (old) + (r)) / ((new) + 1))
#define BENCH_FUNC(i, j) ({ret = func_res =  CALL_BENCH_FUNC (i, j, );})
#define BENCH_FUNC_LAT(i, j) ({ret = func_res =  CALL_BENCH_FUNC (i, j, func_res * zero +);})
#define BENCH_VARS float func_res = 0;
#define FUNCNAME "truncf"
#include "bench-skeleton.c"
