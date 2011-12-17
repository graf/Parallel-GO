#include "tpodata.h"
int A87B58126(TPOData *D)
{
  int i;
  for (i=0;i<DIMENSION;i++)
      (*(D->X))[i]=(*(D->X0))[i];
  (*(D->X))[(*(D->iNX))] = (*(D->X0))[(*(D->iNX))]-(*(D->hx));
  return 1;
}
