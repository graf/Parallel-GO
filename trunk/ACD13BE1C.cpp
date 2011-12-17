#include "tpodata.h"
int ACD13BE1C(TPOData *D)
{
  int i;
  for(i=0;i<DIMENSION;i++)
      (*(D->X0))[i]=(*(*(D->Hqva))).x0[i];
  (*(D->hx))=(*(*(D->Hqva))).hx;
  (*(D->wold))=(*(*(D->Hqva))).z;
  (*(D->iNX))=(*(*(D->Hqva))).d2z;
  (*(D->LorQ))=(*(*(D->Hqva))).Loran;
  (*(D->Diag))=(*(*(D->Hqva))).Str;
  (*(D->Hbd))=(*(*(D->Hqva))).Hbd;
  return 1;
}
