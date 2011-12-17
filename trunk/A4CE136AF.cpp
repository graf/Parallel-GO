#include "tpodata.h"
extern int SBEC09D15(QVAD2S *simps);
int A4CE136AF(TPOData *D)
{
    //Удаление элемента из головы списка квадратов
    QVAD2S *_simps = D->Hqva;

    int result = SBEC09D15(_simps);

    D->Hqva = _simps;


    return result;
}
