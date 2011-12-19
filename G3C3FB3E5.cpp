#include "graph.h"
int P27B846B(TPOData *D);
int P9D30AA17(TPOData *D);
int P37DE52F(TPOData *D);
int P282E6F54(TPOData *D);
int G3C3FB3E5(TPOData *D);
int A4CE136AF(TPOData *D);
int A34FC36CB(TPOData *D);
int A58101D91(TPOData *D);
int ACD13BE1C(TPOData *D);
static DefinePredicate ListPred[4] = {
	DefinePredicate("P27B846B", &P27B846B),
	DefinePredicate("P9D30AA17", &P9D30AA17),
	DefinePredicate("P37DE52F", &P37DE52F),
	DefinePredicate("P282E6F54", &P282E6F54)
};
static DefineTop ListTop[4] = {
	DefineTop("ACD13BE1C", 0, 1, &ACD13BE1C),
	DefineTop("A58101D91", 2, 3, &A58101D91),
	DefineTop("A4CE136AF", 4, 5, &A4CE136AF),
	DefineTop("A34FC36CB", -77, -77, &A34FC36CB)
};
static DefineGraph ListGraf[6] = {
	DefineGraph(0, 3),
	DefineGraph(3, 1),
	DefineGraph(1, 2),
	DefineGraph(3, 3),
	DefineGraph(2, 3),
	DefineGraph(3, 0)
};
int G3C3FB3E5(TPOData *D)
{
	//Отбраковка квадратов, чтение-удаление
	//printf("Отбраковка квадратов, чтение-удаление\r\n");
	int topCount = 4;
	int rootTop = 0;
	GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
	return 1;
}
