#include "utype.h"
extern "C" int deform(XI* X,FUNC *Yc,MPAR *BB,int *Nfunc,double *Esimp);
int S5A6D0DC4(XI* X,FUNC *Yc,MPAR *BB,int *Nfunc,double *Esimp)
{
	return deform(X, Yc, BB, Nfunc, Esimp);
}
