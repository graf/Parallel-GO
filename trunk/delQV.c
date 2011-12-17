#include "utype.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int delQV(QVAD2S *simps)
{
    QVAD2  *H;
    /*
XI X9;
double R_,L;
int i;
X9[0]=0.25;
X9[1]=0.5;

R_=1;
for(i=0;i<NX_;i++)
 {if(fabs(X9[i]-((*simps)->x0[i]))<0.0000001) L=1;
 else L=0;
 R_=R_*L;
 }
if (R_==1)
 R_=R_;
*/

    if (*simps == NULL) {
        printf("попытка удалить элемент из пустого списка QVAD\n");
        exit(1);
    }

    H=*simps;
    if (H->next == NULL) {
        *simps = NULL;
    } else {
        *simps = H->next;
    }
    free(H);
    H = NULL;

    //printf("create elem tree = %d\n",*top);
    //getch();
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
      exit(1); }
     strcpy(event->namev, namev);
     event->time = time;
     event->next = NULL;
 if ((H = malloc(sizeof(SPEVENT)))== NULL)
      {printf("нехватает памяти для размещения элемента структуры SPEVN\n");
      exit(1); }
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

