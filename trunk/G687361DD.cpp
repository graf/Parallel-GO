#include "graph.h"
int P282E6F54(TPOData *D);
int G687361DD(TPOData *D);
int ABE3B97B1(TPOData *D);
int AF7F684BF(TPOData *D);
int AB20CC9C7(TPOData *D);
int A3C94B0E7(TPOData *D);
int AC4C482F7(TPOData *D);
static DefinePredicate ListPred[1] = {
DefinePredicate("P282E6F54", &P282E6F54)
};
static DefineTop ListTop[7] = {
DefineTop("AF7F684BF", 0, 0, &AF7F684BF),
DefineTop("ABE3B97B1", 1, 1, &ABE3B97B1),
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("AB20CC9C7", 2, 2, &AB20CC9C7),
DefineTop("A3C94B0E7", -77, -77, &A3C94B0E7),
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("AC4C482F7", 3, 3, &AC4C482F7)
};
static DefineGraph ListGraf[4] = {
DefineGraph(0, 3),
DefineGraph(0, 0),
DefineGraph(0, 4),
DefineGraph(0, 1)
};
int G687361DD(TPOData *D)
{
//Обработка локальных экстремумов ||
//printf("Обработка локальных экстремумов ||\r\n");
int topCount = 5;
int rootTop = 6;
GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
return 1;
}
