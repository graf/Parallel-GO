//#include "gspuser.h"
#include "utype.h"
//#include <alloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int BPfiLM(LMAXS *Hxs, XI *xf,double *Eloc,int *Krep)
{ 
LMAX *H, *HP;
int i;
double R,L;

H=*Hxs;
HP=H;

BEG0:;

L=0;
for(i=0;i<DIMENSION;i++) 
	{R=fabs((H->xf0)[i]-(*xf)[i]);
	 if(R>L) L=R;
	}
if((L <= (*Eloc)/2) && (H->Npri >= (*Krep)*DIMENSION) && L !=0 )
	return(1);
	

	HP=H;
	H=H->next;
		
if (H==NULL)
	goto END0;
	else goto BEG0;

END0:;
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