#include "tpodata.h"
#include "utils.h"
int G6D2FF987(TPOData *D);
int BkvParU(LMAXS *HXMAX, QVAD2S *Hqva, double *, double *lx, int *KlocMax, double *mmmax, int *NFUNC, MPAR *Akfun, FUNC *zp1, int *Nloc0, int* Reg, int* Nmax2)
{
    TPOData D(myProcNum+1);
    *(D.Akfun) = *Akfun;
    *(D.HXMAX) = *HXMAX;
    *(D.Hqva) = *Hqva;
    *(D.lx) = *lx;
    *(D.KlocMax) = *KlocMax;
    *(D.mmax) = *mmmax;
    *(D.NFUNC) = *NFUNC;
    *(D.zp1) = *zp1;
    *(D.Nlok) = *Nloc0;
    *(D.Reg) = *Reg;
    *(D.Nmax2) = *Nmax2;

    G6D2FF987(&D);

    *Akfun = *(D.Akfun);
    *HXMAX = *(D.HXMAX);
    *Hqva = *(D.Hqva);
    *lx = *(D.lx);
    *KlocMax = *(D.KlocMax);
    *mmmax = *(D.mmax);
    *NFUNC = *(D.NFUNC);
    *zp1 = *(D.zp1);
    *Nloc0 = *(D.Nlok);
    *Nmax2 = *(D.Nmax2);
    *Reg = *(D.Reg);


    return 0;
}
