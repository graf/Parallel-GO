#include "tpodata.h"
#include "utils.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

extern "C" int addLM(LMAXS *Hxs, XI *xf, FUNC *z, double *Eloc, int *Nmax, int *Kmax);
extern "C" int addQVM(QVAD2S *simps, int *Nsimp,double *d2z,double *Str, double *Ksum,XI *x0,double *z,double *hx, FUNC *DelS,int *Lor,int *Hbd);

int addQVM(QVAD2S *simps, int Nsimp, double d2z,double Str, double Ksum,XI x0,double z,double hx, FUNC DelS, int Lor,int Hbd) {
    QVAD2 *simp, *H, *HP;
        XI X0;
        double R,L;
        int i;

    H=*simps;
    if ((simp = (QVAD2S)malloc(sizeof(QVAD2)))  == NULL) {
        printf("墠⠥   ࠧ饭   QVAD2\n");
        exit(8);
    }
    simp->Nsimp = Nsimp;
    simp->d2z   = d2z;
    simp->Str   = Str;
    for(i=0;i<DIMENSION;i++)
        (simp->x0)[i]=x0[i];
    simp->z   = z;
    simp->hx   = hx;
    simp->DelS   = DelS;
    simp->Ksum  = Ksum;
    simp->Loran= Lor;
    simp->Hbd= Hbd;
    simp->next = H;
    *simps = simp;
}

int AE0DB6BEB(TPOData *D)
{
    /*Waiting for process and collect data*/
    if (myProcNum == 0) {
        int maxPRL = (*D->PRLp).NF[0];
        int maxPRLP = 0;
        for (int i = 1; i < TOTAL_PROCS_NUMBER; i++) {
            if ((*D->PRLp).MQVAD[i] != NULL) {
                MPI_Recv(NULL, 0, MPI_INT, i+1, MPI_TAG_COMPLETED, MPI_COMM_WORLD, &status);

                //Получены данные от процессора, нужно разобрать эти данные
                (*D->PRLp).NF[i] = D->NF[i];

                if (maxPRL < (*D->PRLp).NF[i]) {
                    maxPRL = (*D->PRLp).NF[i];
                    maxPRLP = i;
                }
            }
        }

        ptrArrayOfQVADPL MQVADS = D->MQVAD_GB;
        ptrArrayOfLMAXPL HTMAXS = D->HTMAX_GB;
        ptrArrayOFFUNC zp_max = D->zp_max;
        for (int i = 1; i < TOTAL_PROCS_NUMBER; i++) {
            if ((*D->PRLp).MQVAD[i] == NULL)
                continue;

            //Разбор списка квадратов
            const long MQVAD_len = MQVADS[i].length;
            if (MQVAD_len > 0) {
                for (int j = 0; j < MQVAD_len-1; j++) {
                    QVAD2 q = MQVADS[i].list[j];
                    addQVM(&((*D->PRLp).MQVAD[i]), &(q.Nsimp),&(q.d2z), &(q.Str), &(q.Ksum), &(q.x0), &(q.z), &(q.hx), &(q.DelS), &(q.Loran), &(q.Hbd));
//                    addQVM(&((*D->PRLp).MQVAD[i]), q.Nsimp,q.d2z, q.Str, q.Ksum, q.x0, q.z, q.hx, q.DelS, q.Loran, q.Hbd);
                }
            } else
                (*D->PRLp).MQVAD[i] = NULL;
            //Разбор локальных областей притяжения
            const long HTMAX_len = HTMAXS[i].length;
            if (HTMAX_len > 0) {
                for (int j = 0; j < HTMAX_len-1; j++) {
                    LMAX p = HTMAXS[i].list[j];
                    addLM(D->HXMAX, &(p.xf0), &(p.fmax), D->Eloc, D->Nmax2, D->KlocMax);
                }
            }

            //максимум функции
            if (zp_max[i] > *D->zp1) {
                *D->zp1 = zp_max[i];
                printf("New maximum %g\r\n", *D->zp1);
            }
        }

        D->totalFuncCalls += maxPRL;
    } else {
        //Сбор списка квадратов
        QVADPL QVAD_result;
        QVAD_result.length = 0;
        QVAD2S head = (*D->PRLp).MQVAD[myProcNum];
        while (head != NULL && QVAD_result.length < QVADArray_LENGTH) {
            QVAD_result.list[QVAD_result.length++] = (*(head));
            head = head->next;
        }
        if (QVAD_result.length >= QVADArray_LENGTH)
            printf("Process %d: ### WARN ###: MQVAD_len OVER LENGTH %d\r\n", myProcNum, QVAD_result.length);
        (*D->PRLp).MQVAD[myProcNum] = NULL;
        D->MQVAD_GB[myProcNum] = QVAD_result;

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
        D->HTMAX_GB[myProcNum] = HTMAX_result;

        //МАксимум функции
        D->zp_max[myProcNum] = *D->zp1;
    }
    return 1;
}
