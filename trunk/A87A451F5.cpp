#include "tpodata.h"
int A87A451F5(TPOData *D)
{
    (*(D->Ksum)) = (*(D->mi)) * (*(D->hx)) + ((*(D->w0))-(*(D->wold)))*((*(D->w0))-(*(D->wold)))/((*(D->mi))*(*(D->hx)));
    (*(D->Ksum)) = (*(D->Ksum)) + 2*((*(D->w0)) + (*(D->wold)));
    return 1;
}
