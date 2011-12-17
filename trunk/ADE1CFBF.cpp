#include "tpodata.h"
int ADE1CFBF(TPOData *D)
{
    (*(D->Lor))=(*(D->LorQ))+1;
    return 1;
}
