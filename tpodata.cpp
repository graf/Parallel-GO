#include "tpodata.h"
#include <string.h>
#include "mpi.h"
#include <limits.h>

MPI_Datatype memoryPacketDatatype;
MPI_Datatype MPI_USER_TYPE_QVAD2;
MPI_Datatype MPI_USER_TYPE_MPAR2;
MPI_Datatype MPI_USER_TYPE_LMAX;
MPI_Datatype MPI_USER_TYPE_QVADPL;
MPI_Datatype MPI_USER_TYPE_LMAXPL;

MPI_Status status;
int myProcNum, totalProc;

TPOData::TPOData(int rank)
{
    myRank = rank;
    initMemory();
    initId();
    totalDataOperationsTime = 0;
    totalFuncCalls = 0;

    MQVAD.Assign(this, &TPOData::set_MQVAD, &TPOData::get_MQVAD, &TPOData::set_MQVAD, &TPOData::get_MQVAD, QVADArray_LENGTH);
    NF.Assign(this, &TPOData::set_NF, &TPOData::get_NF, &TPOData::set_NF, &TPOData::get_NF, ArrayOfLong_LENGTH);
    MQVAD_len.Assign(this, &TPOData::set_MQVAD_len, &TPOData::get_MQVAD_len, &TPOData::set_MQVAD_len, &TPOData::get_MQVAD_len, ArrayOfLong_LENGTH);
    Estron_p.Assign(this, &TPOData::set_Estron, &TPOData::get_Estron);
    NFUNC_p.Assign(this, &TPOData::set_NFUNC, &TPOData::get_NFUNC);
    Nlok_p.Assign(this, &TPOData::set_Nlok, &TPOData::get_Nlok);
    lx_p.Assign(this, &TPOData::set_lx, &TPOData::get_lx);
    KlocMax_p.Assign(this, &TPOData::set_KlocMax, &TPOData::get_KlocMax);
    mmax_p.Assign(this, &TPOData::set_mmax, &TPOData::get_mmax);
    zp1_p.Assign(this, &TPOData::set_zp1, &TPOData::get_zp1);
    Akfun_p.Assign(this, &TPOData::set_Akfun, &TPOData::get_Akfun);
    HTMAX_p.Assign(this, &TPOData::set_HTMAX_p, &TPOData::get_HTMAX_p, &TPOData::set_HTMAX_p, &TPOData::get_HTMAX_p, ArrayOfLMAX_LENGTH);
    HTMAX_len.Assign(this, &TPOData::set_HTMAX_len, &TPOData::get_HTMAX_len, &TPOData::set_HTMAX_len, &TPOData::get_HTMAX_len, ArrayOfLong_LENGTH);
    HTMAX_GB.Assign(this, &TPOData::set_HTMAX_GB, &TPOData::get_HTMAX_GB, &TPOData::set_HTMAX_GB, &TPOData::get_HTMAX_GB, ArrayOfLMAXPL_LENGTH);
    MQVAD_GB.Assign(this, &TPOData::set_MQVAD_GB, &TPOData::get_MQVAD_GB, &TPOData::set_MQVAD_GB, &TPOData::get_MQVAD_GB, ArrayOfQVADPL_LENGTH);
    zp_max.Assign(this, &TPOData::set_zp_max, &TPOData::get_zp_max, &TPOData::set_zp_max, &TPOData::get_zp_max, ArrayOFFUNC_LENGTH);
}

