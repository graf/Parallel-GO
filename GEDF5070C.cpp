#include "graph.h"
int P66BC8002(TPOData *D);
int P5519A254(TPOData *D);
int PAC182156(TPOData *D);
int PF6088A06(TPOData *D);
int P312BFCC3(TPOData *D);
int P36AADBB9(TPOData *D);
int P282E6F54(TPOData *D);
int A655CD1E4(TPOData *D);
int A87A451F5(TPOData *D);
int GA29BF28F(TPOData *D);
int AB67B75FC(TPOData *D);
int A37CA1EE6(TPOData *D);
int A322C6E47(TPOData *D);
int A8E248E71(TPOData *D);
int ADE1CFBF(TPOData *D);
int A7D450414(TPOData *D);
int G7B9CA3E1(TPOData *D);
int A3BE6A80A(TPOData *D);
int A58101D91(TPOData *D);
int GEDF5070C(TPOData *D);
int A5B00D10C(TPOData *D);
int AE0C44442(TPOData *D);
int AAFE33EBC(TPOData *D);
int A9E1CDE26(TPOData *D);
int A75A041D3(TPOData *D);
int ACA6447B9(TPOData *D);
int A4C236239(TPOData *D);
static DefinePredicate ListPred[7] = {
	DefinePredicate("P66BC8002", &P66BC8002),
	DefinePredicate("P5519A254", &P5519A254),
	DefinePredicate("PAC182156", &PAC182156),
	DefinePredicate("PF6088A06", &PF6088A06),
	DefinePredicate("P312BFCC3", &P312BFCC3),
	DefinePredicate("P36AADBB9", &P36AADBB9),
	DefinePredicate("P282E6F54", &P282E6F54)
};
static DefineTop ListTop[5] = {
	DefineTop("GA29BF28F", 0, 0, &GA29BF28F),
	DefineTop("A75A041D3", 1, 1, &A75A041D3),
	DefineTop("A58101D91", 2, 3, &A58101D91),
	DefineTop("ADE1CFBF", 4, 4, &ADE1CFBF),
	DefineTop("G7B9CA3E1", -77, -77, &G7B9CA3E1)
};
static DefineGraph ListGraf[5] = {
	DefineGraph(6, 1),
	DefineGraph(6, 2),
	DefineGraph(5, 3),
	DefineGraph(6, 4),
	DefineGraph(6, 4)
};
int GEDF5070C(TPOData *D)
{
	//Вычисление характеристик областей
	//printf("Вычисление характеристик областей\r\n");
	int topCount = 5;
	int rootTop = 0;
	GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
	return 1;
}
