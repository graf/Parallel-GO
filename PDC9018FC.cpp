#include "tpodata.h"
extern int S59018825(LMAXS *Hxs, int *Krep, int *Nmax);
int PDC9018FC(TPOData *D)
{
    LMAXS *_Hxs = D->HXMAX;
    int *_Krep = D->Krep;
    int *_Nmax = D->Nmax;

    int result = S59018825(_Hxs, _Krep, _Nmax);



    return result;
}
