#include "graph.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>

void enter(const char* name)
{
    //FILE *f = fopen("stacktrace.txt", "a+");
    printf("Process %d: Enter %s\r\n", myProcNum, name);
    //fclose(f);
}

void leave(const char* name)
{
    //FILE *f = fopen("stacktrace.txt", "a+");
    printf("Process %d: Leave %s....OK!\r\n", myProcNum, name);
    //fclose(f);
}

int GraphMV(TPOData *D, int jroot, int , DefinePredicate *ListPred, DefineTop *ListTop, DefineGraph *ListGraf)
{
    int jfirst, jlast, j, jPred, jTop, Fpred;
    int (*Tp)(TPOData *);
    Tp =  ListTop[jroot].top;
//    enter(ListTop[jroot].NameTop);
    (*Tp)(D); //Do actor
//    leave(ListTop[jroot].NameTop);

    jfirst = ListTop[jroot].FirstDef;
    jlast  = ListTop[jroot].LastDef;
BEGIN:
    for(j = jfirst; j <= jlast; j++) {
	jPred = ListGraf[j].NambPred;

        Tp =  ListPred[jPred].predicate;
        Fpred = (*Tp)(D);

        if(Fpred == 1) {
            jTop = ListGraf[j].NambTop;
            Tp  =  ListTop[jTop].top;
//            enter(ListTop[jTop].NameTop);
            (*Tp)(D); //Do actor
//            leave(ListTop[jTop].NameTop);

            jfirst = ListTop[jTop].FirstDef;
            jlast  = ListTop[jTop].LastDef;

            if(jlast == -77)
                goto ENDGRAF;
            goto BEGIN;
        }
    }
ENDGRAF:
    return 1;
}
