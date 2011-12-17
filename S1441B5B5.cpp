#include "utype.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern "C" int BreadH(QVAD2S *Hqva, XI *X0, double *hx, double *d2z, double *w0, double *Str, int *Lor, int *j6, FUNC *wold, int *Hbd);
int S1441B5B5(QVAD2S *Hqva, XI *X0, double *hx, double *d2z, double *w0, double *Str, int *Lor, int *j6, FUNC *wold, int *Hbd)
{
    return BreadH(Hqva, X0, hx, d2z, w0, Str, Lor, j6, wold, Hbd);
}
