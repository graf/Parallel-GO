#include "graph.h"
int P5519A254(TPOData *D);
int P77F15A6D(TPOData *D);
int PBEBB3B79(TPOData *D);
int P27B846B(TPOData *D);
int P66BC8002(TPOData *D);
int PAC182156(TPOData *D);
int P282E6F54(TPOData *D);
int P90F7A843(TPOData *D);
int P37DE52F(TPOData *D);
int P9D30AA17(TPOData *D);
int P36AADBB9(TPOData *D);
int P312BFCC3(TPOData *D);
int PF6088A06(TPOData *D);
int A8E248E71(TPOData *D);
int ACD13BE1C(TPOData *D);
int AFB859466(TPOData *D);
int A58101D91(TPOData *D);
int G7BF72D52(TPOData *D);
int A63059F62(TPOData *D);
int G3C3FB3E5(TPOData *D);
int A322C6E47(TPOData *D);
int AA1BE37B2(TPOData *D);
int A3BE6A80A(TPOData *D);
int ADE1CFBF(TPOData *D);
int A7D450414(TPOData *D);
int AB67B75FC(TPOData *D);
int AE226CBAF(TPOData *D);
int AE5EA5591(TPOData *D);
int ACA6447B9(TPOData *D);
int AE0C44442(TPOData *D);
int AAFE33EBC(TPOData *D);
int GEDF5070C(TPOData *D);
int A75A041D3(TPOData *D);
int GA29BF28F(TPOData *D);
int A6E9FF91F(TPOData *D);
int A655CD1E4(TPOData *D);
int G6D2FF987(TPOData *D);
int A4C236239(TPOData *D);
int A87A451F5(TPOData *D);
int A9E1CDE26(TPOData *D);
int A37CA1EE6(TPOData *D);
int A4CE136AF(TPOData *D);
int G7B9CA3E1(TPOData *D);
int A5B00D10C(TPOData *D);
int A34FC36CB(TPOData *D);
int A87B58126(TPOData *D);
static DefinePredicate ListPred[13] = {
DefinePredicate("P5519A254", &P5519A254),
DefinePredicate("P77F15A6D", &P77F15A6D),
DefinePredicate("PBEBB3B79", &PBEBB3B79),
DefinePredicate("P27B846B", &P27B846B),
DefinePredicate("P66BC8002", &P66BC8002),
DefinePredicate("PAC182156", &PAC182156),
DefinePredicate("P282E6F54", &P282E6F54),
DefinePredicate("P90F7A843", &P90F7A843),
DefinePredicate("P37DE52F", &P37DE52F),
DefinePredicate("P9D30AA17", &P9D30AA17),
DefinePredicate("P36AADBB9", &P36AADBB9),
DefinePredicate("P312BFCC3", &P312BFCC3),
DefinePredicate("PF6088A06", &PF6088A06)
};
static DefineTop ListTop[7] = {
DefineTop("A4CE136AF", 0, 0, &A4CE136AF),
DefineTop("AFB859466", 1, 1, &AFB859466),
DefineTop("G3C3FB3E5", 2, 2, &G3C3FB3E5),
DefineTop("AA1BE37B2", 3, 4, &AA1BE37B2),
DefineTop("G7BF72D52", 5, 7, &G7BF72D52),
DefineTop("A34FC36CB", -77, -77, &A34FC36CB),
DefineTop("AE5EA5591", 8, 8, &AE5EA5591)
};
static DefineGraph ListGraf[9] = {
DefineGraph(6, 6),
DefineGraph(6, 0),
DefineGraph(6, 1),
DefineGraph(1, 2),
DefineGraph(6, 5),
DefineGraph(8, 5),
DefineGraph(2, 5),
DefineGraph(6, 3),
DefineGraph(6, 4)
};
int G6D2FF987(TPOData *D)
{
//Базовый модуль разделения списка ведущих вершин
//printf("Базовый модуль разделения списка ведущих вершин\r\n");
int topCount = 7;
int rootTop = 2;
GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
return 1;
}
