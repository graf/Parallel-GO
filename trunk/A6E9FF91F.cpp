#include "tpodata.h"
int A6E9FF91F(TPOData *D)
{
    (*(D->kDi))=(*(D->iNX))+1;
    (*(D->Diag)) = sqrt(16*(DIMENSION-(*(D->kDi)))+4*(*(D->kDi)))*(*(D->hx));
    (*(D->Str))=(*(D->Str))-(*(D->hx));
    return 1;
}