TPOData::~TPOData()
{
    delete Akfun;
    delete Diag;
    delete Eloc;
    delete Esimp;
    delete Estron;
    delete Flif;
    delete GKLtip;
    delete HXMAX;
    delete Hbd;
    delete Hq2;
    delete Hqva;
    delete Htmax;
    delete ILok;
    delete KlocMax;
    delete Kobl;
    delete Krep;
    delete Ksum;
    delete Kz;
    delete Lip;
    delete Lor;
    delete LorQ;
    delete MaxF;
    delete MaxPRL;
    delete NFUNC;
    delete N_fun;
    delete Nbd;
    delete Nloc0;
    delete Nlok;
    delete Nmax;
    delete Nmax2;
    delete NprlTec;
    delete Nsimp;
    delete Nstep;
    delete Ntern;
    delete PRLp;
    delete Reset;
    delete Simpmax;
    delete Str;
    delete Sumstep;
    delete X;
    delete X0;
    delete Zmax;
    delete d2z;
    delete hx;
    delete iNX;
    delete j1;
    delete j2;
    delete j6;
    delete kDi;
    delete lx;
    delete maxhx;
    delete mi;
    delete mmax;
    delete r;
    delete w0;
    delete wmax;
    delete wmin;
    delete wold;
    delete x0;
    delete xp1;
    delete xp2;
    delete z2;
    delete zmin;
    delete zp1;
    delete zp2;

    //delete _MQVAD_len;
    //delete _MQVAD;
    //delete _NF;
    //delete _Estron;
    //delete _NFUNC;
    //delete _Nlok;
    //delete _lx;
    //delete _mmax;
    //delete _zp1;
    //delete _KlocMax;
    //delete _Akfun;
    //delete _HTMAX_p;
    //delete _HTMAX_len;
}

void TPOData::initMemory()
{
    *(Akfun = new MPAR);
    *(Diag = new double) = 0;
    *(Eloc = new double) = 0.33;
    *(Esimp = new double) = 1.0e-5;
    *(Estron = new double) = 0.032;
    *(Flif = new int) = 0;
    *(GKLtip = new int) = 3;
    *(HXMAX = new LMAXS) = NULL;
    *(Hbd = new int) = 0;
    *(Hq2 = new QVAD2S);
    *(Hqva = new QVAD2S) = NULL;
    *(Htmax = new LMAXS) = NULL;
    *(ILok = new int) = 0;
    *(KlocMax = new int) = 99; //!!!!!!!!!!!!!
    *(Kobl = new double) = 10;
    *(Krep = new int) = 50;  //!!!!!!!!!!
    *(Ksum = new double) = 0;
    *(Kz = new double);
    *(Lip = new double) = 170;
    *(Lor = new int) = 0;
    *(LorQ = new int) = 0;
    *(MaxF = new long) = 0;
    *(MaxPRL = new int) = 0;
    *(NFUNC = new int) = 24; //21
    *(N_fun = new int) = 4; //!!!!!!!!!!!!!!!!
    *(Nbd = new int) = 1;
    *(Nloc0 = new int) = 2; //!!!!!!!!!!!
    *(Nlok = new int) = 65536*2;
    *(Nmax = new int) = 0;
    *(Nmax2 = new int) = 0;
    *(NprlTec = new int) = 0;
    *(Nsimp = new int) = 1;
    *(Nstep = new long) = 0;
    *(Ntern = new int) = 0;
    *(PRLp = new SEGM);
    *(Reset = new int) = 0;
    *(Simpmax = (XIF *) new XIF);
    *(Str = new double) = 0;
    *(Sumstep = new long) = 0;
    *(X = (XI *)new XI);
    *(X0 = (XI *)new XI);
    *(Zmax = new FUNC) = -1.0e77;
    *(d2z = new double) = 0;
    *(hx = new double) = 0.5;
    *(iNX = new int) = TOTAL_PROCS_NUMBER-1;
    *(j1 = new int) = 0;
    *(j2 = new int) = 0;
    *(j6 = new int) = 0;
    *(kDi = new int) = 1;
    *(lx = new double) = 0.032;
    *(maxhx = new double) = 0;
    *(mi = new double) = 1;
    *(mmax = new double) = 0;
    *(r = new double) = 1.0;
    *(w0 = new double) = 0;
    *(wmax = new FUNC) = -1.0e77;
    *(wmin = new FUNC) = -1.0e77;
    *(wold = new FUNC) = 0;
    *(x0 = new double) = 0;
    *(xp1 = (XI *)new XI);
    *(xp2 = (XI *)new XI);
    *(z2 = new FUNC) = 0;
    *(zmin = new FUNC) = 1.0e77;
    *(zp1 = new FUNC) = -1.0e77;
    *(zp2 = new FUNC) = 1.0e77;


    if  (myRank == 0) {
        _MQVAD = (QVADArray*)(new QVADArray);
        _NF = (ArrayOfLong*)(new ArrayOfLong);
        _MQVAD_len = (ArrayOfLong*)(new ArrayOfLong);
        _HTMAX_p = (ArrayOfLMAX*)(new ArrayOfLMAX);
        _HTMAX_len = (ArrayOfLong*)(new ArrayOfLong);
        _HTMAX_GB = (ArrayOfLMAXPL*)(new ArrayOfLMAXPL);
        _MQVAD_GB = (ArrayOfQVADPL*)(new ArrayOfQVADPL);
        _zp_max = (ArrayOFFUNC*)(new ArrayOFFUNC);
        _Estron = Estron;
        _NFUNC = NFUNC;
        _Nlok = Nlok;
        _lx = lx;
        _mmax = mmax;
        _zp1 = zp1;
        _KlocMax = KlocMax;
        _Akfun = new MPAR2;
    }
    else {
        _MQVAD = NULL;
        _NF = NULL;
        _MQVAD_len = NULL;
        _Estron = NULL;
        _NFUNC = NULL;
        _HTMAX_GB = NULL;
        _MQVAD_GB = NULL;
        _Nlok = NULL;
        _lx = NULL;
        _mmax = NULL;
        _zp1 = NULL;
        _KlocMax = NULL;
        _Akfun = NULL;
        _HTMAX_p = NULL;
        _HTMAX_len = NULL;
        _zp_max = NULL;
    }

}

