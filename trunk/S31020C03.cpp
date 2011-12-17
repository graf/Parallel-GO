#include "utype.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
extern "C" int Potbrak(XIF *Z,XI *X0,int *NmaxF,double *lx,double *Kob);
int S31020C03(XIF *Z,XI *X0,int *NmaxF,double *lx,double *Kob)
{
	return Potbrak(Z, X0, NmaxF, lx, Kob);
}
