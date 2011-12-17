#include "tpodata.h"
int ACA6447B9(TPOData *D)
{
    int i;
    (*(D->zp1))=(*(D->z2));
    for (i=0;i < DIMENSION; i++)
        (*(D->xp1))[i]=(*(D->X))[i];
    return 1;
}
