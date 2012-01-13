#include "tpodata.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int AC474C1C6(TPOData *D)
{
    (*(D->Htmax))=(*(D->HXMAX));
    (*(D->HXMAX))=(*(D->HXMAX))->next;
    (*(D->Htmax))->next=NULL;
    D->HTMAX_p[(*D->NprlTec)]=*((*(D->Htmax)));
    free((*(D->Htmax)));
    return 1;
}
