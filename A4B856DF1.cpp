#include "tpodata.h"
extern int S3BA8B77(QVAD2S *simps, int *Nsimp, double *d2z, double *Str, double *Ksum, XI *x0, double *z, double *hx, FUNC *DelS, int *Lor, int *Hbd);
int A4B856DF1(TPOData *D)
{
    //Запись перерасчитанных симплексов в базовый набор
    QVAD2S *_simps = D->Hqva;
    int *_Nsimp = D->j6;
    double *_d2z = D->d2z;
    double *_Str = D->Str;
    double *_Ksum = D->Ksum;
    XI *_x0 = D->X0;
    double *_z = D->w0;
    double *_hx = D->hx;
    FUNC *_DelS = D->wold;
    int *_Lor = D->Lor;
    int *_Hbd = D->Hbd;

    int result = S3BA8B77(_simps, _Nsimp, _d2z, _Str, _Ksum, _x0, _z, _hx, _DelS, _Lor, _Hbd);

    D->Hqva = _simps;
    D->j6 = _Nsimp;
    D->d2z = _d2z;
    D->Str = _Str;
    D->Ksum = _Ksum;
    D->X0 = _x0;
    D->w0 = _z;
    D->hx = _hx;
    D->wold = _DelS;
    D->Lor = _Lor;
    D->Hbd = _Hbd;


    return result;
}
