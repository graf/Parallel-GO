#include "tpodata.h"
int A3BE6A80A(TPOData *D)
{
    double M;
    M = ((*(D->w0)) - (*(D->wold))) / (*(D->hx));
    if (*(D->hx) == 0) {
        printf("Processor %d: hx = 0\r\n", myProcNum);
    }
    M = fabs(M);
    if (M > (*(D->mmax))) {
        (*(D->mmax)) = M;
        (*(D->Flif))=1;
//        printf("New mmax %g from process %d\r\n", *D->mmax, myProcNum);
    }
    (*(D->mi)) = (*(D->mmax)) * (*(D->r));
    (*(D->d2z)) = (*(D->iNX));
    return 1;
}
