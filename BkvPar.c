#include "tpodata.h"

int BkvPar(LMAXS *HXMAX, QVAD2S *Hqva, double *Estron, double *lx, int *KlocMax, double *mmmax, int *NFUNC, MPAR *Akfun, FUNC *zp1, int *Nloc0)
{
    TPOData D(0);
    D.Akfun = Akfun;
    D.HXMAX = HXMAX;
    D.Hqva = Hqva;
    D.Estron = Estron;
    D.lx = lx;
    D.KlocMax = KlocMax;
    D.mmax = mmmax;
    D.NFUNC = NFUNC;
    D.zp1 = zp1;
    D.Nloc0 = Nloc0;
    G6D2FF987(&D);
    return 0;
}
