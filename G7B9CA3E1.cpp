#include "graph.h"
int PAC182156(TPOData *D);
int P282E6F54(TPOData *D);
int PF6088A06(TPOData *D);
int P81F94AA6(TPOData *D);
int A4C236239(TPOData *D);
int A322C6E47(TPOData *D);
int A3BE6A80A(TPOData *D);
int A655CD1E4(TPOData *D);
int A7D450414(TPOData *D);
int AB67B75FC(TPOData *D);
int A5B00D10C(TPOData *D);
int A87A451F5(TPOData *D);
int G7B9CA3E1(TPOData *D);
static DefinePredicate ListPred[4] = {
	DefinePredicate("PAC182156", &PAC182156),
	DefinePredicate("P282E6F54", &P282E6F54),
	DefinePredicate("PF6088A06", &PF6088A06),
	DefinePredicate("P81F94AA6", &P81F94AA6)
};
static DefineTop ListTop[8] = {
	DefineTop("A3BE6A80A", 0, 0, &A3BE6A80A),
	DefineTop("A4C236239", 1, 2, &A4C236239),
	DefineTop("A7D450414", -77, -77, &A7D450414),
	DefineTop("A87A451F5", 3, 5, &A87A451F5),
	DefineTop("A655CD1E4", 6, 6, &A655CD1E4),
	DefineTop("AB67B75FC", 7, 7, &AB67B75FC),
	DefineTop("A322C6E47", 8, 8, &A322C6E47),
	DefineTop("A5B00D10C", -77, -77, &A5B00D10C)
};
static DefineGraph ListGraf[9] = {
	DefineGraph(1, 1),
	DefineGraph(2, 2),
	DefineGraph(1, 3),
	DefineGraph(3, 6),
	DefineGraph(0, 6),
	DefineGraph(1, 4),
	DefineGraph(1, 5),
	DefineGraph(1, 6),
	DefineGraph(1, 7)
};
int G7B9CA3E1(TPOData *D)
{
	//Прореживание квадратов
	//printf("Прореживание квадратов\r\n");
	int topCount = 8;
	int rootTop = 0;
	GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
	return 1;
}
