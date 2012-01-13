#include "tpodata.h"
extern int SF8A061BB(QVAD2S *Hxs, QVAD2S *Hz);
int A19ACD2E9(TPOData *D)
{
//Соединение список начальных делений параллельных процессов
	QVAD2S *_Hxs = D->Hqva;
	QVAD2S *_Hz = D->Hq2;

	int result = SF8A061BB(_Hxs, _Hz);

	D->Hqva = _Hxs;
	D->Hq2 = _Hz;


	return result;
}