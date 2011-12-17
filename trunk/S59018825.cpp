#include "utype.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
extern "C" int BPendLM(LMAXS *Hxs,int *Krep,int *Nmax);
int S59018825(LMAXS *Hxs,int *Krep,int *Nmax)
{
	return BPendLM(Hxs, Krep, Nmax);
}
