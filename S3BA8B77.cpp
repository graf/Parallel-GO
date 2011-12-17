#include "utype.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
extern "C" int addQVM(QVAD2S *simps, int *Nsimp,double *d2z,double *Str, double *Ksum,XI *x0,double *z,double *hx, FUNC *DelS,int *Lor,int *Hbd);
int S3BA8B77(QVAD2S *simps, int *Nsimp,double *d2z,double *Str, double *Ksum,XI *x0,double *z,double *hx, FUNC *DelS,int *Lor,int *Hbd)
{
	return addQVM(simps, Nsimp, d2z, Str, Ksum, x0, z, hx, DelS, Lor, Hbd);
}
