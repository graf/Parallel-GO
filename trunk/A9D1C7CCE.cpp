#include "tpodata.h"
int A9D1C7CCE(TPOData *D)
{
    if (myProcNum == 0) {
        for (int i = 1; i < *(D->NprlTec); i++) {
            MPI_Send(NULL, 0, MPI_INT, i+1 ,MPI_TAG_RUN, MPI_COMM_WORLD);
        }
    }
    *D->MaxPRL = 0;
    (*(D->Htmax)) = new LMAX;
    *(*D->Htmax) = D->HTMAX_p[myProcNum];
    (*(D->Htmax))->next = NULL;
    return 1;
}
