#include "tpodata.h"
int A3C94B0E7(TPOData *D)
{
    FUNC z2_ = (*(D->z2));
    int i;
    char out[1024];
    int offset = sprintf(out, "Process %d: %g;\t%g;\tX=; ",myProcNum, (*(D->Akfun)).A[0][4],z2_);
    *D->MaxPRL += (*(D->Akfun)).A[0][4];
    (*(D->Akfun)).A[0][4]=0;
    for(i=0;i<DIMENSION;i++)
        offset += sprintf(out + offset, " %8g;",(*(D->X))[i]);
    if (z2_ > 0.0)
        printf("%s\r\n", out);
    return 1;
}
