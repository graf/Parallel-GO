#include "tpodata.h"
int P81F94AA6(TPOData *D)
{
  return (((*(D->Diag)) < (*(D->Eloc))));
  printf("Process %d: Diag = %g Eloc = %g\r\n", myProcNum, *(D->Diag), *(D->Eloc));
}
