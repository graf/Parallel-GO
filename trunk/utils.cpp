#include "utils.h"
#include <sys/file.h>

MPAR2 Mpar_2_Mpar2(const MPAR &src) {
    MPAR2 result;
    result.GKLS_dim = src.GKLS_dim;
    result.N_fun = src.N_fun;
    result.tip = src.tip;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 6; j++)
            result.A[i*2+j] = src.A[i][j];
    return result;
}

MPAR Mpar2_2_Mpar(const MPAR2 &src) {
    MPAR result;
    result.GKLS_dim = src.GKLS_dim;
    result.N_fun = src.N_fun;
    result.tip = src.tip;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 6; j++)
            result.A[i][j] = src.A[i*2+j];
    return result;
}

void log2file(const char *msg)
{
    FILE *f = fopen("log.txt", "a+");
    fprintf(f, "Process %d: %s\r\n", myProcNum, msg);
    fclose(f);
}

void printf_QVAD2(QVAD2 q)
{
    char buff[1024];
    int offset = sprintf(buff, "Process %d: QVAD: Nsimp=%d d2z=%g Str=%g Ksum=%g z=%g hx=%g Dels=%g Loran=%d Hbd=%d", myProcNum, q.Nsimp, q.d2z, q.Str, q.Ksum, q.z, q.hx, q.DelS, q.Loran, q.Hbd);
    for (int i = 0; i < DIMENSION; i++)
        offset += sprintf(buff+offset, " x0[%d]=%g", i, q.x0[i]);
    printf("%s\r\n", buff);
}

void printf_LMAX(LMAX l)
{
    char buff[1024];
    int offset = sprintf(buff, "Process %d: LMAX: fLmax=%g fmax=%g Npri=%d", myProcNum, l.fLmax, l.fmax, l.Npri);
    for (int i = 0; i < DIMENSION; i++)
        offset += sprintf(buff+offset, " xf0[%d]=%g", i, l.xf0[i]);
    for (int i = 0; i < DIMENSION; i++)
        offset += sprintf(buff+offset, " xLm[%d]=%g", i, l.xLm[i]);
    printf("%s\r\n", buff);
}

void printf_QVAD2S(QVAD2S q)
{
    char buff[4096];
    int offset = sprintf(buff, "Process %d: {\r\n", myProcNum);
    int MQVAD_len=0;
    QVAD2S head = q;
    while (head != NULL) {
        QVAD2 q = (*(head));
        offset += sprintf(buff+offset, "\tQVAD: Nsimp=%d d2z=%g Str=%g Ksum=%g z=%g hx=%g Dels=%g Loran=%d Hbd=%d", q.Nsimp, q.d2z, q.Str, q.Ksum, q.z, q.hx, q.DelS, q.Loran, q.Hbd);
        for (int j = 0; j < DIMENSION; j++)
            offset += sprintf(buff+offset, " x0[%d]=%g", j, q.x0[j]);
        offset += sprintf(buff+offset, "\r\n");
        head = head->next;
        MQVAD_len++;
    }
    sprintf(buff+offset, "} length=%d", MQVAD_len);
    printf("%s\r\n", buff);
}

void printf_LMAXS(LMAXS l)
{
    char buff[4096];
    int offset = sprintf(buff, "Process %d: {\r\n", myProcNum);
    int LMAX_len=0;
    LMAXS head = l;
    while (head != NULL) {
        LMAX l = (*(head));
        offset += sprintf(buff+offset, "\tLMAX: fLmax=%g fmax=%g Npri=%d", l.fLmax, l.fmax, l.Npri);
        for (int j = 0; j < DIMENSION; j++)
            offset += sprintf(buff+offset, " xf0[%d]=%g", j, l.xf0[j]);
        for (int j = 0; j < DIMENSION; j++)
            offset += sprintf(buff+offset, " xLm[%d]=%g", j, l.xLm[j]);
        offset += sprintf(buff+offset, "\r\n");
        head = head->next;
        LMAX_len++;
    }
    sprintf(buff+offset, "} length=%d", LMAX_len);
    printf("%s\r\n", buff);
}

void printf_QVADPL(QVADPL qvadpl)
{
    char buff[4096];
    int offset = sprintf(buff, "Process %d: QVADPL.length=%d {\r\n", myProcNum, qvadpl.length);
    for (int i = 0; i < qvadpl.length; i++) {
        QVAD2 q = qvadpl.list[i];
        offset += sprintf(buff+offset, "\tQVAD: Nsimp=%d d2z=%g Str=%g Ksum=%g z=%g hx=%g Dels=%g Loran=%d Hbd=%d", q.Nsimp, q.d2z, q.Str, q.Ksum, q.z, q.hx, q.DelS, q.Loran, q.Hbd);
        for (int j = 0; j < DIMENSION; j++)
            offset += sprintf(buff+offset, " x0[%d]=%g", j, q.x0[j]);
        offset += sprintf(buff+offset, "\r\n");
    }
    sprintf(buff+offset, "}");
    printf("%s\r\n", buff);
}

void printf_LMAXPL(LMAXPL lmaxpl)
{
    char buff[4096];
    int offset = sprintf(buff, "Process %d: LMAXPL.length=%d {\r\n", myProcNum, lmaxpl.length);
    for (int i = 0; i < lmaxpl.length; i++) {
        LMAX l = lmaxpl.list[i];
        offset += sprintf(buff+offset, "\tLMAX: fLmax=%g fmax=%g Npri=%d", l.fLmax, l.fmax, l.Npri);
        for (int j = 0; j < DIMENSION; j++)
            offset += sprintf(buff+offset, " xf0[%d]=%g", j, l.xf0[j]);
        for (int j = 0; j < DIMENSION; j++)
            offset += sprintf(buff+offset, " xLm[%d]=%g", j, l.xLm[j]);
        offset += sprintf(buff+offset, "\r\n");
    }
    sprintf(buff+offset, "}");
    printf("%s\r\n", buff);
}
