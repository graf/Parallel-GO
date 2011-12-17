#include "tpodata.h"
int AAFE33EBC(TPOData *D)
{
    (*(D->Sumstep))  = (*(D->Sumstep)) + (*(D->Nstep));
    (*(D->Ntern)) = (*(D->Ntern)) + 1;
    return 1;
}
