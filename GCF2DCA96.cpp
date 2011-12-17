#include "graph.h"
int P282E6F54(TPOData *D);
int P6D120035(TPOData *D);
int GCF2DCA96(TPOData *D);
int A6F8E0D5D(TPOData *D);
int A50515E14(TPOData *D);
int AAA1FF769(TPOData *D);
int AA72B0A89(TPOData *D);
int A47C88229(TPOData *D);
int AE0DB6BEB(TPOData *D);
int A275CD97B(TPOData *D);
int G15C01624(TPOData *D);
static DefinePredicate ListPred[2] = {
    DefinePredicate("P282E6F54", &P282E6F54),
    DefinePredicate("P6D120035", &P6D120035)
};
static DefineTop ListTop[3] = {
    DefineTop("AA72B0A89", 0, 0, &AA72B0A89),
    DefineTop("G15C01624", 1, 1, &G15C01624),
    DefineTop("AE0DB6BEB", -77, -77, &AE0DB6BEB)
};
static DefineGraph ListGraf[2] = {
    DefineGraph(0, 1),
    DefineGraph(0, 2)
};
int GCF2DCA96(TPOData *D)
{
    //Параллельный кусок
    //printf("Параллельный кусок\r\n");
    int topCount = 3;
    int rootTop = 0;
    GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
    return 1;
}
