#include "graph.h"
int P6D120035(TPOData *D);
int P3CCF6131(TPOData *D);
int P11577D41(TPOData *D);
int P282E6F54(TPOData *D);
int A34FC36CB(TPOData *D);
int A751E17FE(TPOData *D);
int AE54835B2(TPOData *D);
int AD5BCBEC(TPOData *D);
int A50515E14(TPOData *D);
int G4D288644(TPOData *D);
int A3593C33C(TPOData *D);
int A87A451F5(TPOData *D);
int A4B856DF1(TPOData *D);
static DefinePredicate ListPred[4] = {
	DefinePredicate("P6D120035", &P6D120035),
	DefinePredicate("P3CCF6131", &P3CCF6131),
	DefinePredicate("P11577D41", &P11577D41),
	DefinePredicate("P282E6F54", &P282E6F54)
};
static DefineTop ListTop[8] = {
	DefineTop("A751E17FE", 0, 0, &A751E17FE),
	DefineTop("A50515E14", 1, 2, &A50515E14),
	DefineTop("A3593C33C", 3, 4, &A3593C33C),
	DefineTop("A34FC36CB", -77, -77, &A34FC36CB),
	DefineTop("AE54835B2", 5, 5, &AE54835B2),
	DefineTop("A87A451F5", 6, 6, &A87A451F5),
	DefineTop("A4B856DF1", 7, 7, &A4B856DF1),
	DefineTop("AD5BCBEC", 8, 9, &AD5BCBEC)
};
static DefineGraph ListGraf[10] = {
	DefineGraph(3, 1),
	DefineGraph(0, 2),
	DefineGraph(3, 4),
	DefineGraph(2, 1),
	DefineGraph(3, 3),
	DefineGraph(3, 5),
	DefineGraph(3, 6),
	DefineGraph(3, 7),
	DefineGraph(1, 4),
	DefineGraph(2, 2)
};
int G4D288644(TPOData *D)
{
	//Перерасчет списка элементов
	//printf("Перерасчет списка элементов\r\n");
	int topCount = 8;
	int rootTop = 0;
	GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
	return 1;
}