void TPOData::initId() {
    Estron_id = 4;
    KlocMax_id = 13;
    MQVAD_id = 21;
    HTMAX_p_id = 7;
    HTMAX_GB_id = 8;
    NF_id = 24;
    MQVAD_GB_id = 42;
    NFUNC_id = 25;
    Nlok_id = 29;
    lx_id = 51;
    mmax_id = 54;
    zp1_id = 66;
    HTMAX_len_id = 67;
    MQVAD_len_id = 68;
    Akfun_id = 666;
    zp_max_id = 70;
}

void* TPOData::getDataAddr(int id)
{
    void* result = NULL;
    switch (id) {
    case 4:
        result = _Estron;
        break;
    case 7:
        result = _HTMAX_p;
        break;
    case 8:
        result = _HTMAX_GB;
        break;
    case 13:
        result = _KlocMax;
        break;
    case 21:
        result = _MQVAD;
        break;
    case 24:
        result = _NF;
        break;
    case 25:
        result = _NFUNC;
        break;
    case 29:
        result = _Nlok;
        break;
    case 42:
        result = _MQVAD_GB;
        break;
    case 51:
        result = _lx;
        break;
    case 54:
        result = _mmax;
        break;
    case 66:
        result = _zp1;
        break;
    case 67:
        result = _HTMAX_len;
        break;
    case 68:
        result = _MQVAD_len;
        break;
    case 666:
        result = _Akfun;
        break;
    case 70:
        result = _zp_max;
        break;
    }
    return result;
}

int TPOData::getDataSize(int id)
{
    int result = 0;
    switch (id) {
    case 4:
        result = sizeof(double);
        break;
    case 7:
        result = sizeof(LMAX);
        break;
    case 8:
        result = sizeof(LMAXPL);
        break;
    case 42:
        result = sizeof(QVADPL);
        break;
    case 13:
        result = sizeof(int);
        break;
    case 21:
        result = sizeof(QVAD2);
        break;
    case 24:
        result = sizeof(long);
        break;
    case 25:
        result = sizeof(int);
        break;
    case 29:
        result = sizeof(int);
        break;
    case 51:
        result = sizeof(double);
        break;
    case 54:
        result = sizeof(double);
        break;
    case 66:
        result = sizeof(FUNC);
        break;
    case 67:
        result = sizeof(long);
        break;
    case 68:
        result = sizeof(long);
        break;
    case 666:
        result = sizeof(MPAR2);
        break;
    case 70:
        result = sizeof(FUNC);
        break;
    }
    return result;
}

