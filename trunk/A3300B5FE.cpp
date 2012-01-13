#include "tpodata.h"
extern int SC27C3EB4(LMAXS *Hxs, XI *xf, FUNC *z, double *Eloc, int *Nmax, int *Kmax, LMAXS *Hend);
int A3300B5FE(TPOData *D)
{
//Формарование в направлении убывания функции локальных областей поиска локальных максимумов
	LMAXS *_Hxs = D->HXMAX;
	XI *_xf = D->X;
	FUNC *_z = D->z2;
	double *_Eloc = D->Eloc;
	int *_Nmax = D->Nmax2;
	int *_Kmax = D->KlocMax;
	LMAXS *_Hend = D->Hend;

	int result = SC27C3EB4(_Hxs, _xf, _z, _Eloc, _Nmax, _Kmax, _Hend);

	D->HXMAX = _Hxs;
	D->X = _xf;
	D->z2 = _z;
	D->Eloc = _Eloc;
	D->Nmax2 = _Nmax;
	D->KlocMax = _Kmax;
	D->Hend = _Hend;


	return result;
}