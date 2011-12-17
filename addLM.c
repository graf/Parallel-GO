#include "utype.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//#include <alloc.h>
//#include "gspuser.h"

int addLM(LMAXS *Hxs, XI *xf, FUNC *z, double *Eloc, int *Nmax, int *Kmax)
{ 
    LMAX *Hx, *H, *HP, *Hn;
    int i,FP,Npr;
    FUNC zt,zs,Inf;
    double R,L;

    FP=0;

    if (*Hxs==NULL)
    {
        if ((Hx = calloc(1,sizeof(LMAX)))== NULL)
        {printf("��墠⠥� ������ ��� ࠧ��饭�� ������ ��������� LMAX\n"); exit(1);}

        for(i=0;i<DIMENSION;i++) (Hx->xf0)[i]=(*xf)[i];
        Hx->fmax   = *z;
        Hx->Npri   = 1;
        Hx->next=NULL;
        (*Nmax)++;
        *Hxs=Hx;
        return 1;
    }

    H=*Hxs;
    HP=H;
    Npr=0;
BEG0:;

    L=0;
    for(i=0;i<DIMENSION;i++)
    {R=fabs((H->xf0)[i]-(*xf)[i]);
        if(R>L) L=R;
    }
    if(L <= (*Eloc)/2)
    {
        if((*z) > H->fmax)
        {
            if((*Hxs) == H)
            {
                if(((*Hxs)->next)==NULL)
                {
                    Npr=(*Hxs)->Npri;
                    (*Hxs)=NULL;
                    free(H);
                    (*Nmax)--;
                    goto END0;
                }
                else
                {
                    Npr=Npr+(*Hxs)->Npri;
                    (*Hxs)=H->next;
                    H = NULL;
                    H=*Hxs;
                    HP=H;
                    (*Nmax)--;

                }
            }
            else
            {
                Npr=Npr+H->Npri;
                Hx=H;
                HP->next=H->next;
                H=HP->next;
                free(Hx);
                (*Nmax)--;

            }
        }
        else
        {
            H->Npri++;
            return 1;
        }
    }
    else
    {
        HP=H;
        H=H->next;
    }


    if (H==NULL)
        goto END0;
    else goto BEG0;

END0:;

    if(*Hxs==NULL) Inf=-1.0e77;
    else Inf= (*Hxs)->fmax;

    H=*Hxs;
    HP=H;

BEG:;

    if((*z) >= Inf)
    {
        if (*Hxs==NULL)
        {
            if ((Hx = calloc(1,sizeof(LMAX)))== NULL)
            {printf("��墠⠥� ������ ��� ࠧ��饭�� ������ ��������� LMAX\n"); exit(1);}

            for(i=0;i<DIMENSION;i++) (Hx->xf0)[i]=(*xf)[i];
            Hx->fmax   = *z;
            Hx->Npri   = 1;
            Hx->next=NULL;
            (*Nmax)++;
            *Hxs=Hx;
            return 1;
        }
        zt=(H->fmax);
        if((H->next)==NULL) zs=1.0e77;
        else zs=((H->next)->fmax);

        if((*z) >= zt && (*z) < zs)
        {
            if((*Hxs)==H)
            {
                if ((Hx =  calloc(1,sizeof(LMAX)))== NULL)
                {printf("��墠⠥� ������ ��� ࠧ��饭�� ������ ��������� LMAX\n");exit(1);}
                for(i=0;i<DIMENSION;i++) (Hx->xf0)[i]=(*xf)[i];
                (Hx->fmax) = *z;
                (Hx->Npri)=Npr+1;
                (*Nmax)++;
                Hx->next=(*Hxs)->next;
                (*Hxs)->next=Hx;
                goto RE;
            }
            else
            {
                if ((Hx =  calloc(1,sizeof(LMAX)))== NULL)
                {printf("��墠⠥� ������ ��� ࠧ��饭�� ������ ��������� LMAX\n");exit(1);}
                for(i=0;i<DIMENSION;i++) (Hx->xf0)[i]=(*xf)[i];
                (Hx->fmax) = *z;
                (Hx->Npri)=Npr+1;
                (*Nmax)++;
                Hn=H->next;
                H->next=Hx;
                Hx->next=Hn;
                goto RE;
            }
        }
        HP=H;
        H=H->next;

        if (H==NULL)
            goto END;
        else goto BEG;

END:;
    }

    if(((*z) < Inf) && (*Nmax)<=(*Kmax))
    {
        if ((Hx = calloc(1,sizeof(LMAX)))== NULL)
        {printf("��墠⠥� ������ ��� ࠧ��饭�� ������ ��������� LMAX\n"); exit(1);}

        for(i=0;i<DIMENSION;i++) (Hx->xf0)[i]=(*xf)[i];
        Hx->fmax   = *z;
        (Hx->Npri)=1;
        Hx->next=(*Hxs);
        (*Nmax)++;
        *Hxs=Hx;
    }

RE:;
    if((*Nmax)>(*Kmax))
    {
        HP=(*Hxs);
        (*Hxs)=(HP->next);
        free(HP);
        (*Nmax)--;
    }
    return 1;
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
