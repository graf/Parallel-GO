#include "tpodata.h"
int P32265593(TPOData *D)
{
//    if ((*D->ILok % 10000) == 0)
//        printf("Process %d: tIlok = %d\r\n",myProcNum, *D->ILok);
  return (((*(D->ILok))<(*(D->Nlok)))||((*(D->Nlok))==0));
}
