#ifndef UTILS_H
#define UTILS_H
#include "utype.h"

MPAR2 Mpar_2_Mpar2(const MPAR &src);
MPAR Mpar2_2_Mpar(const MPAR2 &src);
void log2file(const char* msg);
void printf_QVAD2(QVAD2 q);
void printf_QVADPL(QVADPL qvadpl);
void printf_QVAD2S(QVAD2S q);
void printf_LMAXPL(LMAXPL lmaxpl);
void printf_QVADPL(QVADPL qvadpl);
void printf_LMAXS(LMAXS l);

#endif // UTILS_H
