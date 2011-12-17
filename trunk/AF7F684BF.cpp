#include "tpodata.h"
extern int S5A6D0DC4(XI *X, FUNC *Yc, MPAR *BB, int *Nfunc, double *Esimp);
int ABE3B97B1(TPOData *D);
int AF7F684BF(TPOData *D)
{
    //Поиск методом деформированных многогранников
    XI *_X = D->X;
    FUNC *_Yc = D->z2;
    MPAR *_BB = D->Akfun;
    int *_Nfunc = D->NFUNC;
    double *_Esimp = D->Esimp;

    int result = S5A6D0DC4(_X, _Yc, _BB, _Nfunc, _Esimp);

    D->X = _X;
    D->z2 = _Yc;
    D->Akfun = _BB;
    D->NFUNC = _Nfunc;
    D->Esimp = _Esimp;


    return result;
}
