#include "tpodata.h"
int A8BAF7ABB(TPOData *D)
{
    (*(D->Htmax)) = NULL;
    /*Waiting for process and collect data*/
    if (myProcNum == 0) {
        int maxPRL = *D->MaxPRL;
        int maxPRLP = 0;
        for (int i = 1; i < *(D->NprlTec); i++) {
            MPI_Recv(NULL, 0, MPI_INT, i+1, MPI_TAG_COMPLETED, MPI_COMM_WORLD, &status);

            //Получены данные от процессора, нужно разобрать эти данные
            (*D->PRLp).NF[i] = D->NF[i];
            if (maxPRL < (*D->PRLp).NF[i]) {
                maxPRL = (*D->PRLp).NF[i];
                maxPRLP = i;
            }
        }
        D->totalFuncCalls += maxPRL;
    } else {
        //Вернуть данные в общую память
        D->NF[myProcNum] = *(D->MaxPRL);
    }
    return 1;
}
