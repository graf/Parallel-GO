#include "utype.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int addQVM(QVAD2S *simps, int *Nsimp,double *d2z,double *Str, double *Ksum,XI *x0,double *z,double *hx, FUNC *DelS,int *Lor,int *Hbd)
{ QVAD2 *simp, *H, *HP;
    XI X0;
    double R,L;
    int i;
    /*
for(i=0;i<DIMENSION;i++) 
 {X0[i]=0.25;}
 X0[0]=0.75;

R=1;
for(i=0;i<DIMENSION;i++)
 {if(fabs(X0[i]-(*x0)[i])<0.0000001) L=1;
 else L=0;
 R=R*L;
 }
if (R==1)
 R=R;
 */
    if (*simps==NULL)
    {
        if ((simp = malloc(sizeof(QVAD2)))== NULL)
        {printf("墠⠥   ࠧ饭   QVAD2\n"); exit(7);}
        simp->Nsimp = *Nsimp;
        simp->d2z   = *d2z;
        simp->Str   = *Str;
        for(i=0;i<DIMENSION;i++) (simp->x0)[i]=(*x0)[i];
        simp->z   = *z;
        simp->hx   = *hx;
        simp->DelS   = *DelS;
        simp->Ksum  = *Ksum;
        simp->Loran= *Lor;
        simp->Hbd= *Hbd;
        simp->next=NULL;
        *simps=simp;
        goto END;
    }

    H=*simps;
    HP=H;
BEG:
    if ((H->Loran) < *Lor)
    {
        if (H==*simps)
        {if ((simp = malloc(sizeof(QVAD2)))== NULL)
            {printf("墠⠥   ࠧ饭   QVAD2\n");exit(8);}
            simp->Nsimp = *Nsimp;
            simp->d2z   = *d2z;
            simp->Str   = *Str;
            for(i=0;i<DIMENSION;i++) (simp->x0)[i]=(*x0)[i];
            simp->z   = *z;
            simp->hx   = *hx;
            simp->DelS   = *DelS;
            simp->Ksum  = *Ksum;
            simp->Loran= *Lor;
            simp->Hbd= *Hbd;
            simp->next=H;
            *simps=simp;
            goto END;
        }
        else
        { if ((simp = malloc(sizeof(QVAD2)))== NULL)
            {printf("墠⠥   ࠧ饭   QVAD2\n");exit(9);}
            simp->Nsimp = *Nsimp;
            simp->d2z   = *d2z;
            simp->Str   = *Str;
            for(i=0;i<DIMENSION;i++) (simp->x0)[i]=(*x0)[i];
            simp->z   = *z;
            simp->hx   = *hx;
            simp->DelS   = *DelS;
            simp->Ksum  = *Ksum;
            simp->Loran= *Lor;
            simp->Hbd= *Hbd;
            HP->next=simp;
            simp->next=H;
            goto END;
        }
    }
    //*************************************
    if (((H->Loran) == *Lor)&&((H->Ksum)<=*Ksum))
    {
        if (H==*simps)
        {if ((simp = malloc(sizeof(QVAD2)))== NULL)
            {printf("墠⠥   ࠧ饭   QVAD2\n");exit(10);}
            simp->Nsimp = *Nsimp;
            simp->d2z   = *d2z;
            simp->Str   = *Str;
            for(i=0;i<DIMENSION;i++) (simp->x0)[i]=(*x0)[i];
            simp->z   = *z;
            simp->hx   = *hx;
            simp->DelS   = *DelS;
            simp->Ksum  = *Ksum;
            simp->Loran= *Lor;
            simp->Hbd= *Hbd;
            simp->next=H;
            *simps=simp;
            goto END;
        }
        else
        { if ((simp = malloc(sizeof(QVAD2)))== NULL)
            {printf("墠⠥   ࠧ饭   QVAD2\n");exit(11);}
            simp->Nsimp = *Nsimp;
            simp->d2z   = *d2z;
            simp->Str   = *Str;
            for(i=0;i<DIMENSION;i++) (simp->x0)[i]=(*x0)[i];
            simp->z   = *z;
            simp->hx   = *hx;
            simp->DelS   = *DelS;
            simp->Ksum  = *Ksum;
            simp->Loran= *Lor;
            simp->Hbd= *Hbd;
            HP->next=simp;
            simp->next=H;
            goto END;
        }
    }

    HP=H;
    H=H->next;

    if (H==NULL)
    {if ((simp = malloc(sizeof(QVAD2))) == NULL)
        {printf("墠⠥   ࠧ饭   QVAD2\n");exit(12);}
        simp->Nsimp = *Nsimp;
        simp->d2z   = *d2z;
        simp->Str   = *Str;
        for(i=0;i<DIMENSION;i++) (simp->x0)[i]=(*x0)[i];
        simp->z   = *z;
        simp->hx   = *hx;
        simp->DelS   = *DelS;
        simp->Ksum  = *Ksum;
        simp->Loran= *Lor;
        simp->Hbd= *Hbd;
        HP->next = simp;
        simp->next=NULL;
        goto END;
    }
    else goto BEG;

END:
    //printf("\n ஢ ᮡ simp= %s  %f",namev,*Ksum);
    //getch();

    return 1;
}
/*
int main(void)
{
QVAD2S simps=NULL;
QVAD2  *simp;
double d2z=20,Str=5,Fsr=1,Ksum=1;
int MNf[3]={2,3,4};
int MNp=1,Nsimp=1;
int i1=1,i2=2,i3=3;
addsim(&simps,&Nsimp,&d2z,&Str, &Fsr,&Ksum,&i1,&i2,&i3,&MNp);
Nsimp=2;Fsr=1;Ksum=10;
addsim(&simps,&Nsimp,&d2z,&Str, &Fsr,&Ksum,&i1,&i2,&i3,&MNp);
Nsimp=3;Fsr=2;Ksum=10;
addsim(&simps,&Nsimp,&d2z,&Str, &Fsr,&Ksum,&i1,&i2,&i3,&MNp);
Nsimp=3;Fsr=2;Ksum=0;
addsim(&simps,&Nsimp,&d2z,&Str, &Fsr,&Ksum,&i1,&i2,&i3,&MNp);
free(simps);
return 1;
}
*/
