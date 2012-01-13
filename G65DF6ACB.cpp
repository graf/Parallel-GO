#include "graph.h"
int P282E6F54(TPOData *D);
int AC4C482F7(TPOData *D);
int A8BAF7ABB(TPOData *D);
int AB20CC9C7(TPOData *D);
int A9D1C7CCE(TPOData *D);
int ABE3B97B1(TPOData *D);
int G65DF6ACB(TPOData *D);
int G687361DD(TPOData *D);
int AF7F684BF(TPOData *D);
int A3C94B0E7(TPOData *D);
static DefinePredicate ListPred[1] = {
	DefinePredicate("P282E6F54", &P282E6F54)
};
static DefineTop ListTop[4] = {
	DefineTop("GHOST TOP", -77, -77, NULL),
	DefineTop("G687361DD", 0, 0, &G687361DD),
	DefineTop("A8BAF7ABB", -77, -77, &A8BAF7ABB),
	DefineTop("A9D1C7CCE", 1, 1, &A9D1C7CCE)
};
static DefineGraph ListGraf[2] = {
	DefineGraph(0, 2),
	DefineGraph(0, 1)
};
int G65DF6ACB(TPOData *D)
{
	//Параллельный кусок 2 (Локальный поиск)
//    printf("Параллельный кусок 2 (Локальный поиск)\r\n");
	int topCount = 3;
	int rootTop = 3;
	GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
	return 1;
}
