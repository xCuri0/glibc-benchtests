#include <math.h>

#define CALL_BENCH_FUNC(v, i, x) fmin (x variants[v].in[i].arg0, variants[v].in[i].arg1)

struct args
{
  double volatile arg0;
  double volatile arg1;
  double timing;
};

struct _variants
{
  const char *name;
  int count;
  struct args *in;
};


struct args in0[10] = {
  {78.5, -78.5, 0},
  {-78.5, 78.5, 0},
  {0,     78.5, 0},
  {78.5,  0, 0},
  {0,     -78.5, 0},
  {-78.5, 0, 0},
  {__builtin_inf (), 78.5, 0},
  {__builtin_inf (), -78.5, 0},
  {78.5, __builtin_inf (), 0},
  {-78.5, __builtin_inf (), 0},
};


struct args in1[4] = {
  {__builtin_nan (""), 78.5, 0},
  {__builtin_nan (""), -78.5, 0},
  {78.5, __builtin_nan (""), 0},
  {-78.5, __builtin_nan (""), 0},
};


struct args in2[4] = {
  {__builtin_nans (""), 78.5, 0},
  {__builtin_nans (""), -78.5, 0},
  {78.5, __builtin_nans (""), 0},
  {-78.5, __builtin_nans (""), 0},
};


struct _variants variants[3] = {
  {"", 10, in0},
  {"qNaN", 4, in1},
  {"sNaN", 4, in2},
};

#define NUM_VARIANTS 3
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
#define FUNCNAME "fmin"
#include "bench-skeleton.c"
