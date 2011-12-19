#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "utype.h"



typedef double MATRIC[DIMENSION+1][DIMENSION+1];
typedef double KRIT[2];
typedef int (*optfunc)(XI *X,FUNC *z,int *NFUNC,MPAR *Af);

int initsimp(XI, MATRIC *,MPAR *, optfunc,int *Nfunc);
int M_X(XI X0,MATRIC R,int IX);
int X_M(XI* X0,MATRIC R,int IX,MPAR *BB,optfunc ff,int*);
int MaM(MATRIC ,int *,int * );
int cent(XI X0,MATRIC R,int Imax,double *F1);
int step(XI X0,XI X1,XI X2,XI X3,double *a);
//int Zfun3(XI *X,FUNC *z,int *NFUNC,MPAR *Af);


//****************************
int deform(XI* X,FUNC *Yc,MPAR *BB,int *Nfunc,double *Esimp)
//     
{
double a=1.0, g=1.5, b=0.5,S;
FUNC F,F1,Fend;
MATRIC R;
//int (*func)(XI *X,FUNC *z,int *NFUNC,MPAR *Af);
int Zfun3(XI *X,FUNC *z,int *NFUNC,MPAR *Af);
int IX=2,Imax,Imin,i;
XI Xc,X0,Xa,Xp,Xb;
/*S=((*X)[0]-0.333622684666667)*((*X)[0]-0.333622684666667);
	S=S+((*X)[1]-0.333478008666666)*((*X)[1]-0.333478008666666);
	S=S+((*X)[2]-0.54609375)*((*X)[2]-0.54609375);
	S=S+((*X)[3]-0.709953703666667)*((*X)[3]-0.709953703666667);
	S=S+((*X)[4]-0.515)*((*X)[4]-0.515);
	S=S+((*X)[5]-0.51361111111)*((*X)[5]-0.51361111111);
	S=sqrt(S);
	if(S<0.11)	
	{printf(" F=%e S=%e\n",F,S);}
	*/
//func=fy;
initsimp(*X, &R,BB, Zfun3,Nfunc);//      㭪樨
BEG:;
MaM(R,&Imax,&Imin);
cent(Xc,R,Imax,&Fend);
M_X(Xa, R,Imax);
step(X0, Xc, Xc, Xa,&a);

//X0=Xc+a*(Xc-Xa);
  Zfun3(&X0,&F,Nfunc,BB);

if (Fend<=*Esimp)
   {
	//Vixod
     M_X(*X,R,Imin);
     *Yc=F;
      return(1);
   }
  if (-F<R[Imin][DIMENSION])
     {   //  殮
     step(Xp,Xc,X0,Xc,&g);
     //Xp=Xc+g*(X0-Xc);
     Zfun3(&Xp,&F1,Nfunc,BB);
     if (-F1>-F)  X_M(&X0, R,Imax,BB,Zfun3,Nfunc);
     else         X_M(&Xp, R,Imax,BB,Zfun3,Nfunc);
     goto END;
     }
  else
     if ((-F < R[Imax][DIMENSION]) && (-F > R[Imin][DIMENSION]))
       {   //  ⨥
        step(Xc,Xc,Xa,Xc,&b);
        //Xc=Xc+b*(Xa-Xc);
        Zfun3(&Xc,&F1,Nfunc,BB);
        if (-F1>-F)  X_M(&X0, R,Imax,BB,Zfun3,Nfunc);
        else         X_M(&Xc, R,Imax,BB,Zfun3,Nfunc);
     goto END;
       }
       else
         if (-F >= R[Imax][DIMENSION])
           {  //।
            M_X(Xb,R,Imin);
            for (i=0;i<=DIMENSION;i++)
              {M_X(Xa,R,i);
               step(Xc,Xb,Xa,Xb,&b);
               //Xc=Xb+b*(Xa-Xb);
               X_M(&Xc, R,i,BB,Zfun3,Nfunc);
              }
            goto END;
            }
           else
           {
            X_M(&X0, R,Imax,BB,Zfun3,Nfunc);
            goto END;
           }
END:;

goto BEG;

return(1);
}

