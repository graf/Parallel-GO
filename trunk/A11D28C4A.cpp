#include "tpodata.h"
#include "utils.h"
int A11D28C4A(TPOData *D)
{
    //Первый этап закончился. Процессы не должны больше ничего ждать.
    for (int i = 1; i < totalProc; i++) {
        MPI_Send(NULL, 0, MPI_INT, i+1, MPI_TAG_TERMINATE, MPI_COMM_WORLD);
    }
//    if (myProcNum == 0)
//        printf_LMAXS(*(D->HXMAX));
    return 1;
}
