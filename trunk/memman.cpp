#include "tpodata.h"
#ifdef PARALLEL
#include <mpi.h>
#include <omp.h>

int memman(TPOData *D)
{
    omp_set_num_threads(totalProc);
#pragma omp parallel private(status)
    {
        int i = omp_get_thread_num();
        int provided_level_thread_support;
        MPI_Query_thread(&provided_level_thread_support);
        int Terminate = 0;
        MemoryPacket p;
        MPI_Status status;
        printf("memmanager for process %d: run. Provided level of thread support %d\r\n", i, provided_level_thread_support);
        while (!Terminate) {
            MPI_Recv(&p, 1, memoryPacketDatatype, i+1, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            if (status.MPI_TAG != MPI_TAG_TERMINATE) {
                if (status.MPI_TAG == MPI_TAG_GETDATA) {
                    MPI_Send((char *)D->getDataAddr(p.id)+(p.offset*D->getDataSize(p.id)), p.count, D->getMpiType(p.id), status.MPI_SOURCE, MPI_TAG_ACTUALDATA, MPI_COMM_WORLD);
                } else if (status.MPI_TAG == MPI_TAG_PUTDATA) {
                    MPI_Recv((char *)D->getDataAddr(p.id)+(p.offset*D->getDataSize(p.id)), p.count, D->getMpiType(p.id), status.MPI_SOURCE, MPI_TAG_ACTUALDATA, MPI_COMM_WORLD, &status);
                }
            } else Terminate = true;
        }
    }
    
    printf("memmanager: terminated\r\n");
    return 1;
}
#endif
