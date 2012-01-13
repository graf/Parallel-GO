#include "utype.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int sumsimp(QVAD2S *Hxs, QVAD2S *Hz)
{ 
    QVAD2 *H, *HP;

    if(((*Hxs)!=NULL)&&((*Hz)!=NULL))
    {
        H=(*Hxs);
        while(H!=NULL)
        {
            HP=H;
            H=H->next;
        }
        HP->next=(*Hz);
        (*Hz)=NULL;
        return 1;
    }
    if(((*Hxs)==NULL)&&((*Hz)!=NULL))
    {
        (*Hxs)=(*Hz);
        (*Hz)=NULL;
        return 1;
    }
    if(((*Hxs)!=NULL)&&((*Hz)==NULL))
        return 1;
    if(((*Hxs)==NULL)&&((*Hz)==NULL))
        return 1;

}
