#include "tpodata.h"
int A4C236239(TPOData *D)
{
    (*(D->wmax))=(*(D->w0))+(*(D->mmax))*(*(D->Diag))/2; //(*(D->wmax))=(*(D->w0))+(*(D->Lip))*(*(D->Str));
    return 1;
}
