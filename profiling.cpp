#include <stdio.h>
#include "profiling.h"
#include "utype.h"

void printf_profile() {
    if (myProcNum == -1)
        return;
    printf("Process %d: G15C01624 time about %g sec\r\n", myProcNum, G15C01624_time);
    printf("Process %d: GCF2DCA96 time about %g sec\r\n", myProcNum, GCF2DCA96_time);
    printf("Process %d: AA72B0A89 time about %g sec\r\n", myProcNum, AA72B0A89_time);
    printf("Process %d: AE0DB6BEB time about %g sec\r\n", myProcNum, AE0DB6BEB_time);
}
