#include "utype.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int Potbrak(XIF *Z,XI *X0,int *NmaxF,double *lx,double *Kob)
{
    int j,i;
    double R;


    if((*NmaxF)==0) return(0);

    for(j=0;j<(*NmaxF);j++)
    {R=0;
        for(i=0;i<DIMENSION;i++)
            R=R+((*X0)[i]-(*Z)[j][i])*((*X0)[i]-(*Z)[j][i]);
        R=sqrt(R);
        if(R<(*Kob)*(*lx)) return(1);
        R=0;
        for(i=DIMENSION;i<2*DIMENSION;i++)
            R=R+((*X0)[i-DIMENSION]-(*Z)[j][i])*((*X0)[i-DIMENSION]-(*Z)[j][i]);
        R=sqrt(R);
        if(R<(*Kob)*(*lx)) return(1);
    }
    return(0);
}


/*
int main(void)
{
static XI X0={0,0,0},X;
int i=7;
double h=0.5;
konv(&i,&X,&h,&X0);
return 1;
}
*/
