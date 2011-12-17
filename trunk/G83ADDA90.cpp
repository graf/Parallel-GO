#include "graph.h"
int P99390B2F(TPOData *D);
int P282E6F54(TPOData *D);
int PE6F9C907(TPOData *D);
int G83ADDA90(TPOData *D);
int A34FC36CB(TPOData *D);
int AC474C1C6(TPOData *D);
int AC9F60AD(TPOData *D);
int A3E1AF896(TPOData *D);
static DefinePredicate ListPred[3] = {
DefinePredicate("P99390B2F", &P99390B2F),
DefinePredicate("P282E6F54", &P282E6F54),
DefinePredicate("PE6F9C907", &PE6F9C907)
};
static DefineTop ListTop[5] = {
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("A3E1AF896", 0, 1, &A3E1AF896),
DefineTop("AC474C1C6", 2, 3, &AC474C1C6),
DefineTop("A34FC36CB", -77, -77, &A34FC36CB),
DefineTop("AC9F60AD", 4, 5, &AC9F60AD)
};
static DefineGraph ListGraf[6] = {
DefineGraph(2, 3),
DefineGraph(1, 2),
DefineGraph(2, 3),
DefineGraph(1, 4),
DefineGraph(0, 2),
DefineGraph(1, 3)
};
int G83ADDA90(TPOData *D)
{
//Раздача приближений лок.максимумов по процессорам
//printf("Раздача приближений лок.максимумов по процессорам\r\n");
int topCount = 4;
int rootTop = 1;
GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
return 1;
}
