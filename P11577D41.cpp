#include "tpodata.h"
int P11577D41(TPOData *D)
{
    return ((((*(D->NprlTec))<TOTAL_PROCS_NUMBER) && ((*(D->j1))<=(*(D->NprlTec)))) || (((*(D->NprlTec))==TOTAL_PROCS_NUMBER) && ((*(D->j1))<(*(D->NprlTec)))));
}
