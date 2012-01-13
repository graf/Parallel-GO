#include "utype.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int endHLM(LMAXS *Hxs,LMAXS *HP,LMAXS *Hend);

int addLM2(LMAXS *Hxs, XI *xf, FUNC *z, double *Eloc, int *Nmax, int *Kmax, LMAXS *Hend)
{ 
    LMAX *Hx, *H, *HP, *Hn, *He, *HPe;
    int i,FP,Npr;
    FUNC zt,zs,Inf;
    double R,L;
//    static XI xm={0.907, 0.458, 0.0135, 0.6655, 0.5335, 0.279, 0.507, 0.266};
//    static XI xm={0.996,0.7675,0.667,0.4665};
//    static XI xm={0.4965,0.9605,0.62,0.075,0.0185,0.015,0.74};



    //Первая точка
    if (*Hxs==NULL)
    {
        if ((Hx = calloc(1,sizeof(LMAX)))== NULL)
        {printf("­Ґеў в Ґв Ї ¬пвЁ ¤«п а §¬ҐйҐ­Ёп н«Ґ¬Ґ­в  бвагЄвгал LMAX\n"); exit(1);}

        for(i=0;i<DIMENSION;i++) (Hx->xf0)[i]=(*xf)[i];
        for(i=0;i<DIMENSION;i++) (Hx->xLm)[i]=(*xf)[i];
        Hx->fmax   = *z;
        Hx->Npri   = 1;
        Hx->next=NULL;
        Hx->prev=NULL;
        (*Nmax)++;
        *Hxs=Hx;
        *Hend=NULL;
        return 1;
    }

    H=*Hxs;
    HP=H;
    Npr=1;
BEG0:;

//    Ловушка А.Н.
//    L=0;R=0;
//    for(i=0;i<DIMENSION;i++)
//        R=R+((H->xf0)[i]-xm[i])*((H->xf0)[i]-xm[i]);
//    L=sqrt(R);
//    if(L<=*Eloc)
//        L=2*L;


    L=0;R=0;
    for(i=0;i<DIMENSION;i++) R=R+((H->xf0)[i]-(*xf)[i])*((H->xf0)[i]-(*xf)[i]);
    L=sqrt(R);

    //Просмотр всех существующих кластеров. Если точка попала в существующий кластер
    //Этап подготовки. Удаление элементов списка
    if(L <= (*Eloc))
    {
        for(i=0;i<DIMENSION;i++) (H->xLm)[i]=(H->xLm)[i]+(*xf)[i];
        (H->Npri)++;
        for(i=0;i<DIMENSION;i++) (H->xf0)[i]=((H->xLm)[i])/(H->Npri);
        if((*z) > H->fmax)
        {
            H->fmax = *z;
            HP=H;
            if((H->prev)!=NULL && (H->next)!=NULL)
            {Hn=H->prev;
                ((H->prev)->next)=H->next;
                ((H->next)->prev)=H->prev;
                (*Hend)=NULL;
                goto END1;}
            if((H->prev)!=NULL && (H->next)==NULL)
            {Hn=H->prev;
                ((H->prev)->next)=NULL;
                (*Hend)=H;
                goto END1;}
            if((H->prev)==NULL && (H->next)!=NULL)
            {(*Hend)=NULL;
                return 1;
            }
END1:;
            FP=0;
            while(Hn!=NULL)
            {
                if((Hn->fmax) <= *z)
                {HP=Hn;
                    Hn=Hn->prev;
                    FP=1;}
                else
                {
                    if(FP==1)
                    {
                        (Hn->next)=H;
                        (H->next)=HP;
                        (H->prev)=Hn;
                        (HP->prev)=H;
                        return 1;
                    }
                    else
                    {
                        if((Hn->next)!=NULL)
                        {
                            (H->next)=(Hn->next);
                            ((Hn->next)->prev)=H;
                            (Hn->next)=H;
                            (H->prev)=Hn;
                            return 1;
                        }
                        else
                        {
                            (H->next)=NULL;
                            (Hn->next)=H;
                            (H->prev)=Hn;
                            return 1;
                        }
                    }
                }
            }
            if((FP==1)&&(Hn==NULL))
            {
                ((*Hxs)->prev)=H;
                (H->next)=(*Hxs);
                (H->prev)=NULL;
                (*Hxs)=H;
                return;
            }
        }
        else
            return 1;

    }


    HP=H;
    H=H->next;//Цикл по всем элементам


    if (H==NULL)
        goto END0;
    else goto BEG0;

END0:;

    if(*Hxs==NULL)
        Inf=(*z);
    else					//Нижняя грань
    {

        if ((*Hend)!=NULL)
        {endHLM(Hend,&HPe,&He);
            Inf=He->fmax;
            (*Hend)=HPe;
        }
        else
        {
            endHLM(Hxs,&HPe,&He);
            Inf=He->fmax;
            (*Hend)=HPe;
        }
    }
    //	Inf=((*Hend)->fmax);


    H=*Hxs;
    HP=H;
    //Упрощенная сортировка списка.Запись или обновление элементов списка
BEG:;

    if((*z) >= Inf)//Если имеется улучшение веса худшего кластера
    {
        if((*Hxs)==NULL)
        {//Для пустого списка
            if ((Hx = calloc(1,sizeof(LMAX)))== NULL)
            {printf("­Ґеў в Ґв Ї ¬пвЁ ¤«п а §¬ҐйҐ­Ёп н«Ґ¬Ґ­в  бвагЄвгал LMAX\n"); exit(1);}
            for(i=0;i<DIMENSION;i++) (Hx->xf0)[i]=(*xf)[i];
            for(i=0;i<DIMENSION;i++) (Hx->xLm)[i]=(*xf)[i];
            Hx->fmax   = *z;
            Hx->Npri   = 1;
            Hx->next=NULL;
            Hx->prev=NULL;
            (*Nmax)++;
            *Hxs=Hx;
            *Hend=NULL;
            return 1;
        }
        if(((*Hxs)!=NULL)&&(((*Hxs)->fmax)<=(*z)))
        {//Для первого элемента
            if ((Hx = calloc(1,sizeof(LMAX)))== NULL)
            {printf("­Ґеў в Ґв Ї ¬пвЁ ¤«п а §¬ҐйҐ­Ёп н«Ґ¬Ґ­в  бвагЄвгал LMAX\n"); exit(1);}
            for(i=0;i<DIMENSION;i++) (Hx->xf0)[i]=(*xf)[i];
            for(i=0;i<DIMENSION;i++) (Hx->xLm)[i]=(*xf)[i];
            Hx->fmax   = *z;
            Hx->Npri   = 1;
            Hx->next=(*Hxs);
            Hx->prev=NULL;
            (*Hxs)->prev=Hx;
            (*Nmax)++;
            *Hxs=Hx;
            *Hend=NULL;
            if ((*Nmax)>(*Kmax))
            {
                if((*Hend)!=NULL)
                {endHLM(Hend,&HPe,&He);
                    (*Hend)=HPe;
                }
                else
                {endHLM(Hxs,&HPe,&He);
                    (*Hend)=HPe;
                }
                ((He->prev)->next)=NULL;
                (*Hend)=He->prev;
                free(He);
                (*Nmax)--;
            }
            return 1;
        }
        zt=(H->fmax);//Вес текущего элемента
        if((H->next)==NULL) zs=1.0e77;//Вес следующего элемента
        else zs=((H->next)->fmax);

        if((*z) < zt && (*z) >= zs)
        {//Если новый элемент между текущим и следующим. Врезка
            if((*Hxs)==H)//Элемент лежит непосредственно после первого
            {
                if ((Hx =  calloc(1,sizeof(LMAX)))== NULL)
                {printf("­Ґеў в Ґв Ї ¬пвЁ ¤«п а §¬ҐйҐ­Ёп н«Ґ¬Ґ­в  бвагЄвгал LMAX\n");exit(1);}
                for(i=0;i<DIMENSION;i++) (Hx->xf0)[i]=(*xf)[i];
                for(i=0;i<DIMENSION;i++) (Hx->xLm)[i]=(*xf)[i];
                (Hx->fmax) = *z;
                (Hx->Npri)=1;
                (*Nmax)++;
                Hx->next=(*Hxs)->next;
                Hx->prev=(*Hxs);
                ((*Hxs)->next)->prev=Hx;
                (*Hxs)->next=Hx;
                *Hend=Hx;
                if ((*Nmax)>(*Kmax))
                {
                    if((*Hend)!=NULL)
                    {endHLM(Hend,&HPe,&He);
                        (*Hend)=He;
                    }
                    else
                    {endHLM(Hxs,&HPe,&He);
                        (*Hend)=He;
                    }
                    (He->prev)->next=NULL;
                    (*Hend)=He->prev;
                    free(He);
                    (*Nmax)--;
                }
                goto RE;
            }
            else
            {
                if ((Hx =  calloc(1,sizeof(LMAX)))== NULL)
                {printf("­Ґеў в Ґв Ї ¬пвЁ ¤«п а §¬ҐйҐ­Ёп н«Ґ¬Ґ­в  бвагЄвгал LMAX\n");exit(1);}
                for(i=0;i<DIMENSION;i++) (Hx->xf0)[i]=(*xf)[i];
                for(i=0;i<DIMENSION;i++) (Hx->xLm)[i]=(*xf)[i];
                (Hx->fmax) = *z;
                (Hx->Npri)=1;
                (*Nmax)++;
                Hx->next=H->next;
                Hx->prev=H;
                ((H->next)->prev)=Hx;
                (H->next)=Hx;
                *Hend=Hx;
                if ((*Nmax)>(*Kmax))
                {
                    if((*Hend)!=NULL)
                    {endHLM(Hend,&HPe,&He);
                        (*Hend)=He;
                    }
                    else
                    {endHLM(Hxs,&HPe,&He);
                        (*Hend)=He;
                    }
                    (He->prev)->next=NULL;
                    (*Hend)=He->prev;
                    free(He);
                    (*Nmax)--;
                }
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
    //Если нет улучшения наихудшего кластера, но есть вакансии в списке начальных приближений
    if(((*z) < Inf) && (*Nmax)<(*Kmax))
    {
        if ((Hx = calloc(1,sizeof(LMAX)))== NULL)
        {printf("­Ґеў в Ґв Ї ¬пвЁ ¤«п а §¬ҐйҐ­Ёп н«Ґ¬Ґ­в  бвагЄвгал LMAX\n"); exit(1);}

        for(i=0;i<DIMENSION;i++) (Hx->xf0)[i]=(*xf)[i];
        for(i=0;i<DIMENSION;i++) (Hx->xLm)[i]=(*xf)[i];
        Hx->fmax   = *z;
        (Hx->Npri)=1;
        Hx->next=NULL;
        if((*Hend)!=NULL)
            endHLM(Hend,&HPe,&He);
        else
            endHLM(Hxs,&HPe,&He);
        (*Hend)=He;
        He->next=Hx;
        Hx->prev=He;
        (*Nmax)++;
    }

RE:;

    return 1;
}

int endHLM(LMAXS *Hxs,LMAXS *HP,LMAXS *Hend)
{
    LMAX *H,*He;
    H=(*Hxs);
    while (H!=NULL)
    {
        if((H->next)!=NULL)
            if((H->next)->next==NULL)
                (*HP)=H;
            else
                (*HP)=*Hxs;
        else
            (*HP)=*Hxs;
        He=H;
        H=H->next;
    }
    (*Hend)=He;
    return 1;
} 

/*

int main(void)
{
static LMAXS Hxs=NULL,Hend=NULL; 
static XI xf={0,0.1};
double Eloc=0.1;
double mi=75;
int Nmax=0;
int Kmax=2;
FUNC z=1;


addLM2(&Hxs,&xf,&z,&Eloc,&Nmax,&Kmax,&Hend);
xf[0]=0.11;xf[1]=0.005;
z=9;
addLM2(&Hxs,&xf,&z,&Eloc,&Nmax,&Kmax,&Hend);
xf[0]=0.5;xf[1]=0.5;
z=5;
addLM2(&Hxs,&xf,&z,&Eloc,&Nmax,&Kmax,&Hend);
xf[0]=0.71;xf[1]=0.51;
z=2.1;
addLM2(&Hxs,&xf,&z,&Eloc,&Nmax,&Kmax,&Hend);
xf[0]=0.705;xf[1]=0.51;
z=2.6;
addLM2(&Hxs,&xf,&z,&Eloc,&Nmax,&Kmax,&Hend);
xf[0]=0.11;xf[1]=0.00511;
z=66;
addLM2(&Hxs,&xf,&z,&Eloc,&Nmax,&Kmax,&Hend);
free(Hxs);
return 1;
}
*/
