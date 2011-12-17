#include "tpodata.h"
int A8E248E71(TPOData *D)
{
    int i;
    (*(D->zp2))=(*(D->z2));
    for (i=0; i < DIMENSION; i++)
        (*(D->xp2))[i] = (*(D->X))[i];
    return 1;
}