#ifdef PARALLEL
MPI_Datatype TPOData::getMpiType(int id)
{
    MPI_Datatype result = MPI_INT;
    switch (id) {
    case 1:
        result = MPI_DOUBLE;
        break;
    case 2:
        result = MPI_DOUBLE;
        break;
    case 3:
        result = MPI_DOUBLE;
        break;
    case 4:
        result = MPI_DOUBLE;
        break;
    case 5:
        result = MPI_INT;
        break;
    case 6:
        result = MPI_INT;
        break;
    case 7:
        result = MPI_USER_TYPE_LMAX;
        break;
    case 8:
        result = MPI_USER_TYPE_ARRAYOFLMAXPL;
        break;
    case 12:
        result = MPI_INT;
        break;
    case 13:
        result = MPI_INT;
        break;
    case 14:
        result = MPI_DOUBLE;
        break;
    case 15:
        result = MPI_INT;
        break;
    case 16:
        result = MPI_DOUBLE;
        break;
    case 17:
        result = MPI_DOUBLE;
        break;
    case 18:
        result = MPI_DOUBLE;
        break;
    case 19:
        result = MPI_INT;
        break;
    case 20:
        result = MPI_INT;
        break;
    case 21:
        result = MPI_USER_TYPE_QVADARRAY;
        break;
    case 22:
        result = MPI_LONG;
        break;
    case 23:
        result = MPI_INT;
        break;
    case 24:
        result = MPI_USER_TYPE_ARRAYOFLONG;
        break;
    case 42:
        result = MPI_USER_TYPE_ARRAYOFQVADPL;
        break;
    case 25:
        result = MPI_INT;
        break;
    case 26:
        result = MPI_INT;
        break;
    case 27:
        result = MPI_INT;
        break;
    case 28:
        result = MPI_INT;
        break;
    case 29:
        result = MPI_INT;
        break;
    case 30:
        result = MPI_INT;
        break;
    case 31:
        result = MPI_INT;
        break;
    case 32:
        result = MPI_INT;
        break;
    case 33:
        result = MPI_INT;
        break;
    case 34:
        result = MPI_LONG;
        break;
    case 35:
        result = MPI_INT;
        break;
    case 37:
        result = MPI_INT;
        break;
    case 39:
        result = MPI_DOUBLE;
        break;
    case 40:
        result = MPI_LONG;
        break;
    case 43:
        result = MPI_USER_TYPE_FUNC;
        break;
    case 44:
        result = MPI_DOUBLE;
        break;
    case 45:
        result = MPI_DOUBLE;
        break;
    case 46:
        result = MPI_INT;
        break;
    case 47:
        result = MPI_INT;
        break;
    case 48:
        result = MPI_INT;
        break;
    case 49:
        result = MPI_INT;
        break;
    case 50:
        result = MPI_INT;
        break;
    case 51:
        result = MPI_DOUBLE;
        break;
    case 52:
        result = MPI_DOUBLE;
        break;
    case 53:
        result = MPI_DOUBLE;
        break;
    case 54:
        result = MPI_DOUBLE;
        break;
    case 56:
        result = MPI_DOUBLE;
        break;
    case 57:
        result = MPI_DOUBLE;
        break;
    case 58:
        result = MPI_USER_TYPE_FUNC;
        break;
    case 59:
        result = MPI_USER_TYPE_FUNC;
        break;
    case 60:
        result = MPI_USER_TYPE_FUNC;
        break;
    case 61:
        result = MPI_DOUBLE;
        break;
    case 64:
        result = MPI_USER_TYPE_FUNC;
        break;
    case 65:
        result = MPI_USER_TYPE_FUNC;
        break;
    case 66:
        result = MPI_USER_TYPE_FUNC;
        break;
    case 67:
        result = MPI_USER_TYPE_ARRAYOFLONG;
        break;
    case 68:
        result = MPI_USER_TYPE_ARRAYOFLONG;
        break;
    case 666:
        result = MPI_USER_TYPE_MPAR2;
        break;
    case 70:
        result = MPI_USER_TYPE_ARRAYOFFUNC;
        break;
    }
    return result;
}
#endif

