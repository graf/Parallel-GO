#include "tpodata.h"
int A3FBDF9D1(TPOData *D)
{
    int i;
    for (i=0; i < TOTAL_PROCS_NUMBER; i++)  {
        (*(D->PRLp)).MQVAD[i] = NULL;
        (*(D->PRLp)).NF[i] = 0;
    }
    for (i=0;i < DIMENSION; i++)
        (*(D->X))[i]=0.5;
    return 1;
}
