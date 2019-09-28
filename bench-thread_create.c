#include <pthread.h>
#include "thread_create-source.c"

#define CALL_BENCH_FUNC(v, i, x) thread_create (x variants[v].in[i].arg0, variants[v].in[i].arg1, variants[v].in[i].arg2)

struct args
{
  int volatile arg0;
  size_t volatile arg1;
  size_t volatile arg2;
  double timing;
};

struct _variants
{
  const char *name;
  int count;
  struct args *in;
};


struct args in0[1] = {
  {32, 1024, 1, 0},
};


struct args in1[1] = {
  {32, 1024, 2, 0},
};


struct args in2[1] = {
  {32, 2048, 1, 0},
};


struct args in3[1] = {
  {32, 2048, 2, 0},
};


struct _variants variants[4] = {
  {"stack=1024,guard=1", 1, in0},
  {"stack=1024,guard=2", 1, in1},
  {"stack=2048,guard=1", 1, in2},
  {"stack=2048,guard=2", 1, in3},
};

#define NUM_VARIANTS 4
#define NUM_SAMPLES(i) (variants[i].count)
#define VARIANT(i) (variants[i].name)

#define BENCH_INIT thread_create_init

#define RESULT(__v, __i) (variants[(__v)].in[(__i)].timing)
#define RESULT_ACCUM(r, v, i, old, new) \
        ((RESULT ((v), (i))) = (RESULT ((v), (i)) * (old) + (r)) / ((new) + 1))
#define BENCH_FUNC(i, j) ({ CALL_BENCH_FUNC (i, j, );})
#define BENCH_FUNC_LAT(i, j) ({ CALL_BENCH_FUNC (i, j, );})
#define BENCH_VARS 
#define FUNCNAME "thread_create"
#include "bench-skeleton.c"
