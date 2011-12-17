#ifndef STYPE_H
#define STYPE_H

#include "mpi.h"

//Структура для общения с диспетчетом памяти
typedef struct {
    int   id;
    long  offset;
    long  count;
} MemoryPacket;

extern MPI_Datatype memoryPacketDatatype;

//Служебные типы и переменные
extern MPI_Status status;
extern int myProcNum, totalProc;

//Идентификаторы сообщений отсчитываются от этого значения
#define MPI_TAG_BASE             32740

//Идентификаторы сообщений запуска/остановки процесса
#define MPI_TAG_TERMINATE        MPI_TAG_BASE + 1
#define MPI_TAG_RUN              MPI_TAG_BASE + 2

//Идентификаторы сообщений менеджера памяти
#define MPI_TAG_GETDATA          MPI_TAG_BASE + 3
#define MPI_TAG_PUTDATA          MPI_TAG_BASE + 4
#define MPI_TAG_ACTUALDATA       MPI_TAG_BASE + 5
#define MPI_TAG_COMPLETED        MPI_TAG_BASE + 6


#endif
