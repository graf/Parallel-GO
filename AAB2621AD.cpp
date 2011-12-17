#include "tpodata.h"
extern int S6628910D(QVAD2S *Hqva, QVAD2S *Hq2, SEGM *PRLp, int *NprlTec);
int AAB2621AD(TPOData *D)
{
    //Разборка списка симплексов по процессорам
    QVAD2S *_Hqva = D->Hqva;
    QVAD2S *_Hq2 = D->Hq2;
    SEGM *_PRLp = D->PRLp;
    int *_NprlTec = D->NprlTec;

    int result = S6628910D(_Hqva, _Hq2, _PRLp, _NprlTec);

    D->Hqva = _Hqva;
    D->Hq2 = _Hq2;
    D->PRLp = _PRLp;
    D->NprlTec = _NprlTec;


    return result;
}
