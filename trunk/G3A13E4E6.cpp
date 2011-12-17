#include "graph.h"
int P1D6BE722(TPOData *D);
int P282E6F54(TPOData *D);
int P37DE52F(TPOData *D);
int A34FC36CB(TPOData *D);
int A58101D91(TPOData *D);
int G3A13E4E6(TPOData *D);
int A4CE136AF(TPOData *D);
static DefinePredicate ListPred[3] = {
DefinePredicate("P1D6BE722", &P1D6BE722),
DefinePredicate("P282E6F54", &P282E6F54),
DefinePredicate("P37DE52F", &P37DE52F)
};
static DefineTop ListTop[3] = {
DefineTop("A4CE136AF", 0, 1, &A4CE136AF),
DefineTop("A34FC36CB", -77, -77, &A34FC36CB),
DefineTop("A58101D91", 2, 3, &A58101D91)
};
static DefineGraph ListGraf[4] = {
DefineGraph(0, 0),
DefineGraph(1, 1),
DefineGraph(2, 1),
DefineGraph(1, 0)
};
int G3A13E4E6(TPOData *D)
{
//Очистка списка квадратов
//printf("Очистка списка квадратов\r\n");
int topCount = 3;
int rootTop = 2;
GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
return 1;
}
