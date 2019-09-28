#include <stdio.h>
#include "sprintf-source.c"

#define CALL_BENCH_FUNC(v, i, x) sprintf (x variants[v].in[i].arg0, variants[v].in[i].arg1, variants[v].in[i].arg2, variants[v].in[i].arg3, variants[v].in[i].arg4, variants[v].in[i].arg5, variants[v].in[i].arg6, variants[v].in[i].arg7, variants[v].in[i].arg8, variants[v].in[i].arg9, variants[v].in[i].arg10)

struct args
{
  char * volatile arg0;
  const char * volatile arg1;
  int volatile arg2;
  char volatile arg3;
  char volatile arg4;
  char volatile arg5;
  char volatile arg6;
  char volatile arg7;
  const char * volatile arg8;
  float volatile arg9;
  unsigned int volatile arg10;
  double timing;
};

struct _variants
{
  const char *name;
  int count;
  struct args *in;
};


struct args in0[1] = {
  {buf, FORMAT1, 1001, '1', '2', '3', '4', '5', "string", 1.5, 0x1234, 0},
};


struct args in1[1] = {
  {buf, FORMAT2, 1001, '1', '2', '3', '4', '5', "string", 1.5, 0x1234, 0},
};


struct _variants variants[2] = {
  {"positional", 1, in0},
  {"non-positional", 1, in1},
};

#define NUM_VARIANTS 2
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
#define FUNCNAME "sprintf"
#include "bench-skeleton.c"
