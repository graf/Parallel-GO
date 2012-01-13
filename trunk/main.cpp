#include "tpodata.h"
#include "memman.h"
#include "unistd.h"
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include "utils.h"
#include "profiling.h"

extern int f_count;

void register_MPI_USER_TYPE_QVAD2() {
    int          len[12] = { 1, 1, 1, 1, DIMENSION, 1, 1, 1, 1, 1, 1, 1 };
    MPI_Aint     pos[12] = { offsetof(QVAD2,Nsimp),
                             offsetof(QVAD2,d2z),
                             offsetof(QVAD2,Str),
                             offsetof(QVAD2,Ksum),
                             offsetof(QVAD2,x0),
                             offsetof(QVAD2,z),
                             offsetof(QVAD2,hx),
                             offsetof(QVAD2,DelS),
                             offsetof(QVAD2,Loran),
                             offsetof(QVAD2,Hbd),
                             offsetof(QVAD2,next),
                             sizeof(QVAD2) };
    MPI_Datatype typ[12] = { MPI_INT, MPI_DOUBLE, MPI_DOUBLE, MPI_DOUBLE, MPI_USER_TYPE_XI_ONE_ELEMENT, MPI_DOUBLE, MPI_DOUBLE, MPI_USER_TYPE_FUNC, MPI_INT, MPI_INT, MPI_INT, MPI_UB };

    MPI_Type_struct( 12, len, pos, typ, &MPI_USER_TYPE_QVAD2);
    MPI_Type_commit( &MPI_USER_TYPE_QVAD2 );
}

void register_MPI_USER_TYPE_LMAX() {
    int          len[8] = { DIMENSION, 1, 1, 1, DIMENSION, 1, 1, 1};
    MPI_Aint     pos[8] = { offsetof(LMAX,xf0),
                            offsetof(LMAX,fmax),
                            offsetof(LMAX,Npri),
                            offsetof(LMAX,fLmax),
                            offsetof(LMAX,xLm),
                            offsetof(LMAX,next),
                            offsetof(LMAX,prev),
                            sizeof(LMAX) };
    MPI_Datatype typ[8] = { MPI_USER_TYPE_XI_ONE_ELEMENT, MPI_USER_TYPE_FUNC, MPI_INT, MPI_USER_TYPE_FUNC, MPI_USER_TYPE_XI_ONE_ELEMENT, MPI_INT, MPI_INT, MPI_UB };

    MPI_Type_struct( 8, len, pos, typ, &MPI_USER_TYPE_LMAX);
    MPI_Type_commit( &MPI_USER_TYPE_LMAX );
}

void register_MPI_USER_TYPE_MPAR2() {
    int          len[5] = { 12, 1, 1, 1, 1 };
    MPI_Aint     pos[5] = { offsetof(MPAR2,A),
                            offsetof(MPAR2,GKLS_dim),
                            offsetof(MPAR2,tip),
                            offsetof(MPAR2,N_fun),
                            sizeof(MPAR2) };
    MPI_Datatype typ[5] = { MPI_DOUBLE, MPI_INT, MPI_INT, MPI_INT, MPI_UB };

    MPI_Type_struct( 5, len, pos, typ, &MPI_USER_TYPE_MPAR2);
    MPI_Type_commit( &MPI_USER_TYPE_MPAR2 );
}

void register_MPI_USER_TYPE_QVADPL() {
    int          len[3] = { QVADArray_LENGTH, 1, 1 };
    MPI_Aint     pos[3] = { offsetof(QVADPL,list),
                            offsetof(QVADPL,length),
                            sizeof(QVADPL) };
    MPI_Datatype typ[3] = { MPI_USER_TYPE_QVAD2, MPI_INT, MPI_UB };

    MPI_Type_struct( 3, len, pos, typ, &MPI_USER_TYPE_QVADPL);
    MPI_Type_commit( &MPI_USER_TYPE_QVADPL );
}