void TPOData::getData(int id, int offset, int count, void* recvBuf)
{
    totalDataOperationsTime -= MPI_Wtime();
    if (myRank != 0) {
#ifdef PARALLEL
        MemoryPacket p = { id, offset, count };
        MPI_Sendrecv(&p, 1, memoryPacketDatatype, 0, MPI_TAG_GETDATA, recvBuf, count, getMpiType(id), 0, MPI_TAG_ACTUALDATA, MPI_COMM_WORLD, &status);
#endif
    } else recvBuf = getDataAddr(id);
    totalDataOperationsTime += MPI_Wtime();
}

void TPOData::setData(int id, int offset, int count, const void *value)
{
    totalDataOperationsTime -= MPI_Wtime();
    if (myRank != 0) {
#ifdef PARALLEL
        MemoryPacket p = { id, offset, count };
        MPI_Send(&p, 1, memoryPacketDatatype, 0, MPI_TAG_PUTDATA, MPI_COMM_WORLD);
        MPI_Send((void *)value, count, getMpiType(id), 0, MPI_TAG_ACTUALDATA, MPI_COMM_WORLD);
#endif
    } else {
        memcpy((char *)getDataAddr(id) + getDataSize(id)*offset, value, count * getDataSize(id));
    }
    totalDataOperationsTime += MPI_Wtime();
}

//#########################   MQVAD    #########################

QVAD2 TPOData::get_MQVAD(const int& index)
{
    if (_MQVAD == NULL)
        _MQVAD = (QVADArray*)(new QVADArray);
    getData(MQVAD_id, index, 1, &(*_MQVAD)[index]);
    return (*_MQVAD)[index];
}

QVAD2 TPOData::set_MQVAD(const int& index, const QVAD2 &value)
{
    setData(MQVAD_id, index, 1, &value);
    return value;
}

ptrQVADArray TPOData::get_MQVAD()
{
    if (_MQVAD == NULL)
        _MQVAD = (QVADArray*)(new QVADArray);
    getData(MQVAD_id, 0, QVADArray_LENGTH, _MQVAD);
    return *_MQVAD;
}

ptrQVADArray TPOData::set_MQVAD(const ptrQVADArray &value)
{
    setData(MQVAD_id, 0, QVADArray_LENGTH, *(&value));
    return (QVAD2 *)value;
}

//#########################   HTMAX_p    #########################
LMAX TPOData::get_HTMAX_p(const int& index)
{
    if (_HTMAX_p == NULL) _HTMAX_p = (ArrayOfLMAX*)(new ArrayOfLMAX);
    getData(HTMAX_p_id, index, 1, &(*_HTMAX_p)[index]);
    return (*_HTMAX_p)[index];
}

LMAX TPOData::set_HTMAX_p(const int& index, const LMAX &value)
{
    setData(HTMAX_p_id, index, 1, &value);
    return value;
}

ptrArrayOfLMAX TPOData::get_HTMAX_p()
{
    if (_HTMAX_p == NULL) _HTMAX_p = (ArrayOfLMAX*)(new ArrayOfLMAX);
    getData(HTMAX_p_id, 0, ArrayOfLMAX_LENGTH, _HTMAX_p);
    return *_HTMAX_p;
}

ptrArrayOfLMAX TPOData::set_HTMAX_p(const ptrArrayOfLMAX &value)
{
    setData(HTMAX_p_id, 0, ArrayOfLMAX_LENGTH, *(&value));
    return (LMAX *)value;
}


long TPOData::get_NF(const int& index)
{
    if (_NF == NULL) _NF = (ArrayOfLong*)(new ArrayOfLong);
    getData(NF_id, index, 1, &(*_NF)[index]);
    return (*_NF)[index];
}

long TPOData::set_NF(const int& index, const long &value)
{
    setData(NF_id, index, 1, &value);
    return value;
}

ptrArrayOfLong TPOData::get_NF()
{
    if (_NF == NULL) _NF = (ArrayOfLong*)(new ArrayOfLong);
    getData(NF_id, 0, ArrayOfLong_LENGTH, _NF);
    return *_NF;
}