//***************************************************************************
int initsimp(XI X0,MATRIC *R,MPAR *BB,optfunc ff,int *Nfunc)
{ double F;
   int n1=DIMENSION+1,i,j;
   int (*func)(XI *X,FUNC *z,int *NFUNC,MPAR *Af);
   XI X;
    func=ff;
  
	
	
/*	r1=(dlina/(DIMENSION*sqrt(2.0)))*(sqrt(n1)+DIMENSION-1);
	r2=(dlina/(DIMENSION*sqrt(2.0)))*(sqrt(n1)-1);
	for (i=0;i<DIMENSION;i++)
       (*R)[0][i]=X0[i];

	for (i=1;i<=DIMENSION;i++)
       for (j=0;j<DIMENSION;j++)
           (*R)[i][j]=r2+X0[j];

	for (i=1;i<=DIMENSION;i++)
           (*R)[i][i-1]=r1+X0[i-1];
*/
	for (i=0;i<DIMENSION;i++)
       (*R)[0][i]=X0[i];
	
	for (i=1;i<=DIMENSION;i++)
       for (j=0;j<DIMENSION;j++)
           (*R)[i][j]=X0[j];

	for (i=1;i<=DIMENSION;i++)
       (*R)[i][i-1]=X0[i-1]+DSIMP;
	
	for (i=0;i<=DIMENSION;i++)
       {for (j=0;j<DIMENSION;j++)
          X[j]=(*R)[i][j];
          func(&X,&F,Nfunc,BB);
          (*R)[i][DIMENSION]=-F;
        }
 return(1);
}
/////////////////////////////////////////////////////////////////////////////
int MaM(MATRIC R,int *max,int *min )
{  int i; double Fmax=-1.0e77,Fmin=1.0e77;
   *max=0; *min=0;
   for (i=0;i<=DIMENSION;i++)
      { if (R[i][DIMENSION]<=Fmin)
                {*min=i; Fmin=R[i][DIMENSION];}
        if (R[i][DIMENSION]>Fmax)
                {*max=i; Fmax=R[i][DIMENSION];}
      }
   return(1);
}
/**************************************************************************/
int cent(XI X0,MATRIC R,int Imax,double *F1)
{  int i,j; double F;

   for (i=0;i<DIMENSION;i++)
      {F=0;
      for (j=0;j<=DIMENSION;j++)
         F=F+R[j][i];
      (X0)[i]=(F-R[Imax][i])/DIMENSION;
      }
   *F1=0.0;
   for (i=0;i<DIMENSION;i++)
      {F=0.0;
      for (j=0;j<=DIMENSION;j++)
      F=F+((X0)[i]-R[j][i])*((X0)[i]-R[j][i]);
      *F1=*F1+sqrt(F);
      }
   *F1=*F1/(DIMENSION+1);
  return(1);
}
/****************************************************************************/
int X_M(XI* X0,MATRIC R,int IX,MPAR *BB,optfunc ff,int *I)
{  int i; 
	FUNC F;
   int (*func)(XI *X,FUNC *z,int *NFUNC,MPAR *Af);
   func=ff;
   for (i=0;i<DIMENSION;i++)
       (R)[IX][i]=(*X0)[i];
   func(X0,&F,I,BB);
   (R)[IX][DIMENSION]=-F;
  return(1);
}
//****************************************************************************/
int M_X(XI X0,MATRIC R,int IX)
{  int i;
   for (i=0;i<DIMENSION;i++)
      (X0)[i]=R[IX][i];
  return(1);
}
/////////////////////////////////////////////////////////////////////////////
int step(XI X0,XI X1,XI X2,XI X3,double *a)
{int i;
for (i=0;i<DIMENSION;i++)
  (X0)[i]=(X1)[i]+(*a)*((X2)[i]-(X3)[i]);
return 1;
}
///////////////////////////////////////////////////////////////////////
/*
int Zfun3(XI *X,FUNC *z,int *NFUNC,MPAR *Af)
	{
	*z=-(((*X)[0]-2)*((*X)[0]-2)+((*X)[1]-3.5)*((*X)[1]-3.5));
	return 1;
	}
*/	
/**************************************
int main(void)
{
 static FUNC Yc;
 static XI X={48.5,8.2};
 static MPAR B;
 int Nfunc;
 double Esimp;
 
 KRIT Yd={0.001,0.01};
 
 int Nx=DIMENSION;


 deform(&X,&Yc,&B,&Nfunc,&Esimp);        //min y1

 return 1;
 }
*/ 
