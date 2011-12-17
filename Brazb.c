#include "utype.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int Brazb(QVAD2S *Hqva,QVAD2S *Hq2,SEGM *PRLp,int *NprlTec)
{

    (*Hq2)=(*Hqva);
    (*Hqva)=(*Hqva)->next;
    (*Hq2)->next=NULL;
    (*PRLp).MQVAD[(*NprlTec)]=(*Hq2);

    return(1);
}
