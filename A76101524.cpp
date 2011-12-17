#include "tpodata.h"
extern int SB16CA89F(MPAR *Akfun);
int A76101524(TPOData *D)
{
    //Настройка теста GKLS
    MPAR *_Akfun = D->Akfun;

    int result = SB16CA89F(_Akfun);

    D->Akfun = _Akfun;


    return result;
}
