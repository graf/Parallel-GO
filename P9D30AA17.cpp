#include "tpodata.h"
extern int S31020C03(XIF *Z, XI *X0, int *NmaxF, double *lx, double *Kob);
int P9D30AA17(TPOData *D)
{
    XIF *_Z = D->Simpmax;
    XI *_X0 = D->X0;
    int *_NmaxF = D->Nmax;
    double *_lx = D->lx;
    double *_Kob = D->Kobl;

    int result = S31020C03(_Z, _X0, _NmaxF, _lx, _Kob);

    return result;
}
