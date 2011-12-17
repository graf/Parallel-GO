#include "tpodata.h"
int P36AADBB9(TPOData *D)
{
  return ((((*(D->z2))-(*(D->Zmax)))/(*(D->hx))>(*(D->Kz)))&&((*(D->z2))>(*(D->Zmax))));
}
