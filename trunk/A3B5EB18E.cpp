#include "tpodata.h"
extern int SB7A02AC0(LMAXS *HXMAX, QVAD2S *Hqva, double *Estron, double *lx, int *KlocMax, double *mmmax, int *NFUNC, MPAR *Akfun, FUNC *zp1, int *Nloc0, int *Reg, int *Nmax2);
int A3B5EB18E(TPOData *D)
{
//Формирование начального списка элементов для организации параллельных вычислений
	LMAXS *_HXMAX = D->HXMAX;
	QVAD2S *_Hqva = D->Hqva;
	double *_Estron = D->Eloc;
	double *_lx = D->lx;
	int *_KlocMax = D->KlocMax;
	double *_mmmax = D->mmax;
	int *_NFUNC = D->NFUNC;
	MPAR *_Akfun = D->Akfun;
	FUNC *_zp1 = D->zp1;
    int *_Nlok = D->Nloc0;
	int *_Reg = D->Reg;
	int *_Nmax2 = D->Nmax2;

    int result = SB7A02AC0(_HXMAX, _Hqva, _Estron, _lx, _KlocMax, _mmmax, _NFUNC, _Akfun, _zp1, _Nlok, _Reg, _Nmax2);

	D->HXMAX = _HXMAX;
	D->Hqva = _Hqva;
	D->Eloc = _Estron;
	D->lx = _lx;
	D->KlocMax = _KlocMax;
	D->mmax = _mmmax;
	D->NFUNC = _NFUNC;
	D->Akfun = _Akfun;
	D->zp1 = _zp1;
    D->Nloc0 = _Nlok;
	D->Reg = _Reg;
	D->Nmax2 = _Nmax2;


	return result;
}
