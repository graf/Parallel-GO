#include "tpodata.h"
int A7D450414(TPOData *D)
{
  double y,hb;hb=(*(D->Nbd))-(*(D->Hbd)); if (hb>=1) y=DIMENSION*hb*log(2);else y=0; (*(D->Nstep))=(*(D->Nstep))+2*(exp(y)-1);
  return 1;
}
