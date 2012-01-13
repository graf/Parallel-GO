#include "tpodata.h"
extern int BkvParU(LMAXS *HXMAX, QVAD2S *Hqva, double *Estron, double *lx, int *KlocMax, double *mmmax, int *NFUNC, MPAR *Akfun, FUNC *zp1, int *Nloc0, int *Reg, int *Nmax2);
int SB7A02AC0(LMAXS *HXMAX, QVAD2S *Hqva, double *Estron, double *lx, int *KlocMax, double *mmmax, int *NFUNC, MPAR *Akfun, FUNC *zp1, int *Nloc0, int *Reg, int *Nmax2)
{
	return BkvParU(HXMAX, Hqva, Estron, lx, KlocMax, mmmax, NFUNC, Akfun, zp1, Nloc0, Reg, Nmax2);
}
