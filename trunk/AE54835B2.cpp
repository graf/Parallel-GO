#include "tpodata.h"
extern int S1441B5B5(QVAD2S *Hqva, XI *X0, double *hx, double *d2z, double *w0, double *Str, int *Lor, int *j6, FUNC *wold, int *Hbd);
int AE54835B2(TPOData *D)
{
    //Чтение полей симплекса
    QVAD2S *_Hqva = D->Hq2;
    XI *_X0 = D->X0;
    double *_hx = D->hx;
    double *_d2z = D->d2z;
    double *_w0 = D->w0;
    double *_Str = D->Str;
    int *_Lor = D->Lor;
    int *_j6 = D->j6;
    FUNC *_wold = D->wold;
    int *_Hbd = D->Hbd;

    int result = S1441B5B5(_Hqva, _X0, _hx, _d2z, _w0, _Str, _Lor, _j6, _wold, _Hbd);

    D->Hq2 = _Hqva;
    D->X0 = _X0;
    D->hx = _hx;
    D->d2z = _d2z;
    D->w0 = _w0;
    D->Str = _Str;
    D->Lor = _Lor;
    D->j6 = _j6;
    D->wold = _wold;
    D->Hbd = _Hbd;


    return result;
}
