#include "utype.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
extern "C" int addLM(LMAXS *Hxs, XI *xf, FUNC *z, double *Eloc, int *Nmax, int *Kmax);
int SACD3CE29(LMAXS *Hxs, XI *xf, FUNC *z, double *Eloc, int *Nmax, int *Kmax)
{
        return addLM(Hxs, xf, z, Eloc, Nmax, Kmax);
}
