#include "tpodata.h"
int A3BE6A80A(TPOData *D)
{
    double M;
    M = ((*(D->w0)) - (*(D->wold))) / (*(D->hx));
    M = fabs(M);
    if (M > (*(D->mmax))) {
        (*(D->mmax)) = M;
        (*(D->Flif))=1;
    }
    (*(D->mi)) = (*(D->mmax)) * (*(D->r));
    (*(D->d2z)) = (*(D->iNX));
    return 1;
}
