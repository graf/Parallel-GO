#include "utype.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
extern "C" int sumsimp(QVAD2S *Hxs, QVAD2S *Hz);
int SF8A061BB(QVAD2S *Hxs, QVAD2S *Hz)
{
	return sumsimp(Hxs, Hz);
}
