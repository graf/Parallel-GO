#include "tpodata.h"
int G6D2FF987(TPOData *D);
int BkvPar(LMAXS *HXMAX, QVAD2S *Hqva, double *Estron, double *lx, int *KlocMax, double *mmmax, int *NFUNC, MPAR *Akfun, FUNC *zp1, int *Nloc0)
{
    TPOData D(myProcNum+1);
    *(D.Akfun) = *Akfun;
    *(D.HXMAX) = *HXMAX;
    *(D.Hqva) = *Hqva;
    *(D.Estron) = *Estron;
    *(D.lx) = *lx;
    *(D.KlocMax) = *KlocMax;
    *(D.mmax) = *mmmax;
    *(D.NFUNC) = *NFUNC;
    *(D.zp1) = *zp1;
    *(D.Nloc0) = *Nloc0;

    G6D2FF987(&D);

    *Akfun = *(D.Akfun);
    *HXMAX = *(D.HXMAX);
    *Hqva = *(D.Hqva);
    *Estron = *(D.Estron);
    *lx = *(D.lx);
    *KlocMax = *(D.KlocMax);
    *mmmax = *(D.mmax);
    *NFUNC = *(D.NFUNC);
    *zp1 = *(D.zp1);
    *Nloc0 = *(D.Nloc0);
    return 0;
}
