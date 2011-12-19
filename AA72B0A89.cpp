#include "tpodata.h"
#include "utils.h"

extern "C" int addQVM(QVAD2S *simps, int *Nsimp,double *d2z,double *Str, double *Ksum,XI *x0,double *z,double *hx, FUNC *DelS,int *Lor,int *Hbd);
int AA72B0A89(TPOData *D)
{
    /*Prepare data*/
    if (myProcNum == 0) {
        //Закинем данны в общую память
        D->mmax_p = *D->mmax;
        D->zp1_p = *D->zp1;
        D->Akfun_p = Mpar_2_Mpar2(*D->Akfun);

        QVADArray MQVAD;
        for (int i = 1; i < TOTAL_PROCS_NUMBER; i++) {
            if ((*D->PRLp).MQVAD[i] != NULL) {
                MQVAD[i] = *((*D->PRLp).MQVAD[i]);
                D->NF[i] = (*D->PRLp).NF[i];
            }
        }

        D->MQVAD = MQVAD;

        for (int i = 1; i < TOTAL_PROCS_NUMBER; i++) {
            if ((*D->PRLp).MQVAD[i] != NULL) {
                MPI_Send(NULL, 0, MPI_INT, i+1 ,MPI_TAG_RUN, MPI_COMM_WORLD);
            }
        }
    } else {
        //Считаем значения из общей памяти в локальные переменные
        QVAD2 q = D->MQVAD[myProcNum];
        (*D->PRLp).MQVAD[myProcNum] = new QVAD2();
        (*(*D->PRLp).MQVAD[myProcNum]) = q;
        (*D->PRLp).MQVAD[myProcNum]->next = NULL;
        (*D->PRLp).NF[myProcNum] = D->NF[myProcNum];
        *D->mmax = D->mmax_p;
        *D->zp1 = D->zp1_p;
        *D->Akfun = Mpar2_2_Mpar(D->Akfun_p);
    }
    return 1;
}
