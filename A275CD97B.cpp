#include "tpodata.h"
extern int S93CDA455(LMAXS *HXMAX, QVAD2S *Hqva, double *Estron, double *lx, int *KlocMax, double *mmmax, int *NFUNC, MPAR *Akfun, FUNC *zp1, int *Nloc0);
int A275CD97B(TPOData *D)
{
    //Локальный поиск в параллельной ветке точки притяжения
    LMAXS *_HXMAX = D->HXMAX;
    QVAD2S *_Hqva = D->Hq2;
    double *_Estron = D->Estron;
    double *_lx = D->lx;
    int *_KlocMax = D->KlocMax;
    double *_mmmax = D->mmax;
    int *_NFUNC = D->NFUNC;
    MPAR *_Akfun = D->Akfun;
    FUNC *_zp1 = D->zp1;
    int *_Nloc0 = D->Nlok;

    int result = S93CDA455(_HXMAX, _Hqva, _Estron, _lx, _KlocMax, _mmmax, _NFUNC, _Akfun, _zp1, _Nloc0);

    D->HXMAX = _HXMAX;
    D->Hq2 = _Hqva;
    D->Estron = _Estron;
    D->lx = _lx;
    D->KlocMax = _KlocMax;
    D->mmax = _mmmax;
    D->NFUNC = _NFUNC;
    D->Akfun = _Akfun;
    D->zp1 = _zp1;
    D->Nlok = _Nloc0;



    return result;
}
