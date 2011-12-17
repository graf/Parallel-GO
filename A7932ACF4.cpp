#include "tpodata.h"
extern int S921B778D(LMAXS *simps);
int A7932ACF4(TPOData *D)
{
    //Удаление списка локальных экстремумов
    LMAXS *_simps = D->HXMAX;

    int result = S921B778D(_simps);

    D->HXMAX = _simps;


    return result;
}
