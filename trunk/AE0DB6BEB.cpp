#include "tpodata.h"
#include "utils.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

extern "C" int addLM2(LMAXS *Hxs, XI *xf, FUNC *z, double *Eloc, int *Nmax, int *Kmax,LMAXS *Hend);
extern "C" int addQVM(QVAD2S *simps, int *Nsimp,double *d2z,double *Str, double *Ksum,XI *x0,double *z,double *hx, FUNC *DelS,int *Lor,int *Hbd);

#ifdef PROFILING
double AE0DB6BEB_time = 0;
#endif

int AE0DB6BEB(TPOData *D)
{
    /*Waiting for process and collect data*/
#ifdef PROFILING
    AE0DB6BEB_time -= MPI_Wtime();
#endif
    if (myProcNum == 0) {
        int maxPRL = (*D->PRLp).NF[0];
        for (int i = 1; i < TOTAL_PROCS_NUMBER; i++) {
            if ((*D->PRLp).MQVAD[i] != NULL) {
                MPI_Recv(NULL, 0, MPI_INT, i+1, MPI_TAG_COMPLETED, MPI_COMM_WORLD, &status);

                //Получены данные от процессора, нужно разобрать эти данные
                (*D->PRLp).NF[i] = D->NF[i];

                if (maxPRL < (*D->PRLp).NF[i])
                    maxPRL = (*D->PRLp).NF[i];
            }
        }


        ptrArrayOfLMAXPL HTMAXS = D->HTMAX_GB;
        ptrArrayOFFUNC zp_max = D->zp_max;
        ptrArrayOfDouble mmax_max = D->mmax_max;
        double collect_time = -MPI_Wtime();
        for (int i = 1; i < TOTAL_PROCS_NUMBER; i++) {
            if ((*D->PRLp).MQVAD[i] == NULL)
                continue;

            //Разбор локальных областей притяжения
            const long HTMAX_len = HTMAXS[i].length;
            if (HTMAX_len > 0) {
                for (int j = 0; j < HTMAX_len-1; j++) {
                    LMAX p = HTMAXS[i].list[j];
                    addLM2(D->HXMAX, &(p.xf0), &(p.fmax), D->Eloc, D->Nmax2, D->KlocMax, D->Hend);
                }
            }

            //максимум функции
            if (zp_max[i] > *D->zp1)
                *D->zp1 = zp_max[i];

            //максимум функции
            if (mmax_max[i] > *D->mmax)
                *D->mmax = mmax_max[i];
        }
        collect_time += MPI_Wtime();
        printf("collect data about %g sec\r\n", collect_time);

        D->totalFuncCalls += maxPRL;
    } else {
        //Сбор локальных точек притяжения
        LMAXPL HTMAX_result;
        HTMAX_result.length = 0;
        LMAXS head2 = (*D->HXMAX);
        while (head2 != NULL && HTMAX_result.length < ArrayOfLMAX_LENGTH) {
            HTMAX_result.list[HTMAX_result.length++] = (*(head2));
            head2 = head2->next;
        }
        if (HTMAX_result.length >= ArrayOfLMAX_LENGTH)
            printf("Process %d: ### WARN ###: HTMAX_len OVER LENGTH %d\r\n", myProcNum, HTMAX_result.length);
        (*D->HXMAX) = NULL;
        (*D->Hend) = NULL;
        D->HTMAX_GB[myProcNum] = HTMAX_result;

        //МАксимум функции
        D->zp_max[myProcNum] = *D->zp1;
        D->mmax_max[myProcNum] = *D->mmax;
    }

    printf("Process %d: func cals at GO %d\r\n", myProcNum, (*D->PRLp).NF[myProcNum]);
#ifdef PROFILING
    AE0DB6BEB_time += MPI_Wtime();
#endif

    return 1;
}
