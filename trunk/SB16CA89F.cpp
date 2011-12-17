#include "utype.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "gkls.h"
#include "rnd_gen.h"
extern "C" int GKLS_GR(MPAR *Akfun);
int SB16CA89F(MPAR *Akfun)
{
	return GKLS_GR(Akfun);
}
