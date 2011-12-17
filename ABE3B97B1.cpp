#include "tpodata.h"
int ABE3B97B1(TPOData *D)
{
    int i;
//    char buff[1024];
//    int offset = sprintf(buff, "Process %d: Start deform from fmax = %8g", myProcNum, (*(*(D->Htmax))).fmax);
    for (i=0;i<DIMENSION;i++) {
        (*(D->X))[i]=(*(*(D->Htmax))).xf0[i];
//        offset+=sprintf(buff+offset, "X[%d]=%8g ", i, (*(*(D->Htmax))).xf0[i]);
    }
//    printf("%s\r\n", buff);

    return 1;
}
