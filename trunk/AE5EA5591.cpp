#include "tpodata.h"
extern int S6F7D238B(QVAD2S *simps, double *hxMax);
int AE5EA5591(TPOData *D)
{
    //Определение размера максимального зерна в списке симплексов
    QVAD2S *_simps = D->Hqva;
    double *_hxMax = D->maxhx;

    int result = S6F7D238B(_simps, _hxMax);

    D->Hqva = _simps;
    D->maxhx = _hxMax;

    return result;
}
