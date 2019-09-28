#include <string.h>

#define CALL_BENCH_FUNC(v, i, x) ffsll (x variants[v].in[i].arg0)

struct args
{
  long long volatile arg0;
  double timing;
};

struct _variants
{
  const char *name;
  int count;
  struct args *in;
};


struct args in0[100] = {
  {0xedada05aba9463, 0},
  {0x7c4e52bbc75241, 0},
  {0x16ab7ad, 0},
  {0x20ec623a4ccdb, 0},
  {0x1e24e9ed059d, 0},
  {0x3acf, 0},
  {0x6eb28fbb803a274, 0},
  {0xc1, 0},
  {0x25fc2148c092529f, 0},
  {0x1d10ba752e5, 0},
  {0x322bd878b3, 0},
  {0x26fa11b70e20, 0},
  {0x30cd6a05a17ca14b, 0},
  {0x1591d3a2d0cc7, 0},
  {0x8119d76e910c1a, 0},
  {0x2b24d878fee314, 0},
  {0x1c, 0},
  {0x3022a3955, 0},
  {0xedc7b7b6a818, 0},
  {0x40, 0},
  {0xf28, 0},
  {0xa2ecb, 0},
  {0x56a7e4211a2ca38, 0},
  {0x6a0ee2316382, 0},
  {0x634, 0},
  {0x58, 0},
  {0x4fad66fb43f5, 0},
  {0x1f004b76, 0},
  {0x7, 0},
  {0x6ff84575bb70af, 0},
  {0x5d5b4e, 0},
  {0xaa614b130, 0},
  {0x15504, 0},
  {0x1a2e2e7e, 0},
  {0x54b0f28b383cc, 0},
  {0x6, 0},
  {0x2a2a3440b7, 0},
  {0x158a132dc0c20836, 0},
  {0x77aa8e9c91c43b1, 0},
  {0x33f526901fc08594, 0},
  {0x7bf156c, 0},
  {0xb458b5e, 0},
  {0x6289fcb44, 0},
  {0x4d84973bbd8c00, 0},
  {0x2e8c2de648, 0},
  {0x150fab, 0},
  {0x16ebb7bae02934, 0},
  {0x485285b6065272, 0},
  {0xfdde0b16299, 0},
  {0x747d3c940cb, 0},
  {0x1bdb379, 0},
  {0xfcb26a, 0},
  {0x20b90cc92bbef, 0},
  {0x46, 0},
  {0xf0e681aaec28b2d5, 0},
  {0x10c738cf1109, 0},
  {0x8509bef69993908, 0},
  {0x3332, 0},
  {0x219167d, 0},
  {0x7eb19c6f88f, 0},
  {0x32a1b4ead441e65, 0},
  {0xdc93, 0},
  {0x327a7e6676802312, 0},
  {0xcc7296c957, 0},
  {0xb0b20c47c6b500a, 0},
  {0x55d614072f1, 0},
  {0x3c8e4, 0},
  {0x1a, 0},
  {0x5809b7ae, 0},
  {0x2, 0},
  {0x1525, 0},
  {0x13, 0},
  {0x6e, 0},
  {0x1b, 0},
  {0x7c58cf, 0},
  {0x2f5347197bcf6, 0},
  {0x516a0d576e2c3, 0},
  {0x4f3cf315, 0},
  {0x3c16a7531f3a1, 0},
  {0xa929f8, 0},
  {0x1ce88e5, 0},
  {0x6ab464e92bc3, 0},
  {0x3ff39bb2, 0},
  {0xea9921, 0},
  {0xb3009, 0},
  {0x39b037793bef0da0, 0},
  {0x5d, 0},
  {0x39a9989019c92, 0},
  {0x108bae, 0},
  {0x239c1c, 0},
  {0x1851dc9178f4, 0},
  {0x1fc6f70, 0},
  {0x38, 0},
  {0xa8f606a147, 0},
  {0x30dac66b, 0},
  {0x76d377c20b0e836, 0},
  {0x2425, 0},
  {0x4e5a82884, 0},
  {0x7a1f128a894728, 0},
  {0xb5f0af24e3f7347, 0},
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
#define FUNCNAME "ffsll"
#include "bench-skeleton.c"
