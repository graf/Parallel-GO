#include "tpodata.h"
extern "C" int Zfun3(XI *X,FUNC *z,int *NFUNC,MPAR *Af);
int A37CA1EE6(TPOData *D)
{
    Zfun3(&((*(D->X))), &((*(D->z2))), &((*(D->NFUNC))), &((*(D->Akfun))));
    return 1;
}
