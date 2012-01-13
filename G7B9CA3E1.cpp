#include "graph.h"
int P282E6F54(TPOData *D);
int PF6088A06(TPOData *D);
int PAC182156(TPOData *D);
int P151D361D(TPOData *D);
int A7D450414(TPOData *D);
int A3BE6A80A(TPOData *D);
int A4C81F17A(TPOData *D);
int A87A451F5(TPOData *D);
int A5B00D10C(TPOData *D);
int A4C236239(TPOData *D);
int A655CD1E4(TPOData *D);
int AB67B75FC(TPOData *D);
int G7B9CA3E1(TPOData *D);
int A322C6E47(TPOData *D);
static DefinePredicate ListPred[4] = {
	DefinePredicate("P282E6F54", &P282E6F54),
	DefinePredicate("PF6088A06", &PF6088A06),
	DefinePredicate("PAC182156", &PAC182156),
	DefinePredicate("P151D361D", &P151D361D)
};
static DefineTop ListTop[10] = {
	DefineTop("A3BE6A80A", 0, 0, &A3BE6A80A),
	DefineTop("A4C236239", 1, 2, &A4C236239),
	DefineTop("A7D450414", 3, 3, &A7D450414),
	DefineTop("A87A451F5", 4, 6, &A87A451F5),
	DefineTop("A655CD1E4", 7, 7, &A655CD1E4),
	DefineTop("AB67B75FC", 8, 8, &AB67B75FC),
	DefineTop("A322C6E47", 9, 9, &A322C6E47),
	DefineTop("A5B00D10C", -77, -77, &A5B00D10C),
	DefineTop("A4C81F17A", -77, -77, &A4C81F17A),
	DefineTop("A4C81F17A", 10, 10, &A4C81F17A)
};
static DefineGraph ListGraf[11] = {
	DefineGraph(0, 1),
	DefineGraph(1, 2),
	DefineGraph(0, 3),
	DefineGraph(0, 8),
	DefineGraph(3, 9),
	DefineGraph(2, 9),
	DefineGraph(0, 4),
	DefineGraph(0, 5),
	DefineGraph(0, 6),
	DefineGraph(0, 7),
	DefineGraph(0, 6)
};
int G7B9CA3E1(TPOData *D)
{
	//Прореживание квадратов
	//printf("Прореживание квадратов\r\n");
	int topCount = 10;
	int rootTop = 0;
	GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
	return 1;
}
