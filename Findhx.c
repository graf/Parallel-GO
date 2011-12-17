#include "utype.h"
//#include <alloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int Findhx(QVAD2S *simps,double *hxMax)
{
    QVAD2 *simp, *H;
    H=*simps;
    //(*hxMax)=0;

    if (*simps == NULL) return 1;

    while (H != NULL)
    {
        if (H->hx > (*hxMax))
            (*hxMax)= H->hx;
        H=H->next;
    }
    return 1;
}
/*
int main(void)
{
SPEVENTS events=NULL;
SPEVENT  *event,*H;
str8 namev="tttt";
double time=1.444;
 if ((event = malloc(sizeof(SPEVENT)))== NULL)
      {printf("нехв т ет п мяти для р змещения элемент  структуры SPEVN\n");
      exit(100); }
     strcpy(event->namev, namev);
     event->time = time;
     event->next = NULL;
 if ((H = malloc(sizeof(SPEVENT)))== NULL)
      {printf("нехв т ет п мяти для р змещения элемент  структуры SPEVN\n");
      exit(101); }
     strcpy(H->namev, namev);
     H->time = time;
     H->next = event;
     events=H;

delevnt(&events);
delevnt(&events);
delevnt(&events);

return 1;
}
*/

