#include <strings.h>

#define CALL_BENCH_FUNC(v, i, x) ffs (x variants[v].in[i].arg0)

struct args
{
  int volatile arg0;
  double timing;
};

struct _variants
{
  const char *name;
  int count;
  struct args *in;
};


struct args in0[100] = {
  {0x33ed4, 0},
  {0x2b, 0},
  {0xba3f6965, 0},
  {0x4, 0},
  {0x927e0ceb, 0},
  {0x7, 0},
  {0x0, 0},
  {0x3418b, 0},
  {0x318c, 0},
  {0x19a7402, 0},
  {0x699d4586, 0},
  {0x392e4, 0},
  {0x66, 0},
  {0x7fc86, 0},
  {0x13d, 0},
  {0x2aa7a61, 0},
  {0x29d, 0},
  {0x1d729b2, 0},
  {0x13a, 0},
  {0x7, 0},
  {0x11b958, 0},
  {0x3a6a23, 0},
  {0x1b0d749, 0},
  {0x1f12ecb, 0},
  {0x21, 0},
  {0x285a, 0},
  {0x24702, 0},
  {0x88799, 0},
  {0x10b, 0},
  {0x5, 0},
  {0x572739, 0},
  {0x12f0, 0},
  {0xa36c89, 0},
  {0x1, 0},
  {0x1f58, 0},
  {0x33743ce8, 0},
  {0xbefe, 0},
  {0x7, 0},
  {0x3, 0},
  {0xdc, 0},
  {0x1713e, 0},
  {0x8d28, 0},
  {0xbb0ef6d, 0},
  {0x3c7, 0},
  {0x2, 0},
  {0xd0e53fcc, 0},
  {0x2e2, 0},
  {0x762, 0},
  {0xf, 0},
  {0x35, 0},
  {0x2fc6e7a, 0},
  {0x105, 0},
  {0x58e3, 0},
  {0x3, 0},
  {0x16aa, 0},
  {0x7b1b38, 0},
  {0x0, 0},
  {0x2b, 0},
  {0x99538d, 0},
  {0xb3234, 0},
  {0x322, 0},
  {0x806bd, 0},
  {0xd73, 0},
  {0x503a, 0},
  {0x7d, 0},
  {0xb88bb919, 0},
  {0x4f5, 0},
  {0x1f757c4f, 0},
  {0xc37e5, 0},
  {0xd9e519, 0},
  {0xf0a, 0},
  {0xe9f1e8d, 0},
  {0x4664, 0},
  {0x4, 0},
  {0x1, 0},
  {0x1, 0},
  {0x0, 0},
  {0x1ee25, 0},
  {0x75a24, 0},
  {0x73c57b0, 0},
  {0x300e9, 0},
  {0x9, 0},
  {0x5b, 0},
  {0x6d25, 0},
  {0x38bf436e, 0},
  {0xf4724994, 0},
  {0x2b, 0},
  {0xb8a5de, 0},
  {0x4a, 0},
  {0x281da, 0},
  {0x905db8, 0},
  {0x3d606, 0},
  {0x6c200855, 0},
  {0x21, 0},
  {0x354e0dfa, 0},
  {0x2, 0},
  {0x1, 0},
  {0xf8297c3, 0},
  {0x2fed30, 0},
  {0xd4ab7, 0},
};


struct _variants variants[1] = {
  {"", 100, in0},
};

#define NUM_VARIANTS 1
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
#define FUNCNAME "ffs"
#include "bench-skeleton.c"
