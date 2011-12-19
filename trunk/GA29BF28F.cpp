#include "graph.h"
int P5519A254(TPOData *D);
int P312BFCC3(TPOData *D);
int P282E6F54(TPOData *D);
int A8E248E71(TPOData *D);
int ACA6447B9(TPOData *D);
int AAFE33EBC(TPOData *D);
int A9E1CDE26(TPOData *D);
int A37CA1EE6(TPOData *D);
int GA29BF28F(TPOData *D);
int AE0C44442(TPOData *D);
static DefinePredicate ListPred[3] = {
	DefinePredicate("P5519A254", &P5519A254),
	DefinePredicate("P312BFCC3", &P312BFCC3),
	DefinePredicate("P282E6F54", &P282E6F54)
};
static DefineTop ListTop[6] = {
	DefineTop("A37CA1EE6", 0, 0, &A37CA1EE6),
	DefineTop("AE0C44442", 1, 3, &AE0C44442),
	DefineTop("AAFE33EBC", 4, 4, &AAFE33EBC),
	DefineTop("A9E1CDE26", -77, -77, &A9E1CDE26),
	DefineTop("ACA6447B9", 5, 6, &ACA6447B9),
	DefineTop("A8E248E71", 7, 7, &A8E248E71)
};
static DefineGraph ListGraf[8] = {
	DefineGraph(2, 1),
	DefineGraph(0, 4),
	DefineGraph(1, 5),
	DefineGraph(2, 2),
	DefineGraph(2, 3),
	DefineGraph(1, 5),
	DefineGraph(2, 3),
	DefineGraph(2, 3)
};
int GA29BF28F(TPOData *D)
{
	//Вычисление нового значения функции
	//printf("Вычисление нового значения функции\r\n");
	int topCount = 6;
	int rootTop = 0;
	GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
	return 1;
}
