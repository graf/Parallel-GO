#include "tpodata.h"
#include "utils.h"
int AA72B0A89(TPOData *D)
{
    /*Prepare data*/
    if (myProcNum == 0) {
        D->Estron_p = *D->Estron;
        D->lx_p = *D->lx;
        D->KlocMax_p = *D->KlocMax;
        D->NFUNC_p = *D->NFUNC;
        D->Nlok_p = *D->Nlok;
        D->mmax_p = *D->mmax;
        D->zp1_p = *D->zp1;
        D->Akfun_p = Mpar_2_Mpar2(*D->Akfun);

        for (int i = 1; i < TOTAL_PROCS_NUMBER; i++) {
            if ((*D->PRLp).MQVAD[i] != NULL) {
                //Закинем данны в общую память
                D->MQVAD[i] = *((*D->PRLp).MQVAD[i]);
                D->NF[i] = (*D->PRLp).NF[i];
                MPI_Send(NULL, 0, MPI_INT, i+1 ,MPI_TAG_RUN, MPI_COMM_WORLD);
            }
        }
    } else {
        //Считаем значения из общей памяти в локальные переменные
        (*D->PRLp).MQVAD[myProcNum] = new QVAD2;
        *(*D->PRLp).MQVAD[myProcNum] = D->MQVAD[myProcNum];
        (*D->PRLp).MQVAD[myProcNum]->next = NULL;
        (*D->PRLp).NF[myProcNum] = D->NF[myProcNum];
        *D->Estron = D->Estron_p;
        *D->lx = D->lx_p;
        *D->KlocMax = D->KlocMax_p;
        *D->NFUNC = D->NFUNC_p;
        *D->Nlok = D->Nlok_p;
        *D->mmax = D->mmax_p;
        *D->zp1 = D->zp1_p;
        *D->Akfun = Mpar2_2_Mpar(D->Akfun_p);
    }
    return 1;
}