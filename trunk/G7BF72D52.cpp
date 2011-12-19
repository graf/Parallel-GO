#include "graph.h"
int P66BC8002(TPOData *D);
int P5519A254(TPOData *D);
int P90F7A843(TPOData *D);
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
int A63059F62(TPOData *D);
int A3BE6A80A(TPOData *D);
int A58101D91(TPOData *D);
int G7BF72D52(TPOData *D);
int AE226CBAF(TPOData *D);
int GEDF5070C(TPOData *D);
int A5B00D10C(TPOData *D);
int A87B58126(TPOData *D);
int AE0C44442(TPOData *D);
int AAFE33EBC(TPOData *D);
int A6E9FF91F(TPOData *D);
int A9E1CDE26(TPOData *D);
int A75A041D3(TPOData *D);
int ACA6447B9(TPOData *D);
int A4C236239(TPOData *D);
static DefinePredicate ListPred[8] = {
	DefinePredicate("P66BC8002", &P66BC8002),
	DefinePredicate("P5519A254", &P5519A254),
	DefinePredicate("P90F7A843", &P90F7A843),
	DefinePredicate("PAC182156", &PAC182156),
	DefinePredicate("PF6088A06", &PF6088A06),
	DefinePredicate("P312BFCC3", &P312BFCC3),
	DefinePredicate("P36AADBB9", &P36AADBB9),
	DefinePredicate("P282E6F54", &P282E6F54)
};
static DefineTop ListTop[7] = {
	DefineTop("A58101D91", 0, 1, &A58101D91),
	DefineTop("A63059F62", 2, 2, &A63059F62),
	DefineTop("A6E9FF91F", 3, 3, &A6E9FF91F),
	DefineTop("AE226CBAF", 4, 4, &AE226CBAF),
	DefineTop("GEDF5070C", 5, 5, &GEDF5070C),
	DefineTop("A87B58126", 6, 6, &A87B58126),
	DefineTop("GEDF5070C", -77, -77, &GEDF5070C)
};
static DefineGraph ListGraf[7] = {
	DefineGraph(2, 1),
	DefineGraph(7, 2),
	DefineGraph(7, 2),
	DefineGraph(7, 3),
	DefineGraph(7, 4),
	DefineGraph(7, 5),
	DefineGraph(7, 6)
};
int G7BF72D52(TPOData *D)
{
	//Двоичное деление области поиска
	//printf("Двоичное деление области поиска\r\n");
	int topCount = 7;
	int rootTop = 0;
	GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
	return 1;
}
