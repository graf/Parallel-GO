#include "utype.h"
#include  <math.h>

double F1(double *X,double *Y);
double F22(double *Y);
double F21(double *X);
double F23(double *X,double *Y);
int B22(double *Y);
int B23(double *X,double *Y);
double R1(double *X,double *Y);
int B21(double *X);
int BR1(double *X,double *Y);
double R2(double *X,double *Y);
int B1(double *X,double *Y);
int BR2(double *X,double *Y);
int Rez(double *X,double *Y,double *R);

static double a=1.001;
//Листья
double F1(double *X,double *Y)
 {
  return(1.5-((*X)-1)*((*X)-1)-((*Y)-1)*((*Y)-1));
 }

double F21(double *X)
 {
  return(2.0-fabs((*X)-1.));
 }

double F22(double *Y)
 {
  return(2.0-fabs((*Y)-1.));
 }

double F23(double *X,double *Y)
 {
	
  return(((*X)-a)*((*X)-a)+((*Y)-a)*((*Y)-a)+0.5);
 }
//решающие функции
int B22(double *Y)
 {
  return(F22(Y)>1.0);
 }

int B23(double *X,double *Y)
 {
  return(F23(X,Y)>1.0);
 }
//R1
double R1(double *X,double *Y)
 {double R;int b1,b2;double f1,f2;
 b1=B22(Y);
 b2=B23(X,Y);
 f1=F22(Y);
 f2=F23(X,Y);
 R=(!b1*f1+!b2*f2)/(!b1+!b2+b2*b1);
 R=R+b2*b1*(f1+f2)/2;
  return(R);
 }

//R2
int B21(double *X)
 {
  return(F21(X)>1.0);
 }

int BR1(double *X,double *Y)
 {
  return(R1(X,Y)>1.0);
 }

double R2(double *X,double *Y)
 {double R;int b1,b2; double f1,f2;
 b1=B21(X);
 b2=BR1(X,Y);
 f1=F21(X);
 f2=R1(X,Y);
 R=(!b1*f1+!b2*f2)/(!b1+!b2+b2*b1);
 R=R+b2*b1*(f1+f2)/2;
  return(R);
 }

//Rez
int B1(double *X,double *Y)
 {
  return(F1(X,Y)>=1.0);
 }

int BR2(double *X,double *Y)
 {
  return(R2(X,Y)>1.0);
 }

int Resh(double *X,double *Y,double *R)
 {int b1,b2;double f1,f2;
 b1=B1(X,Y);
 b2=BR2(X,Y);
 f1=F1(X,Y);
 f2=R2(X,Y);
 (*R)=(b1*f1+b2*f2)/(b1+b2+(!b1*!b2));
 (*R)=(*R)+(!b1*!b2)*(f1+f2)/2;
  return 1;
 }


/*
int main(void)
{
static double X=0.75,Y=0.75,R;
X=0.001;Y=X;

while (X<=2)
{Rez(&X,&Y,&R);
X=X+0.1; Y=X;
}
return 1;
}
*/
