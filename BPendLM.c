#include "utype.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int BPendLM(LMAXS *Hxs,int *Krep,int *Nmax)
{ 
    LMAX *H, *HP;
    double R;
    int N,Nmin;

    N=0;Nmin=64000;
    H=*Hxs;
    HP=H;
    R=0;

BEG0:;

    R=R+H->Npri;
    N++;
    if (Nmin > H->Npri) Nmin=H->Npri;
    HP=H;
    H=H->next;

    if (H==NULL)
        goto END0;
    else goto BEG0;

END0:;

    //return(0);//¯‗ÙÓõÛÓ
    if((R/N) >= (*Krep)*DIMENSION)
        //if(Nmin >= (*Krep)*DIMENSION)
        return(1);
    else
        return(0);
}

/*
int main(void)
{
static LMAXS Hxs=NULL; 
static XI xf={0,0.1};
double Eloc=0.1;
double mi=75;
int Nmax=0;
int Kmax=3;
FUNC z=1;


addLM(&Hxs,&xf,&z,&Eloc,&Nmax,&Kmax);
xf[0]=0.11;xf[1]=0.005;
z=2;
addLM(&Hxs,&xf,&z,&Eloc,&Nmax,&Kmax);
xf[0]=0.5;xf[1]=0.5;
z=5;
addLM(&Hxs,&xf,&z,&Eloc,&Nmax,&Kmax);
xf[0]=0.505;xf[1]=0.51;
z=5.6;
addLM(&Hxs,&xf,&z,&Eloc,&Nmax,&Kmax);
xf[0]=0.705;xf[1]=0.51;
z=5.6;
addLM(&Hxs,&xf,&z,&Eloc,&Nmax,&Kmax);
xf[0]=0.705;xf[1]=0.251;
z=0.6;
addLM(&Hxs,&xf,&z,&Eloc,&Nmax,&Kmax);
free(Hxs);
return 1;
}
*/
