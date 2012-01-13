#include "tpodata.h"
int A5BFABC49(TPOData *D)
{
    (*(D->Hbd))=1;
    (*(D->hx))=0.5;
    (*(D->Diag))=sqrt(16*(DIMENSION-1)+4)*(*(D->hx));
    (*(D->d2z))=DIMENSION-1;
    (*(D->w0))=(*(D->z2));
    return 1;
}