void register_MPI_USER_TYPE_LMAXPL() {
    int          len[3] = { ArrayOfLMAX_LENGTH, 1, 1 };
    MPI_Aint     pos[3] = { offsetof(LMAXPL,list),
                            offsetof(LMAXPL,length),
                            sizeof(LMAXPL) };
    MPI_Datatype typ[3] = { MPI_USER_TYPE_LMAX, MPI_INT, MPI_UB };

    MPI_Type_struct( 3, len, pos, typ, &MPI_USER_TYPE_LMAXPL);
    MPI_Type_commit( &MPI_USER_TYPE_LMAXPL );
}

int GED210F93(TPOData *D);
int G15C01624(TPOData *D);
int GCF2DCA96(TPOData *D);
int G65DF6ACB(TPOData *D);
int GCD1DC2A0(TPOData *D);
int A483E1434(TPOData *D);
int A76101524(TPOData *D);

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    //Для общения с менеждером памяти
    int          len[4] = { 1, 1, 1, 1 };
    MPI_Aint     pos[4] = { offsetof(MemoryPacket,id), offsetof(MemoryPacket,offset),
                            offsetof(MemoryPacket,count), sizeof(MemoryPacket) };
    MPI_Datatype typ[4] = { MPI_INT, MPI_LONG, MPI_LONG, MPI_UB };

    MPI_Type_struct( 4, len, pos, typ, &memoryPacketDatatype );
    MPI_Type_commit( &memoryPacketDatatype );

    register_MPI_USER_TYPE_QVAD2();
    register_MPI_USER_TYPE_MPAR2();
    register_MPI_USER_TYPE_LMAX();
    register_MPI_USER_TYPE_QVADPL();
    register_MPI_USER_TYPE_LMAXPL();
    
    double avgWorkTime = 0;
    double avgFuncCalls = 0;
    double avgDataTransTime = 0;

    int counter = 0;
    for (int GKLtip = GKLS_TYPE; GKLtip <= GKLS_TYPE; GKLtip++)
        for (int N_fun = GKLS_FUN; N_fun <= GKLS_FUN; N_fun+=10)  {
            double start = MPI_Wtime();
            counter++;

            double work_time = 0;
            f_count = 0;

            MPI_Comm_rank(MPI_COMM_WORLD, &myProcNum);
            MPI_Comm_size(MPI_COMM_WORLD, &totalProc);

            TPOData D(myProcNum);

            *D.GKLtip = GKLtip;
            *D.N_fun = N_fun;

            MPI_Barrier(MPI_COMM_WORLD);

            //Перейдем в новые координаты, теперь никто не знает про менеджер памяти.
            //но не забываем про него во всех операциях пересылки !!!!!
            myProcNum--;
            totalProc--;

            //Инициализация GKLS
            A483E1434(&D);
            A76101524(&D);

            if (myProcNum == -1)
                printf("=============================BEGIN EXPERIMENT=============================;\r\n");

            //Запускаем диспетчер памяти
            if (myProcNum == -1) {
                work_time += MPI_Wtime();
                memman(&D);
                work_time -= MPI_Wtime();
            }

            //Запускаем масте-ветвь
            if (myProcNum == 0) {
                work_time += MPI_Wtime();
                GCD1DC2A0(&D);
                //Мы больше не нуждаемся в параллельных процессорах
                for (int i = 1; i < totalProc; i++) {
                    MPI_Send(NULL, 0, MPI_INT, i+1, MPI_TAG_TERMINATE, MPI_COMM_WORLD);
                }
                //выключаем менеджер памяти
                MPI_Send(NULL, 0, MPI_INT, 0, MPI_TAG_TERMINATE, MPI_COMM_WORLD);
                work_time -= MPI_Wtime();
                printf("total func calls = %d\r\n", D.totalFuncCalls);
            }

            //Запускаем параллельные ветки, которые будут ждать команду на запуск
            //Данные подготовливаются и команда на запуск отправляется из актора AA72B0A89
            //А ждать завершения он будет тут AE0DB6BEB
            //Параллельный граф описан в GCF2DCA96.
            if (myProcNum > 0) {
                bool Terminate = false;
                while (!Terminate) {
                    int res;
                    MPI_Recv(&res, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
                    if (status.MPI_TAG != MPI_TAG_TERMINATE) {
                        if ( status.MPI_TAG == MPI_TAG_RUN ) {
                            work_time += MPI_Wtime();
                            GCF2DCA96(&D);
                            //Отправлям мастер-ветви сообщение о завершении
                            MPI_Send(NULL, 0, MPI_INT, 1, MPI_TAG_COMPLETED, MPI_COMM_WORLD);
                            work_time -= MPI_Wtime();
                        }
                    } else {
                        Terminate = true;
                    }
                }
            }

            //Второй параллельный кусок
            if (myProcNum > 0) {
                bool Terminate = false;
                while (!Terminate) {
                    int res;
                    MPI_Recv(&res, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
                    if (status.MPI_TAG != MPI_TAG_TERMINATE) {
                        if ( status.MPI_TAG == MPI_TAG_RUN ) {
                            work_time += MPI_Wtime();
                            G65DF6ACB(&D);
                            //Отправлям мастер-ветви сообщение о завершении
                            MPI_Send(NULL, 0, MPI_INT, 1, MPI_TAG_COMPLETED, MPI_COMM_WORLD);
                            work_time -= MPI_Wtime();
                        }
                    } else {
                        Terminate = true;
                    }
                }
            }

            double finish = MPI_Wtime();
            if (myProcNum == -1) {
                printf("GKLS_func; %d\r\n", N_fun);
                printf("GKLS_type; %d\r\n", GKLtip);
                printf("Process; Total time; Work time; Data trans time; Func calls;\r\n");
            }
            MPI_Barrier(MPI_COMM_WORLD);

            //Пишем отчет
            printf("%d; %g; %g; %g; %d;\r\n", myProcNum, finish-start, fabs(work_time), D.totalDataOperationsTime, f_count);

            //Дожидаемся что все-все процессы дошли до этого места.
            //Дальше необходимо выполнить все операции одновременно всеми процессами.
            MPI_Barrier(MPI_COMM_WORLD);

            if (myProcNum == -1)
                printf("==========================================================================;\r\n\r\n\r\n\r\n");

#ifdef PROFILING
            if (myProcNum == -1)
                printf("===============================PROFILING==================================;\r\n");
            MPI_Barrier(MPI_COMM_WORLD);
            printf_profile();
            MPI_Barrier(MPI_COMM_WORLD);
            if (myProcNum == -1)
                printf("==========================================================================;\r\n\r\n\r\n\r\n");
#endif

            avgWorkTime += fabs(work_time);
            avgFuncCalls += f_count;
            avgDataTransTime += D.totalDataOperationsTime;
        }

    if (myProcNum == -1) {
        printf("==============================SUMMARY (AVG)===============================\r\n");
        printf("TOTAL_PROCS_NUMBER; %d\r\n", TOTAL_PROCS_NUMBER);
        printf("DIMENSION; %d\r\n", DIMENSION);
        printf("SLOW_FACTOR; %d\r\n", SLOW_FACTOR);
        printf("KlocMax; %d\r\n", KLOCMAX);
        printf("Nlok; %d\r\n", NLOC);
        printf("Nloc0; %d\r\n", TOTAL_PROCS_NUMBER-1);
        printf("lx; %g\r\n", LX);
        printf("Eloc; %g\r\n", ELOC);
        printf("Process; Work time; Data trans time; Func calls;\r\n");
    }

    MPI_Barrier(MPI_COMM_WORLD);
    printf("%d; %g; %g; %g;\r\n", myProcNum, avgWorkTime/1.0/counter, avgDataTransTime/1.0/counter, avgFuncCalls/1.0/counter);
    
    //Освобождаем типы
    MPI_Type_free(&memoryPacketDatatype);
    MPI_Type_free(&MPI_USER_TYPE_QVADPL);
    MPI_Type_free(&MPI_USER_TYPE_LMAXPL);
    MPI_Type_free(&MPI_USER_TYPE_MPAR2);
    MPI_Type_free(&MPI_USER_TYPE_QVAD2);  
    MPI_Type_free(&MPI_USER_TYPE_LMAX);
    
    

    MPI_Finalize();
    
    return 0;
}
