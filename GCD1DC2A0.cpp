#include "graph.h"
int PE6F9C907(TPOData *D);
int P312BFCC3(TPOData *D);
int P5519A254(TPOData *D);
int P282E6F54(TPOData *D);
int P37DE52F(TPOData *D);
int P1D6BE722(TPOData *D);
int P99390B2F(TPOData *D);
int P6D120035(TPOData *D);
int AAA1FF769(TPOData *D);
int G687361DD(TPOData *D);
int AC474C1C6(TPOData *D);
int G65DF6ACB(TPOData *D);
int AC9F60AD(TPOData *D);
int AAFE33EBC(TPOData *D);
int A37CA1EE6(TPOData *D);
int A6F8E0D5D(TPOData *D);
int AC4C482F7(TPOData *D);
int GA29BF28F(TPOData *D);
int A8E248E71(TPOData *D);
int A856CFAD2(TPOData *D);
int G15C01624(TPOData *D);
int ABE3B97B1(TPOData *D);
int A3B5EB18E(TPOData *D);
int AA72B0A89(TPOData *D);
int A655CD1E4(TPOData *D);
int A3C94B0E7(TPOData *D);
int A3300B5FE(TPOData *D);
int A58101D91(TPOData *D);
int A3E1AF896(TPOData *D);
int A9D1C7CCE(TPOData *D);
int G83ADDA90(TPOData *D);
int A68D78CB2(TPOData *D);
int AAB2621AD(TPOData *D);
int GCF2DCA96(TPOData *D);
int A4CE136AF(TPOData *D);
int GCD1DC2A0(TPOData *D);
int A11D28C4A(TPOData *D);
int A50515E14(TPOData *D);
int G1F38B331(TPOData *D);
int AE0DB6BEB(TPOData *D);
int A5BFABC49(TPOData *D);
int A3FBDF9D1(TPOData *D);
int AB20CC9C7(TPOData *D);
int A34FC36CB(TPOData *D);
int AE0C44442(TPOData *D);
int G3A13E4E6(TPOData *D);
int AC8A7352(TPOData *D);
int AF7F684BF(TPOData *D);
int A8BAF7ABB(TPOData *D);
int A47C88229(TPOData *D);
int ACA6447B9(TPOData *D);
static DefinePredicate ListPred[8] = {
	DefinePredicate("PE6F9C907", &PE6F9C907),
	DefinePredicate("P312BFCC3", &P312BFCC3),
	DefinePredicate("P5519A254", &P5519A254),
	DefinePredicate("P282E6F54", &P282E6F54),
	DefinePredicate("P37DE52F", &P37DE52F),
	DefinePredicate("P1D6BE722", &P1D6BE722),
	DefinePredicate("P99390B2F", &P99390B2F),
	DefinePredicate("P6D120035", &P6D120035)
};
static DefineTop ListTop[17] = {
	DefineTop("GHOST TOP", -77, -77, NULL),
	DefineTop("GHOST TOP", -77, -77, NULL),
	DefineTop("GHOST TOP", -77, -77, NULL),
	DefineTop("GHOST TOP", -77, -77, NULL),
	DefineTop("A68D78CB2", 0, 0, &A68D78CB2),
	DefineTop("GA29BF28F", 1, 1, &GA29BF28F),
	DefineTop("A5BFABC49", 2, 2, &A5BFABC49),
	DefineTop("A655CD1E4", 3, 3, &A655CD1E4),
	DefineTop("A3B5EB18E", 4, 4, &A3B5EB18E),
	DefineTop("G1F38B331", 5, 5, &G1F38B331),
	DefineTop("GCF2DCA96", 6, 6, &GCF2DCA96),
	DefineTop("GHOST TOP", -77, -77, NULL),
	DefineTop("G83ADDA90", 7, 7, &G83ADDA90),
	DefineTop("G3A13E4E6", 8, 8, &G3A13E4E6),
	DefineTop("A856CFAD2", -77, -77, &A856CFAD2),
	DefineTop("G65DF6ACB", 9, 10, &G65DF6ACB),
	DefineTop("A11D28C4A", 11, 11, &A11D28C4A)
};
static DefineGraph ListGraf[12] = {
	DefineGraph(3, 5),
	DefineGraph(3, 6),
	DefineGraph(3, 7),
	DefineGraph(3, 8),
	DefineGraph(3, 9),
	DefineGraph(3, 10),
	DefineGraph(3, 16),
	DefineGraph(3, 15),
	DefineGraph(3, 14),
	DefineGraph(0, 13),
	DefineGraph(3, 12),
	DefineGraph(3, 12)
};
int GCD1DC2A0(TPOData *D)
{
	//(2 этапа) Параллельная ГО методом деления симплексов
	//printf("(2 этапа) Параллельная ГО методом деления симплексов\r\n");
	int topCount = 12;
	int rootTop = 4;
	GraphMV(D, rootTop, topCount, ListPred, ListTop, ListGraf);
	return 1;
}
