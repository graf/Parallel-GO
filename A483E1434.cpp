#include "tpodata.h"
int A483E1434(TPOData *D)
{
    (*(D->Akfun)).GKLS_dim=DIMENSION;
    (*(D->Akfun)).tip=(*(D->GKLtip));
    (*(D->Akfun)).N_fun=(*(D->N_fun));
    return 1;
}
