#include "tpodata.h"
#ifdef PARALLEL
#include <mpi.h>

int memman(TPOData *D)
{
    int Terminate = 0;
    MemoryPacket p;
    printf("memmanager: run\r\n");
    
    while (!Terminate) {
        MPI_Recv(&p, 1, memoryPacketDatatype, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        if (status.MPI_TAG != MPI_TAG_TERMINATE) {
            if (status.MPI_TAG == MPI_TAG_GETDATA) {
                MPI_Send((char *)D->getDataAddr(p.id)+(p.offset*D->getDataSize(p.id)), p.count, D->getMpiType(p.id), status.MPI_SOURCE, MPI_TAG_ACTUALDATA, MPI_COMM_WORLD);
            } else if (status.MPI_TAG == MPI_TAG_PUTDATA) {
                MPI_Recv((char *)D->getDataAddr(p.id)+(p.offset*D->getDataSize(p.id)), p.count, D->getMpiType(p.id), status.MPI_SOURCE, MPI_TAG_ACTUALDATA, MPI_COMM_WORLD, &status);
            }
        } else Terminate = true;
    }
    
    printf("memmanager: terminated\r\n");
    return 1;
}
#endif
