#include "tpodata.h"
int A5B00D10C(TPOData *D)
{
    (*(D->Zmax))=(*(D->zp1));(*(D->zmin))=(*(D->zp2));
    return 1;
}
