#include <math.h>

#define CALL_BENCH_FUNC(v, i, x) asinh (x variants[v].in[i].arg0)

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


struct args in0[300] = {
  {0x1.408fb643484cep-11, 0},
  {0x1.f0763423f1d52p-23, 0},
  {-0x1.681573418e494p4, 0},
  {-0x1.87cc25833f74bp16, 0},
  {-0x1.ad3df5eb7db54p24, 0},
  {0x1.90f147b3d0164p829, 0},
  {-0x1.60b1066c6712ep71, 0},
  {-0x1.5997c27aac9ccp332, 0},
  {-0x1.2cb3142c669a0p15, 0},
  {-0x1.ec882168157e6p191, 0},
  {0x1.43a1d0e6eae29p109, 0},
  {-0x1.2b43c388e1857p672, 0},
  {0x1.f11c07e219bafp7, 0},
  {0x1.f5efb379e3b3fp952, 0},
  {-0x1.405cf322b684cp-13, 0},
  {-0x1.fa64c4090d337p43, 0},
  {0x1.a98724f016a93p-13, 0},
  {-0x1.5743f3604a7fbp10, 0},
  {0x1.042971d37879bp-17, 0},
  {0x1.d4cda5814c00fp-2, 0},
  {0x1.ec1e878f29cf8p97, 0},
  {-0x1.6a4cd37896c5fp-24, 0},
  {0x1.da85d34b19160p-10, 0},
  {0x1.c068c277d171fp-17, 0},
  {-0x1.b3e2d1ead4160p-1, 0},
  {-0x1.ac8a62deb27c3p521, 0},
  {-0x1.e28e32ce20a25p-1, 0},
  {-0x1.e70635022c5fdp315, 0},
  {0x1.984146d8a6c69p20, 0},
  {-0x1.67cf155405aadp747, 0},
  {-0x1.a852444a7de0ep-23, 0},
  {0x1.92e4800542f83p108, 0},
  {-0x1.564ba0e9ad540p-7, 0},
  {0x1.c36c11c290063p20, 0},
  {0x1.4723d5459434cp-26, 0},
  {-0x1.43c1535cd024bp-11, 0},
  {0x1.6d46e7252da2fp388, 0},
  {0x1.756f2685e9ca9p-26, 0},
  {-0x1.72268726f4141p22, 0},
  {0x1.558480e0da8bdp15, 0},
  {0x1.ef0970332ed6fp-3, 0},
  {0x1.2015764e98ea6p481, 0},
  {-0x1.3a0f66a229b60p871, 0},
  {-0x1.c833f28187420p-25, 0},
  {-0x1.a0ea74513cffbp778, 0},
  {-0x1.d2dde734625d1p13, 0},
  {-0x1.996507c01ea97p25, 0},
  {0x1.d36f165b63b8fp880, 0},
  {0x1.445234d59e32bp-2, 0},
  {0x1.cd74423b4c4aep15, 0},
  {-0x1.c0b6631621425p-1, 0},
  {0x1.a2e0f00779702p-25, 0},
  {-0x1.fcf5c0266c2f2p-22, 0},
  {-0x1.af38a56120728p-21, 0},
  {-0x1.9ec217ea497dap1, 0},
  {0x1.57a000ceee049p800, 0},
  {0x1.6c1b6312efacfp783, 0},
  {0x1.afb5c0c4f933ap6, 0},
  {-0x1.f9267499e3327p16, 0},
  {-0x1.9b5ba5b496ae5p10, 0},
  {0x1.3975f02686229p10, 0},
  {0x1.36b913a68fe70p901, 0},
  {0x1.8946b691ecf5ap10, 0},
  {-0x1.efbb62a588bccp24, 0},
  {0x1.f3de8628048d9p-8, 0},
  {0x1.8ec222d562aa9p25, 0},
  {-0x1.ac03e6a0d863cp22, 0},
  {-0x1.6d9d94c1e0b6fp23, 0},
  {0x1.9807337060f87p-10, 0},
  {0x1.0f8045a313158p26, 0},
  {0x1.fe8cd64528951p-16, 0},
  {-0x1.51c184460cfafp-26, 0},
  {-0x1.74b0f442763c7p20, 0},
  {-0x1.d30da53c93e10p18, 0},
  {0x1.749735f182597p15, 0},
  {0x1.253da08c9c318p144, 0},
  {-0x1.2714417156ae3p693, 0},
  {-0x1.189320570f30bp26, 0},
  {-0x1.a2e120ac12626p756, 0},
  {0x1.ce724582eabcfp-24, 0},
  {0x1.30dcf0414c561p292, 0},
  {-0x1.1a1790d8a72d1p452, 0},
  {0x1.3242254b631b3p-26, 0},
  {-0x1.b5890305f1b78p11, 0},
  {0x1.019a86d2e2300p18, 0},
  {0x1.0e9cc39a3bff8p-14, 0},
  {0x1.bc8ff7e59e82ep18, 0},
  {-0x1.235a45afa3842p25, 0},
  {0x1.0b2c87979b28cp23, 0},
  {0x1.c717951ecf869p-9, 0},
  {0x1.daff104bb08a5p25, 0},
  {-0x1.b14b119b47d4ep5, 0},
  {0x1.6e8a94f758a02p802, 0},
  {0x1.7788055510c4dp23, 0},
  {0x1.6120d7e4e5d9ep498, 0},
  {0x1.1154e15c2c284p-24, 0},
  {0x1.eb28429726661p423, 0},
  {-0x1.b9faa23669003p9, 0},
  {-0x1.a615746664b00p339, 0},
  {-0x1.835384e92d59cp56, 0},
  {0x1.1fb4b0fe36aacp-3, 0},
  {-0x1.e440c3183f046p-19, 0},
  {-0x1.1e714012cae50p22, 0},
  {-0x1.1821b0014d9cep-16, 0},
  {-0x1.5de4c1e0a1bfep-24, 0},
  {-0x1.c1e5c78840e91p25, 0},
  {0x1.f0b1d4cd82236p18, 0},
  {-0x1.450ff3ad26e5bp984, 0},
  {0x1.23438314fb10bp0, 0},
  {-0x1.82be43e413126p14, 0},
  {-0x1.5c70206fd22f7p628, 0},
  {0x1.7e213160ec541p-15, 0},
  {0x1.5487358228cedp-14, 0},
  {0x1.4a163440f7c98p4, 0},
  {0x1.ad443265c6b4ap845, 0},
  {-0x1.732c509382338p-2, 0},
  {0x1.929ba224e2240p-17, 0},
  {0x1.a026b0485c0e8p12, 0},
  {-0x1.fa4e77f1b2343p-12, 0},
  {-0x1.3a2ac1c73ae50p5, 0},
  {0x1.0c4a80d41a2f7p-20, 0},
  {-0x1.1c57b37023dcep150, 0},
  {-0x1.2c1b509030e5dp26, 0},
  {-0x1.c7cdd089827cdp-26, 0},
  {0x1.3d88b121650aap8, 0},
  {-0x1.1583f2a9d2d5dp618, 0},
  {0x1.295d65809666fp111, 0},
  {-0x1.3dc8c1a73f146p-3, 0},
  {-0x1.4dc715a6ae290p999, 0},
  {-0x1.3808360307701p464, 0},
  {-0x1.adf4158880f7bp2, 0},
  {-0x1.3913104f0eea6p-16, 0},
  {0x1.8c91558dbd886p-2, 0},
  {-0x1.d67f73ef2736ap11, 0},
  {0x1.218c0592aa7fcp95, 0},
  {0x1.4c1e32e79005dp7, 0},
  {0x1.395461c5f96a6p5, 0},
  {-0x1.a311a7fbb5afap-12, 0},
  {0x1.f07b95fd415ccp9, 0},
  {-0x1.08745233a4ce8p-13, 0},
  {0x1.38f122e7f7be0p220, 0},
  {0x1.8c9c967e8e99ap-5, 0},
  {-0x1.3353e4fc6b002p987, 0},
  {0x1.945a20aa092e2p4, 0},
  {0x1.a7a935f93958ap22, 0},
  {-0x1.946865aa1c43cp-20, 0},
  {0x1.001d955d8a436p344, 0},
  {-0x1.5146c4a1225eep-22, 0},
  {0x1.ffab14f637eaap733, 0},
  {-0x1.3d50819d9de92p-8, 0},
  {0x1.84a7b4b80f227p4, 0},
  {0x1.73af93193478dp-6, 0},
  {0x1.3ac9b75c613bdp160, 0},
  {0x1.dafd9764a705fp13, 0},
  {0x1.91bc310a7648ep243, 0},
  {-0x1.531fa4a4bac3ap713, 0},
  {0x1.95c32605e6c59p20, 0},
  {-0x1.012141d71b636p-2, 0},
  {-0x1.eb4540a49b927p20, 0},
  {0x1.9c4716594b306p-24, 0},
  {-0x1.242df1aa8bf7ep642, 0},
  {-0x1.2d1fc7cf19d2ap-27, 0},
  {0x1.161fd6fd320d5p745, 0},
  {-0x1.3aaa34f975620p811, 0},
  {0x1.9e11325b1c3c4p22, 0},
  {-0x1.a838b07a6641ap5, 0},
  {0x1.8b1a0407ae636p7, 0},
  {-0x1.eb717004808e1p469, 0},
  {-0x1.d166757807df4p-6, 0},
  {0x1.2a57014d8c24bp317, 0},
  {-0x1.5ea093bc15910p468, 0},
  {-0x1.2545b7ec8b35fp-3, 0},
  {-0x1.e47ca00d1f14ep929, 0},
  {0x1.af09542db1b29p-18, 0},
  {-0x1.8d4bc4f005536p6, 0},
  {-0x1.8d564435d4d3fp-9, 0},
  {0x1.993a6363227e2p12, 0},
  {0x1.bec162f84a16cp13, 0},
  {0x1.f0a22293c4ecbp852, 0},
  {0x1.9eb0b40303dcap843, 0},
  {-0x1.0cdae1dc93ed0p22, 0},
  {0x1.21efa25110e19p12, 0},
  {-0x1.cf1531a43c397p144, 0},
  {-0x1.a043f6a911bdep-16, 0},
  {0x1.816c4063e718ap-15, 0},
  {0x1.e23b95950e47dp-21, 0},
  {0x1.a0830483382afp2, 0},
  {-0x1.52e49239a95d4p957, 0},
  {0x1.f73a3049f9d76p16, 0},
  {-0x1.1304063a4fbe5p316, 0},
  {0x1.f5b95104bb64dp320, 0},
  {0x1.661d765a50087p13, 0},
  {0x1.7bb5671e2bfcap719, 0},
  {0x1.3e14e736580b3p-20, 0},
  {-0x1.11340035e5609p-25, 0},
  {0x1.c4d527df0d553p762, 0},
  {-0x1.731bc7cf3026ap7, 0},
  {-0x1.079c1776f403fp965, 0},
  {0x1.e6879000598aep-28, 0},
  {-0x1.d3bee1e831937p25, 0},
  {0x1.c3b5f0096df0dp24, 0},
  {0x1.667d70b10ce7ep-6, 0},
  {0x1.c780d2406b7d1p-26, 0},
  {-0x1.df8fd3fe95d12p27, 0},
  {0x1.89494217ed887p204, 0},
  {-0x1.ea94d70c825d3p764, 0},
  {-0x1.04366739a80cbp11, 0},
  {0x1.75f1269063e4dp5, 0},
  {0x1.0a46e3262c2b8p20, 0},
  {-0x1.92c337d25b414p-4, 0},
  {0x1.5c2cb3414299cp154, 0},
  {0x1.07f7c34023735p881, 0},
  {0x1.c64b8297569c4p207, 0},
  {0x1.13f4d3bbd6417p8, 0},
  {0x1.bde9c42ffd9ecp-15, 0},
  {0x1.9e07054aa7309p743, 0},
  {-0x1.dd8c11c0073a4p-16, 0},
  {-0x1.e04d9283ac8d4p20, 0},
  {-0x1.c0f2e29b30840p10, 0},
  {0x1.55a4c648ebcc2p378, 0},
  {-0x1.7b0c92c6d8687p658, 0},
  {-0x1.ed8bb5ef46109p24, 0},
  {0x1.5cc2904baa4d2p-18, 0},
  {-0x1.b688c6944fa1dp-3, 0},
  {-0x1.2330768204f78p754, 0},
  {0x1.650441a7059bdp554, 0},
  {-0x1.0d1c66b57d36bp493, 0},
  {-0x1.54e35714807acp368, 0},
  {-0x1.6165d7bebf894p776, 0},
  {0x1.7e0ba7c987b9ep7, 0},
  {0x1.d139574e3913ep168, 0},
  {-0x1.40cc4145ea64ep19, 0},
  {0x1.0db7e5339af44p-8, 0},
  {-0x1.87410240fe22cp-9, 0},
  {-0x1.d0f46605d4a27p18, 0},
  {0x1.d1e8b19cca04dp-19, 0},
  {0x1.979981827668ap-21, 0},
  {0x1.2576745f4cca6p22, 0},
  {-0x1.1f02e2c0c288dp14, 0},
  {-0x1.77bab17202acap-13, 0},
  {0x1.25c5071d2dc6ep8, 0},
  {-0x1.306185b351fdap26, 0},
  {-0x1.ad6e853661ee0p587, 0},
  {0x1.f389b34d6b10fp-13, 0},
  {0x1.08fa931bd21f5p10, 0},
  {-0x1.b65bf00b921e8p-24, 0},
  {-0x1.cbb5f173385aep82, 0},
  {0x1.a32cd47340669p2, 0},
  {-0x1.a83fd05f605e6p-25, 0},
  {0x1.8184a3fcc1ac3p942, 0},
  {0x1.61c9644526617p809, 0},
  {0x1.b12c01289b0c4p15, 0},
  {-0x1.16a4a50f1192bp-17, 0},
  {-0x1.5658b26bd2888p-9, 0},
  {-0x1.8c5563528e33bp-14, 0},
  {-0x1.fd7e32bd8a9adp-23, 0},
  {-0x1.1106a6a425747p-18, 0},
  {0x1.98109155dd7bfp21, 0},
  {0x1.dbd635362ec6bp6, 0},
  {0x1.4a1600b2e95dbp880, 0},
  {-0x1.2fd6819d3d81cp361, 0},
  {-0x1.28f5b629029b5p12, 0},
  {0x1.64c6a3d5a0867p304, 0},
  {0x1.97ae606371057p22, 0},
  {-0x1.d61a76409f8f9p-25, 0},
  {0x1.a4c67223582ffp-27, 0},
  {0x1.b569919b79b6fp214, 0},
  {0x1.1bf0416ef51a4p-28, 0},
  {-0x1.1b9502079e873p-25, 0},
  {-0x1.a94006dd19303p355, 0},
  {-0x1.78bd67abffa91p20, 0},
  {0x1.96d320a0153bap383, 0},
  {0x1.f82770adf361dp19, 0},
  {0x1.ee0725a2dbe84p-28, 0},
  {0x1.93d4c19692fbfp80, 0},
  {0x1.d69c251aa0003p-3, 0},
  {-0x1.36c310f2a5894p-26, 0},
  {-0x1.7bbce527b5784p19, 0},
  {0x1.5a90f2032fb5ap-14, 0},
  {-0x1.194fe079c05eep1002, 0},
  {0x1.2e9a406645b9bp609, 0},
  {-0x1.c566e4a419660p-14, 0},
  {0x1.f917868895288p872, 0},
  {0x1.a966a17972ca9p601, 0},
  {-0x1.6d5eb4970b882p-20, 0},
  {0x1.c1a0d0ee96f75p27, 0},
  {0x1.958fd1185d839p-24, 0},
  {-0x1.c738b5fffeeb2p4, 0},
  {0x1.91bf33cdb6804p710, 0},
  {-0x1.66e0a7e4034dbp224, 0},
  {-0x1.dd6e42f5992c4p667, 0},
  {-0x1.6e17000848200p951, 0},
  {-0x1.f625958e05264p-1, 0},
  {-0x1.63e025fbcdcacp442, 0},
  {0x1.c5fb927d2cb09p8, 0},
  {-0x1.d7e514672b2ddp987, 0},
  {0x1.0eec25d2a59ccp27, 0},
  {0x1.342f35eabf622p707, 0},
  {-0x1.6ffad140301c8p609, 0},
  {-0x1.5b10b0ca4ea9dp-21, 0},
};


struct _variants variants[1] = {
  {"", 300, in0},
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
#define FUNCNAME "asinh"
#include "bench-skeleton.c"