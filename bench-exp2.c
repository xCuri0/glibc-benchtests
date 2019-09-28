#include <math.h>

#define CALL_BENCH_FUNC(v, i, x) exp2 (x variants[v].in[i].arg0)

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


struct args in0[102] = {
  {-0x1.8235e0aa4aab1p814, 0},
  {0x1.0e1220dfad80dp1006, 0},
  {-0x1.e6a710eed0706p919, 0},
  {0x1.11def1bbe9bc3p-471, 0},
  {0x1.05e9b1fc591d9p-1007, 0},
  {0x1.a58906c628b46p984, 0},
  {0x1.772627fce1208p-256, 0},
  {-0x1.461c146b65f2cp-62, 0},
  {-0x1.6cf046992fa9ep-876, 0},
  {-0x1.eaca47d76382cp-413, 0},
  {0x1.5056d0027ca2bp-634, 0},
  {0x1.1be8235cf2515p-300, 0},
  {0x1.f667e36bb79d2p913, 0},
  {0x1.b9ae233039c9cp-721, 0},
  {0x1.b70ec546dac57p589, 0},
  {-0x1.3ef895a695202p-318, 0},
  {-0x1.e73d755c17ecap-901, 0},
  {-0x1.f0a09005d2fdcp-52, 0},
  {0x1.77520292c8ea7p786, 0},
  {0x1.e5c0a38dccd6fp-510, 0},
  {-0x1.21dd1410a13fdp469, 0},
  {-0x1.f1ea1752b167cp-855, 0},
  {0x1.149395c6b1dfcp237, 0},
  {-0x1.22cfe4ceb2a85p244, 0},
  {0x1.061a75f02c856p-417, 0},
  {-0x1.04aaf4e1a4962p-645, 0},
  {-0x1.b962f2c49c11ap169, 0},
  {0x1.6074818509343p-151, 0},
  {-0x1.6b9946b997353p350, 0},
  {-0x1.6b8631635d607p-328, 0},
  {0x1.6893162dc2973p923, 0},
  {-0x1.0a1c40492986dp-371, 0},
  {-0x1.23ae72061594ap-113, 0},
  {0x1.d73d84becb49dp-816, 0},
  {0x1.545894ebc8944p-487, 0},
  {-0x1.c006c29733c62p325, 0},
  {-0x1.745dc305eeb06p-994, 0},
  {0x1.6cdeb63076b54p420, 0},
  {0x1.c8f137c690673p906, 0},
  {-0x1.170ab5609f77cp205, 0},
  {-0x1.0b11b685a3349p-46, 0},
  {0x1.7f68672b92eb1p-622, 0},
  {0x1.66d431dee4bfdp-333, 0},
  {-0x1.e43304b22a96dp228, 0},
  {0x1.58ac069095de9p-419, 0},
  {-0x1.3fcaa6e1f1ac3p654, 0},
  {-0x1.437ed00080554p-88, 0},
  {0x1.717ad5a379c50p531, 0},
  {0x1.9688d6a6dd841p127, 0},
  {-0x1.189c3732f9ac8p505, 0},
  {-0x1.8c5da688a249ep871, 0},
  {0x1.808015df2809ep-647, 0},
  {0x1.54ccb260c52f6p183, 0},
  {0x1.ec1574f23f1b5p757, 0},
  {-0x1.2de0222e50454p-176, 0},
  {-0x1.dc5715d5ac4f3p-882, 0},
  {0x1.6fa963199b1fbp389, 0},
  {-0x1.0a143338c0ff3p149, 0},
  {0x1.c278a3ec4071cp240, 0},
  {0x1.7bdb071d7e6ffp-360, 0},
  {-0x1.e9b7a0af460ddp-809, 0},
  {0x1.d069e62cf695bp535, 0},
  {0x1.0f7ba1b172a18p-887, 0},
  {-0x1.96af5166829b7p399, 0},
  {-0x1.8f70240823cdbp-65, 0},
  {-0x1.fcd2d5a63a217p-971, 0},
  {-0x1.089241ad467f2p-247, 0},
  {-0x1.3fa3940d58aa8p1022, 0},
  {-0x1.aff1c0aec4e7dp814, 0},
  {-0x1.6bad319cfc3bcp-378, 0},
  {0x1.9c8956c66ba36p-579, 0},
  {-0x1.6d9393f52ee3fp411, 0},
  {0x1.e529d23501328p926, 0},
  {0x1.3ec71520af29cp690, 0},
  {0x1.787576a795b83p194, 0},
  {-0x1.ef38147d2dc40p107, 0},
  {-0x1.22a125ccbb1b2p-308, 0},
  {0x1.5f5c074be0351p-928, 0},
  {-0x1.377ed64bec482p390, 0},
  {-0x1.09eae6f62d4b8p-41, 0},
  {0x1.9f3fd03635c92p-104, 0},
  {0x1.cb7d07d13c9efp599, 0},
  {0x1.49e8154de36a7p538, 0},
  {-0x1.d68343fe573bfp-736, 0},
  {-0x1.4beba6b79ba1ep-811, 0},
  {0x1.927774a125013p221, 0},
  {-0x1.e4a1e48c33931p-152, 0},
  {-0x1.b8a3123361eb5p641, 0},
  {-0x1.909ea08b262f3p960, 0},
  {0x1.0d1b30600d5b0p822, 0},
  {-0x1.392420cf4ce19p-690, 0},
  {-0x1.f9e1f71c0f3a2p-349, 0},
  {-0x1.75600638cbf0ep-527, 0},
  {-0x1.788911851a5abp-193, 0},
  {-0x1.2ab1045fa9103p-471, 0},
  {-0x1.d9c7f1a19cefdp-44, 0},
  {0x1.ef5a66b13a5f8p171, 0},
  {0x1.261c24ba6cdfbp539, 0},
  {0x1.641945dc01d29p-620, 0},
  {0x1.5c190276797a1p935, 0},
  {-0x1.ea76b6a8a9d4ap-656, 0},
  {0x1.41a117e9931f0p-169, 0},
};


struct _variants variants[1] = {
  {"", 102, in0},
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
#define FUNCNAME "exp2"
#include "bench-skeleton.c"
