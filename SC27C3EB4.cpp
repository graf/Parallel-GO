#include "utype.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
extern "C" int addLM2(LMAXS *Hxs, XI *xf, FUNC *z, double *Eloc, int *Nmax, int *Kmax,LMAXS *Hend);
int SC27C3EB4(LMAXS *Hxs, XI *xf, FUNC *z, double *Eloc, int *Nmax, int *Kmax,LMAXS *Hend)
{
	return addLM2(Hxs, xf, z, Eloc, Nmax, Kmax, Hend);
}
