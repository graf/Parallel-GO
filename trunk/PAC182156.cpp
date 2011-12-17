#include "tpodata.h"
extern int SEFE952D2(LMAXS *Hxs, XI *xf, double *Eloc, int *Krep);
int PAC182156(TPOData *D)
{
	LMAXS *_Hxs = D->HXMAX;
	XI *_xf = D->X;
	double *_Eloc = D->Eloc;
	int *_Krep = D->Krep;

	int result = SEFE952D2(_Hxs, _xf, _Eloc, _Krep);



	return result;
}