ptrArrayOfLong TPOData::set_NF(const ptrArrayOfLong &value)
{
    setData(NF_id, 0, ArrayOfLong_LENGTH, *(&value));
    return (long *)value;
}

long TPOData::get_MQVAD_len(const int& index)
{
    if (_MQVAD_len == NULL) _MQVAD_len = (ArrayOfLong*)(new ArrayOfLong);
    getData(MQVAD_len_id, index, 1, &(*_MQVAD_len)[index]);
    return (*_MQVAD_len)[index];
}

long TPOData::set_MQVAD_len(const int& index, const long &value)
{
    setData(MQVAD_len_id, index, 1, &value);
    return value;
}

ptrArrayOfLong TPOData::get_MQVAD_len()
{
    if (_MQVAD_len == NULL) _MQVAD_len = (ArrayOfLong*)(new ArrayOfLong);
    getData(MQVAD_len_id, 0, ArrayOfLong_LENGTH, _MQVAD_len);
    return *_MQVAD_len;
}

ptrArrayOfLong TPOData::set_MQVAD_len(const ptrArrayOfLong &value)
{
    setData(MQVAD_len_id, 0, ArrayOfLong_LENGTH, *(&value));
    return (long *)value;
}


double TPOData::get_Estron()
{
    if (_Estron == NULL) *(_Estron = new double) = 0.016;
    getData(Estron_id, 0, 1, _Estron);
    return *_Estron;
}

double TPOData::set_Estron(const double &value)
{
    setData(Estron_id, 0, 1, &value);
    return value;
}

int TPOData::get_KlocMax()
{
    if (_KlocMax == NULL) *(_KlocMax = new int) = 10;
    getData(KlocMax_id, 0, 1, _KlocMax);
    return *_KlocMax;
}

int TPOData::set_KlocMax(const int &value)
{
    setData(KlocMax_id, 0, 1, &value);
    return value;
}

int TPOData::get_NFUNC()
{
    if (_NFUNC == NULL) *(_NFUNC = new int) = 21;
    getData(NFUNC_id, 0, 1, _NFUNC);
    return *_NFUNC;
}

int TPOData::set_NFUNC(const int &value)
{
    setData(NFUNC_id, 0, 1, &value);
    return value;
}

int TPOData::get_Nlok()
{
    if (_Nlok == NULL) *(_Nlok = new int) = 2;
    getData(Nlok_id, 0, 1, _Nlok);
    return *_Nlok;
}

int TPOData::set_Nlok(const int &value)
{
    setData(Nlok_id, 0, 1, &value);
    return value;
}

double TPOData::get_lx()
{
    if (_lx == NULL) *(_lx = new double) = 0.0078;
    getData(lx_id, 0, 1, _lx);
    return *_lx;
}

double TPOData::set_lx(const double &value)
{
    setData(lx_id, 0, 1, &value);
    return value;
}

double TPOData::get_mmax()
{
    if (_mmax == NULL) *(_mmax = new double) = 0;
    getData(mmax_id, 0, 1, _mmax);
    return *_mmax;
}

double TPOData::set_mmax(const double &value)
{
    setData(mmax_id, 0, 1, &value);
    return value;
}

FUNC TPOData::get_zp1()
{
    if (_zp1 == NULL) *(_zp1 = new FUNC) = -1.0e77;
    getData(zp1_id, 0, 1, _zp1);
    return *_zp1;
}

FUNC TPOData::set_zp1(const FUNC &value)
{
    setData(zp1_id, 0, 1, &value);
    return value;
}

MPAR2 TPOData::get_Akfun()
{
    if (_Akfun == NULL)
        *(_Akfun = new MPAR2);
    getData(Akfun_id, 0, 1, _Akfun);
    return *_Akfun;
}

MPAR2 TPOData::set_Akfun(const MPAR2 &value)
{
    setData(Akfun_id, 0, 1, &value);
    return value;
}

long TPOData::get_HTMAX_len(const int& index)
{
    if (_HTMAX_len == NULL) _HTMAX_len = (ArrayOfLong*)(new ArrayOfLong);
    getData(HTMAX_len_id, index, 1, &(*_HTMAX_len)[index]);
    return (*_HTMAX_len)[index];
}

