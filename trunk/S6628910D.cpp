#include "utype.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern "C" int Brazb(QVAD2S *Hqva,QVAD2S *Hq2,SEGM *PRLp,int *NprlTec);
int S6628910D(QVAD2S *Hqva,QVAD2S *Hq2,SEGM *PRLp,int *NprlTec)
{
	return Brazb(Hqva, Hq2, PRLp, NprlTec);
}
