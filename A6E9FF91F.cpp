#include "tpodata.h"
int A6E9FF91F(TPOData *D)
{
    (*(D->kDi))=(*(D->iNX))+1;
    (*(D->Diag)) = sqrt(16*(DIMENSION-(*(D->kDi)))+4*(*(D->kDi)))*(*(D->hx));
//    printf("Process %d: A6E9FF91F Diag = %g\r\n", myProcNum, *D->Diag);
    (*(D->Str))=(*(D->Str))-(*(D->hx));
    return 1;
}
