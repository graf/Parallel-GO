#include "tpodata.h"
extern int BkvPar(LMAXS *HXMAX, QVAD2S *Hqva, double *Estron, double *lx, int *KlocMax, double *mmmax, int *NFUNC, MPAR *Akfun, FUNC *zp1, int *Nloc0);
int S93CDA455(LMAXS *HXMAX, QVAD2S *Hqva, double *Estron, double *lx, int *KlocMax, double *mmmax, int *NFUNC, MPAR *Akfun, FUNC *zp1, int *Nloc0)
{
    return BkvPar(HXMAX, Hqva, Estron, lx, KlocMax, mmmax, NFUNC, Akfun, zp1, Nloc0);
}
