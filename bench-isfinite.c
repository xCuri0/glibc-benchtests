#include <math.h>

#define CALL_BENCH_FUNC(v, i, x) isfinite (x variants[v].in[i].arg0)

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


struct args in0[12] = {
  {0.9, 0},
  {2.3, 0},
  {3.7, 0},
  {3.9, 0},
  {4.0, 0},
  {4.7, 0},
  {5.9, 0},
  {0x1.000000cf4a2a1p0, 0},
  {0x1.0000010b239a8p0, 0},
  {0x1.00000162a932ap0, 0},
  {0x1.000002d452a11p0, 0},
  {0x1.000005bc7d86cp0, 0},
};


struct args in1[2] = {
  {__builtin_inf (), 0},
  {-__builtin_inf (), 0},
};


struct args in2[2] = {
  {__builtin_nan (""), 0},
  {__builtin_nans (""), 0},
};


struct _variants variants[3] = {
  {"", 12, in0},
  {"INF", 2, in1},
  {"NAN", 2, in2},
};

#define NUM_VARIANTS 3
#define NUM_SAMPLES(i) (variants[i].count)
#define VARIANT(i) (variants[i].name)

static int volatile ret;
static int zero __attribute__((used)) = 0;

#define RESULT(__v, __i) (variants[(__v)].in[(__i)].timing)
#define RESULT_ACCUM(r, v, i, old, new) \
        ((RESULT ((v), (i))) = (RESULT ((v), (i)) * (old) + (r)) / ((new) + 1))
#define BENCH_FUNC(i, j) ({ret = func_res =  CALL_BENCH_FUNC (i, j, );})
#define BENCH_FUNC_LAT(i, j) ({ret = func_res =  CALL_BENCH_FUNC (i, j, func_res * zero +);})
#define BENCH_VARS int func_res = 0;
#define FUNCNAME "isfinite"
#include "bench-skeleton.c"
