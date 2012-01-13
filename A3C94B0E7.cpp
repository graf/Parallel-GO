#include "tpodata.h"
extern "C" int addLM2(LMAXS *Hxs, XI *xf, FUNC *z, double *Eloc, int *Nmax, int *Kmax,LMAXS *Hend);
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
    if (fabs(z2_ - 1.0) <= 0.00001 && !D->maxFound) {
        D->maxFound = true;
        printf("%s\r\n", out);
//        addLM2(D->localMaxs, D->X, D->z2, D->Eloc, D->Nmax3, D->KlocMax, D->localMaxsHend);
    }
    return 1;
}
