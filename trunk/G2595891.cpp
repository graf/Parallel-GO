#include "graph.h"
int P282E6F54(TPOData *D);
int PF6088A06(TPOData *D);
int PAC182156(TPOData *D);
int P151D361D(TPOData *D);
int AC2E97CF3(TPOData *D);
int A823252EF(TPOData *D);
int A7D450414(TPOData *D);
int A3BE6A80A(TPOData *D);
int A4C81F17A(TPOData *D);
int A5B00D10C(TPOData *D);
int G2595891(TPOData *D);
int A4C236239(TPOData *D);
int A655CD1E4(TPOData *D);
int AB67B75FC(TPOData *D);
int A322C6E47(TPOData *D);
static DefinePredicate ListPred[4] = {
	DefinePredicate("P282E6F54", &P282E6F54),
	DefinePredicate("PF6088A06", &PF6088A06),
	DefinePredicate("PAC182156", &PAC182156),
	DefinePredicate("P151D361D", &P151D361D)
};
static DefineTop ListTop[11] = {
	DefineTop("A3BE6A80A", 0, 0, &A3BE6A80A),
	DefineTop("A7D450414", 1, 1, &A7D450414),
	DefineTop("A4C81F17A", -77, -77, &A4C81F17A),
	DefineTop("A4C236239", 2, 3, &A4C236239),
	DefineTop("AC2E97CF3", 4, 6, &AC2E97CF3),
	DefineTop("A655CD1E4", 7, 7, &A655CD1E4),
	DefineTop("A823252EF", 8, 8, &A823252EF),
	DefineTop("AB67B75FC", 9, 9, &AB67B75FC),
	DefineTop("A322C6E47", 10, 10, &A322C6E47),
	DefineTop("A4C81F17A", 11, 11, &A4C81F17A),
	DefineTop("A5B00D10C", -77, -77, &A5B00D10C)
};
static DefineGraph ListGraf[12] = {
	DefineGraph(0, 3),
	DefineGraph(0, 2),
	DefineGraph(1, 1),
	DefineGraph(0, 4),
	DefineGraph(3, 6),
	DefineGraph(2, 9),
	DefineGraph(0, 5),
	DefineGraph(0, 7),
	DefineGraph(0, 8),
	DefineGraph(0, 8),
	DefineGraph(0, 10),
	DefineGraph(0, 8)
};
int G2595891(TPOData *D)
{
	//Построение начальных элементов запуска ГО в параллельных ветках
//    printf("Построение начальных элементов запуска ГО в параллельных ветках\r\n");
	int topCount = 11;
	int rootTop = 0;
	GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
	return 1;
}
