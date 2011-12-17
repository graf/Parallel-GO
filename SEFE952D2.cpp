#include "utype.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
extern "C" int BPfiLM(LMAXS *Hxs, XI *xf,double *Eloc,int *Krep);
int SEFE952D2(LMAXS *Hxs, XI *xf,double *Eloc,int *Krep)
{
	return BPfiLM(Hxs, xf, Eloc, Krep);
}
