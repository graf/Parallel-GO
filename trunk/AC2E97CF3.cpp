#include "tpodata.h"
int AC2E97CF3(TPOData *D)
{
  if ((*(D->Reg))==0) (*(D->Ksum))=(*(D->Diag)); 
  else {
    (*(D->Ksum))=(*(D->mi))*(*(D->hx))+((*(D->w0))-(*(D->wold)))*((*(D->w0))-(*(D->wold)))/((*(D->mi))*(*(D->hx))); 
    (*(D->Ksum))=(*(D->Ksum))+2*((*(D->w0))+(*(D->wold)));
  }
  return 1;
}
