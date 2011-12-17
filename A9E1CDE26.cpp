#include "tpodata.h"
#include <stdio.h>
#include <stdlib.h>
extern int SACD3CE29(LMAXS *Hxs, XI *xf, FUNC *z, double *Eloc, int *Nmax, int *Kmax);
int A9E1CDE26(TPOData *D)
{
    //Формирование локальных областей поиска локальных максимумов
    LMAXS *_Hxs = D->HXMAX;
    XI *_xf = D->X;
    FUNC *_z = D->z2;
    double *_Eloc = D->Eloc;
    int *_Nmax = D->Nmax2;
    int *_Kmax = D->KlocMax;

    int result = SACD3CE29(_Hxs, _xf, _z, _Eloc, _Nmax, _Kmax);

    D->HXMAX = _Hxs;
    D->X = _xf;
    D->z2 = _z;
    D->Eloc = _Eloc;
    D->Nmax2 = _Nmax;
    D->KlocMax = _Kmax;


    return result;
}
