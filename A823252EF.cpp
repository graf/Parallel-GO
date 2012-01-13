#include "tpodata.h"
extern int S3BA8B77(QVAD2S *simps, int *Nsimp, double *d2z, double *Str, double *Ksum, XI *x0, double *z, double *hx, FUNC *DelS, int *Lor, int *Hbd);
int A823252EF(TPOData *D)
{
//Формирование списка для паралльных процессов
	QVAD2S *_simps = D->Hq2;
	int *_Nsimp = D->Nsimp;
	double *_d2z = D->d2z;
	double *_Str = D->Diag;
	double *_Ksum = D->Ksum;
	XI *_x0 = D->X;
	double *_z = D->w0;
	double *_hx = D->hx;
	FUNC *_DelS = D->wold;
	int *_Lor = D->Lor;
	int *_Hbd = D->Hbd;

	int result = S3BA8B77(_simps, _Nsimp, _d2z, _Str, _Ksum, _x0, _z, _hx, _DelS, _Lor, _Hbd);

	D->Hq2 = _simps;
	D->Nsimp = _Nsimp;
	D->d2z = _d2z;
	D->Diag = _Str;
	D->Ksum = _Ksum;
	D->X = _x0;
	D->w0 = _z;
	D->hx = _hx;
	D->wold = _DelS;
	D->Lor = _Lor;
	D->Hbd = _Hbd;


	return result;
}
