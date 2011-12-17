#include "tpodata.h"
int AB20CC9C7(TPOData *D)
{
  int i;
  for (i=0;i<DIMENSION;i++)
      ((*(*(D->Htmax))).xLm)[i]=(*(D->X))[i];
  (*(*(D->Htmax))).fLmax=(*(D->z2));
  (*(D->Htmax))=(*(*(D->Htmax))).next;
  return 1;
}
