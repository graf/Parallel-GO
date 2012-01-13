#ifndef UTYPE_H
#define UTYPE_H

#define PARALLEL
#define PROFILING

#ifdef PARALLEL
#include <mpi.h>
#include "stype.h"
#endif

//Часто включаемые файлы
#include <stdio.h>
#include <strings.h>
#include <memory.h>
#include <math.h>

#define GKLS_TYPE 3
#define GKLS_FUN 1
#define KLOCMAX 9999
#define NLOC 0
#define LX 0.30
#define ELOC 0.1
#define SLOW_FACTOR 0

#define DIMENSION 7
#define TOTAL_PROCS_NUMBER 2

#define MAXF 60000 //600
#define GRAN 6619
#define DSIMP  0.005
#define NGL_ 20

//Пользовательские типы
typedef double FUNC;
typedef double XI[DIMENSION];
typedef double XIF[MAXF][2*DIMENSION];
typedef int(*ZFUNC)(double *,double *,FUNC *);

typedef struct {
    double A[2][6];
    int GKLS_dim;
    int tip;
    int N_fun;
} MPAR;

typedef struct {
    double A[12];
    int GKLS_dim;
    int tip;
    int N_fun;
} MPAR2;

typedef struct LM {
    XI  xf0;
    FUNC fmax;
    int Npri;
    FUNC fLmax;
    XI  xLm;
    struct LM *next;
    struct LM *prev;
} LMAX;

typedef struct LQV {
    int Nsimp;
    double d2z;
    double Str;
    double Ksum;
    XI  x0;
    double z;
    double hx;
    FUNC DelS;
    int Loran;
    int Hbd;
    struct LQV *next;
} QVAD2;


typedef LMAX* LMAXS;
typedef QVAD2* QVAD2S;

typedef struct {
    QVAD2S MQVAD[TOTAL_PROCS_NUMBER];
    long NF[TOTAL_PROCS_NUMBER];
} SEGM;

extern MPI_Datatype MPI_USER_TYPE_QVAD2;
extern MPI_Datatype MPI_USER_TYPE_MPAR2;
extern MPI_Datatype MPI_USER_TYPE_LMAX;
extern MPI_Datatype MPI_USER_TYPE_QVADPL;
extern MPI_Datatype MPI_USER_TYPE_LMAXPL;

#define MPI_USER_TYPE_XI_ONE_ELEMENT MPI_DOUBLE
#define MPI_USER_TYPE_FUNC MPI_DOUBLE
#define MPI_USER_TYPE_ARRAYOFDOUBLE MPI_DOUBLE
#define MPI_USER_TYPE_ARRAYOFLONG MPI_LONG
#define MPI_USER_TYPE_ARRAYOFFUNC MPI_USER_TYPE_FUNC
#define MPI_USER_TYPE_QVADARRAY MPI_USER_TYPE_QVAD2
#define MPI_USER_TYPE_ARRAYOFQVADPL MPI_USER_TYPE_QVADPL
#define MPI_USER_TYPE_ARRAYOFLMAXPL MPI_USER_TYPE_LMAXPL

#define MAX_LIST_ARRAY_LENGTH 10000

#define QVADArray_LENGTH MAX_LIST_ARRAY_LENGTH
typedef QVAD2 QVADArray[QVADArray_LENGTH];
typedef QVAD2* ptrQVADArray;

typedef struct {
    QVADArray list;
    int length;
} QVADPL;

//Массив для хранения списков квадратов в глобальной памяти
//PL = parallel list
#define ArrayOfQVADPL_LENGTH TOTAL_PROCS_NUMBER
typedef QVADPL ArrayOfQVADPL[ArrayOfQVADPL_LENGTH];
typedef QVADPL* ptrArrayOfQVADPL;

#define ArrayOfLong_LENGTH TOTAL_PROCS_NUMBER
typedef long ArrayOfLong[ArrayOfLong_LENGTH];
typedef long* ptrArrayOfLong;

//Массив для хранения списка квадратов в каждом процессе
#define ArrayOfLMAX_LENGTH MAX_LIST_ARRAY_LENGTH
typedef LMAX ArrayOfLMAX[ArrayOfLMAX_LENGTH];
typedef LMAX* ptrArrayOfLMAX;

typedef struct {
    ArrayOfLMAX list;
    int length;
} LMAXPL;

#define ArrayOfLMAXPL_LENGTH TOTAL_PROCS_NUMBER
typedef LMAXPL ArrayOfLMAXPL[ArrayOfLMAXPL_LENGTH];
typedef LMAXPL* ptrArrayOfLMAXPL;

#define ArrayOFFUNC_LENGTH TOTAL_PROCS_NUMBER
typedef FUNC ArrayOFFUNC[ArrayOFFUNC_LENGTH];
typedef FUNC* ptrArrayOFFUNC;

#define ArrayOfDouble_LENGTH TOTAL_PROCS_NUMBER
typedef double ArrayOfDouble[ArrayOfDouble_LENGTH];
typedef double* ptrArrayOfDouble;

#endif
