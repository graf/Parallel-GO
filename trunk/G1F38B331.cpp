#include "graph.h"
int P99390B2F(TPOData *D);
int P282E6F54(TPOData *D);
int P37DE52F(TPOData *D);
int A3FBDF9D1(TPOData *D);
int AAB2621AD(TPOData *D);
int A34FC36CB(TPOData *D);
int AC9F60AD(TPOData *D);
int G1F38B331(TPOData *D);
int A3E1AF896(TPOData *D);
static DefinePredicate ListPred[3] = {
DefinePredicate("P99390B2F", &P99390B2F),
DefinePredicate("P282E6F54", &P282E6F54),
DefinePredicate("P37DE52F", &P37DE52F)
};
static DefineTop ListTop[5] = {
DefineTop("A3FBDF9D1", 0, 0, &A3FBDF9D1),
DefineTop("A3E1AF896", 1, 2, &A3E1AF896),
DefineTop("AAB2621AD", 3, 4, &AAB2621AD),
DefineTop("A34FC36CB", -77, -77, &A34FC36CB),
DefineTop("AC9F60AD", 5, 6, &AC9F60AD)
};
static DefineGraph ListGraf[7] = {
DefineGraph(1, 1),
DefineGraph(2, 3),
DefineGraph(1, 2),
DefineGraph(2, 3),
DefineGraph(1, 4),
DefineGraph(0, 2),
DefineGraph(1, 3)
};
int G1F38B331(TPOData *D)
{
//Раздача заданий по процессорам
//printf("Раздача заданий по процессорам\r\n");
int topCount = 5;
int rootTop = 0;
GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
return 1;
}
