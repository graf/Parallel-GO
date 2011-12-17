#include "utype.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int BreadH(QVAD2S *Hqva, XI *X0, double *hx, double *d2z, double *w0, double *Str, int *Lor, int *j6, FUNC *wold, int *Hbd)
{
    int i;
    for(i=0;i<DIMENSION;i++)
        (*X0)[i]=((*Hqva)->x0)[i];
    (*hx)=(*Hqva)->hx;
    (*d2z)=(*Hqva)->d2z;
    (*w0)=(*Hqva)->z;
    (*Str)=(*Hqva)->Str;
    (*Lor)=(*Hqva)->Loran;
    (*j6)=(*Hqva)->Nsimp;
    (*wold)=(*Hqva)->DelS;
    (*Hbd)=(*Hqva)->Hbd;
    return(1);
}
