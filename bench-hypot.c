#include <math.h>

#define CALL_BENCH_FUNC(v, i, x) hypot (x variants[v].in[i].arg0, variants[v].in[i].arg1)

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


struct args in0[1] = {
  {0x3.ffffffffffffcp-1024, 0x8p-152, 0},
};


struct args in1[1] = {
  {0x1.000002027941dp+500,  0x1.0000000000001p+500, 0},
};


struct args in2[1] = {
  {0x0.fffffffffffffp-1022, 0x0.fffffffffffffp-1022, 0},
};


struct args in3[1] = {
  {0x1.fffffffffffffp-501,  0x1.fffffffffffffp-501, 0},
};


struct args in4[2] = {
  {3.0                   , 4.0, 0},
  {5.0                   , 4.0, 0},
};


struct _variants variants[5] = {
  {"overflow", 1, in0},
  {"higher_two500", 1, in1},
  {"subnormal", 1, in2},
  {"less_two500", 1, in3},
  {"default", 2, in4},
};

#define NUM_VARIANTS 5
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
#define FUNCNAME "hypot"
#include "bench-skeleton.c"
