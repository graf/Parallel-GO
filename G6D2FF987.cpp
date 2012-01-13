#include "graph.h"
int P282E6F54(TPOData *D);
int P36AADBB9(TPOData *D);
int PF6088A06(TPOData *D);
int P32265593(TPOData *D);
int PAC182156(TPOData *D);
int P90F7A843(TPOData *D);
int P151D361D(TPOData *D);
int P37DE52F(TPOData *D);
int P5519A254(TPOData *D);
int P2477925C(TPOData *D);
int P312BFCC3(TPOData *D);
int A87A451F5(TPOData *D);
int A19ACD2E9(TPOData *D);
int A4C236239(TPOData *D);
int A322C6E47(TPOData *D);
int A37CA1EE6(TPOData *D);
int ADE1CFBF(TPOData *D);
int AC2E97CF3(TPOData *D);
int AA1BE37B2(TPOData *D);
int AB67B75FC(TPOData *D);
int GA29BF28F(TPOData *D);
int A58101D91(TPOData *D);
int A655CD1E4(TPOData *D);
int AE226CBAF(TPOData *D);
int A63059F62(TPOData *D);
int AAFE33EBC(TPOData *D);
int A7D450414(TPOData *D);
int A823252EF(TPOData *D);
int A3BE6A80A(TPOData *D);
int AFB859466(TPOData *D);
int A4CE136AF(TPOData *D);
int G7B9CA3E1(TPOData *D);
int G7BF72D52(TPOData *D);
int G2595891(TPOData *D);
int AE0C44442(TPOData *D);
int ACA6447B9(TPOData *D);
int A4C81F17A(TPOData *D);
int G6D2FF987(TPOData *D);
int A6E9FF91F(TPOData *D);
int GEDF5070C(TPOData *D);
int A87B58126(TPOData *D);
int A8E248E71(TPOData *D);
int A5B00D10C(TPOData *D);
int ACD13BE1C(TPOData *D);
int A34FC36CB(TPOData *D);
int A75A041D3(TPOData *D);
int A3300B5FE(TPOData *D);
static DefinePredicate ListPred[11] = {
	DefinePredicate("P282E6F54", &P282E6F54),
	DefinePredicate("P36AADBB9", &P36AADBB9),
	DefinePredicate("PF6088A06", &PF6088A06),
	DefinePredicate("P32265593", &P32265593),
	DefinePredicate("PAC182156", &PAC182156),
	DefinePredicate("P90F7A843", &P90F7A843),
	DefinePredicate("P151D361D", &P151D361D),
	DefinePredicate("P37DE52F", &P37DE52F),
	DefinePredicate("P5519A254", &P5519A254),
	DefinePredicate("P2477925C", &P2477925C),
	DefinePredicate("P312BFCC3", &P312BFCC3)
};
static DefineTop ListTop[8] = {
	DefineTop("A4CE136AF", 0, 0, &A4CE136AF),
	DefineTop("AFB859466", 1, 1, &AFB859466),
	DefineTop("ACD13BE1C", 2, 2, &ACD13BE1C),
	DefineTop("AA1BE37B2", 3, 4, &AA1BE37B2),
	DefineTop("G7BF72D52", 5, 6, &G7BF72D52),
	DefineTop("A58101D91", 7, 8, &A58101D91),
	DefineTop("A34FC36CB", -77, -77, &A34FC36CB),
	DefineTop("A19ACD2E9", -77, -77, &A19ACD2E9)
};
static DefineGraph ListGraf[9] = {
	DefineGraph(0, 4),
	DefineGraph(0, 0),
	DefineGraph(0, 1),
	DefineGraph(3, 2),
	DefineGraph(0, 5),
	DefineGraph(7, 5),
	DefineGraph(0, 3),
	DefineGraph(9, 7),
	DefineGraph(0, 6)
};
int G6D2FF987(TPOData *D)
{
	//Базовый модуль разделения списка ведущих вершин
//    printf("Базовый модуль разделения списка ведущих вершин\r\n");
	int topCount = 8;
	int rootTop = 2;
	GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
	return 1;
}