long TPOData::set_HTMAX_len(const int& index, const long &value)
{
    setData(HTMAX_len_id, index, 1, &value);
    return value;
}

ptrArrayOfLong TPOData::get_HTMAX_len()
{
    if (_HTMAX_len == NULL) _HTMAX_len = (ArrayOfLong*)(new ArrayOfLong);
    getData(HTMAX_len_id, 0, ArrayOfLong_LENGTH, _HTMAX_len);
    return *_HTMAX_len;
}

ptrArrayOfLong TPOData::set_HTMAX_len(const ptrArrayOfLong &value)
{
    setData(HTMAX_len_id, 0, ArrayOfLong_LENGTH, *(&value));
    return (long *)value;
}

LMAXPL TPOData::get_HTMAX_GB(const int& index)
{
    if (_HTMAX_GB == NULL) _HTMAX_GB = (ArrayOfLMAXPL*)(new ArrayOfLMAXPL);
    getData(HTMAX_GB_id, index, 1, &(*_HTMAX_GB)[index]);
    return (*_HTMAX_GB)[index];
}

LMAXPL TPOData::set_HTMAX_GB(const int& index, const LMAXPL &value)
{
    setData(HTMAX_GB_id, index, 1, &value);
    return value;
}

ptrArrayOfLMAXPL TPOData::get_HTMAX_GB()
{
    if (_HTMAX_GB == NULL) _HTMAX_GB = (ArrayOfLMAXPL*)(new ArrayOfLMAXPL);
    getData(HTMAX_GB_id, 0, ArrayOfLMAXPL_LENGTH, _HTMAX_GB);
    return *_HTMAX_GB;
}

ptrArrayOfLMAXPL TPOData::set_HTMAX_GB(const ptrArrayOfLMAXPL &value)
{
    setData(HTMAX_GB_id, 0, ArrayOfLMAXPL_LENGTH, *(&value));
    return (LMAXPL *)value;
}

QVADPL TPOData::get_MQVAD_GB(const int& index)
{
    if (_MQVAD_GB == NULL) _MQVAD_GB = (ArrayOfQVADPL*)(new ArrayOfQVADPL);
    getData(MQVAD_GB_id, index, 1, &(*_MQVAD_GB)[index]);
    return (*_MQVAD_GB)[index];
}

QVADPL TPOData::set_MQVAD_GB(const int& index, const QVADPL &value)
{
    setData(MQVAD_GB_id, index, 1, &value);
    return value;
}

ptrArrayOfQVADPL TPOData::get_MQVAD_GB()
{
    if (_MQVAD_GB == NULL) _MQVAD_GB = (ArrayOfQVADPL*)(new ArrayOfQVADPL);
    getData(MQVAD_GB_id, 0, ArrayOfQVADPL_LENGTH, _MQVAD_GB);
    return *_MQVAD_GB;
}

ptrArrayOfQVADPL TPOData::set_MQVAD_GB(const ptrArrayOfQVADPL &value)
{
    setData(MQVAD_GB_id, 0, ArrayOfQVADPL_LENGTH, *(&value));
    return (QVADPL *)value;
}

FUNC TPOData::get_zp_max(const int& index)
{
    if (_zp_max == NULL) _zp_max = (ArrayOFFUNC*)(new ArrayOFFUNC);
    getData(zp_max_id, index, 1, &(*_zp_max)[index]);
    return (*_zp_max)[index];
}

FUNC TPOData::set_zp_max(const int& index, const FUNC &value)
{
    setData(zp_max_id, index, 1, &value);
    return value;
}

ptrArrayOFFUNC TPOData::get_zp_max()
{
    if (_zp_max == NULL) _zp_max = (ArrayOFFUNC*)(new ArrayOFFUNC);
    getData(zp_max_id, 0, ArrayOFFUNC_LENGTH, _zp_max);
    return *_zp_max;
}

ptrArrayOFFUNC TPOData::set_zp_max(const ptrArrayOFFUNC &value)
{
    setData(zp_max_id, 0, ArrayOFFUNC_LENGTH, *(&value));
    return (FUNC *)value;
}
