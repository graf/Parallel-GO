#include "graph.h"
int P282E6F54(TPOData *D);
int P6D120035(TPOData *D);
int A6F8E0D5D(TPOData *D);
int A50515E14(TPOData *D);
int AAA1FF769(TPOData *D);
int A47C88229(TPOData *D);
int A275CD97B(TPOData *D);
int G15C01624(TPOData *D);
static DefinePredicate ListPred[2] = {
DefinePredicate("P282E6F54", &P282E6F54),
DefinePredicate("P6D120035", &P6D120035)
};
static DefineTop ListTop[19] = {
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("GHOST TOP", -77, -77, NULL),
DefineTop("A6F8E0D5D", 0, 0, &A6F8E0D5D),
DefineTop("A50515E14", 1, 2, &A50515E14),
DefineTop("A275CD97B", 3, 3, &A275CD97B),
DefineTop("A47C88229", 4, 4, &A47C88229),
DefineTop("AAA1FF769", -77, -77, &AAA1FF769)
};
static DefineGraph ListGraf[5] = {
DefineGraph(0, 15),
DefineGraph(1, 18),
DefineGraph(0, 16),
DefineGraph(0, 17),
DefineGraph(0, 18)
};
int G15C01624(TPOData *D)
{
//Локальный поиск по процессорам ||
//printf("Локальный поиск по процессорам ||\r\n");
int topCount = 5;
int rootTop = 14;
GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
return 1;
}
