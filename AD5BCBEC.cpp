#include "tpodata.h"
extern int SBEC09D15(QVAD2S *simps);
int AD5BCBEC(TPOData *D)
{
//Удаление элемента из головы списка
	QVAD2S *_simps = D->Hq2;

	int result = SBEC09D15(_simps);

	D->Hq2 = _simps;


	return result;
}