#include "utype.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int delLM(LMAXS *simps)
{
    LMAX  *H;

    if (*simps == NULL)
    {printf("попытка удалить элемент из пустого списка LMAX \n");
        exit(13); }

    while (*simps != NULL)
    {H=*simps;
        if (H->next==NULL)
        {
            H = NULL;
            *simps=NULL;
        }
        else
        {*simps=H->next;
            H = NULL;
        }
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
      {printf("нехватает памяти для размещения элемента структуры SPEVN\n");
      exit(14); }
     strcpy(event->namev, namev);
     event->time = time;
     event->next = NULL;
 if ((H = malloc(sizeof(SPEVENT)))== NULL)
      {printf("нехватает памяти для размещения элемента структуры SPEVN\n");
      exit(15); }
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

