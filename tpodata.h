#ifndef TPODATA_H
#define TPODATA_H
#include "utype.h"
#include "property.h"

class TPOData
{
public:

    TPOData(int rank);
    ~TPOData();

    //Размер выделенной памяти от id
    int getDataSize(int id);
#ifdef PARALLEL
    //Тип MPI от id
    MPI_Datatype getMpiType(int id);
#endif

    //Указатель на область памяти с данными
    void* getDataAddr(int id);

    //Common setter/getter
    void getData(int id, int offset, int count, void* recvBuf);
    void setData(int id, int offset, int count, const void* value);

    MPAR *Akfun;
    QVAD2S *Hq2;
    QVAD2S *Hqva;
    LMAXS *HXMAX;
    LMAXS *Htmax;
    XIF *Simpmax;
    XI *X;
    XI *X0;
    XI *xp1;
    XI *xp2;

    int totalFuncCalls;
    double totalDataOperationsTime;

    int *Flif;
    int *GKLtip;
    int *Hbd;
    int *ILok;
    int *KlocMax;
    int *Krep;
    int *Lor;
    int *LorQ;
    int *MaxPRL;
    int *NFUNC;
    int *N_fun;
    int *Nbd;
    int *Nloc0;
    int *Nlok;
    int *Nmax;
    int *Nmax2;
    int *NprlTec;
    int *Nsimp;
    int *Ntern;
    int *Reset;
    int *iNX;
    int *j1;
    int *j2;
    int *j6;
    int *kDi;
    long *MaxF;
    long *Nstep;
    long *Sumstep;
    double *Diag;
    double *Eloc;
    double *Esimp;
    double *Estron;
    double *Kobl;
    double *Ksum;
    double *Kz;
    double *Lip;
    double *Str;
    double *d2z;
    double *hx;
    double *lx;
    double *maxhx;
    double *mi;
    double *mmax;
    double *r;
    double *w0;
    double *x0;
    FUNC *Zmax;
    FUNC *wmax;
    FUNC *wmin;
    FUNC *wold;
    FUNC *z2;
    FUNC *zmin;
    FUNC *zp1;
    FUNC *zp2;
    SEGM *PRLp;

    void initMemory();

    //Параллельные фишечки
    __property_rw_indexed<QVAD2, int, TPOData> MQVAD;
    __property_rw_indexed<LMAX, int, TPOData> HTMAX_p;
    __property_rw_indexed<long, int, TPOData> NF;
    __property_rw_indexed<long, int, TPOData> MQVAD_len;
    __property_rw_indexed<long, int, TPOData> HTMAX_len;
    __property_rw<int, TPOData> KlocMax_p;
    __property_rw<double, TPOData> Estron_p;
    __property_rw<double, TPOData> lx_p;
    __property_rw<int, TPOData> NFUNC_p;
    __property_rw<int, TPOData> Nlok_p;
    __property_rw<double, TPOData> mmax_p;
    __property_rw<FUNC, TPOData> zp1_p;
    __property_rw<MPAR2, TPOData> Akfun_p;
    __property_rw_indexed<QVADPL, int, TPOData> MQVAD_GB;
    __property_rw_indexed<LMAXPL, int, TPOData> HTMAX_GB;
    __property_rw_indexed<FUNC, int, TPOData> zp_max;
    __property_rw_indexed<double, int, TPOData> mmax_max;

private:
    QVADArray *_MQVAD;
    ArrayOfLong *_NF;
    ArrayOfLong *_MQVAD_len;
    ArrayOfLong *_HTMAX_len;
    double *_Estron;
    int *_KlocMax;
    int *_NFUNC;
    int *_Nlok;
    double *_lx;
    double *_mmax;
    FUNC *_zp1;
    MPAR2 *_Akfun;
    ArrayOfLMAX *_HTMAX_p;
    ArrayOfLMAXPL *_HTMAX_GB;
    ArrayOfQVADPL *_MQVAD_GB;
    ArrayOFFUNC *_zp_max;
        ArrayOfDouble *_mmax_max;

    int MQVAD_id;
    int HTMAX_p_id;
    int NF_id;
    int MQVAD_len_id;
    int Estron_id;
    int KlocMax_id;
    int NFUNC_id;
    int Nlok_id;
    int lx_id;
    int mmax_id;
    int zp1_id;
    int Akfun_id;
    int HTMAX_len_id;
    int MQVAD_GB_id;
    int HTMAX_GB_id;
    int zp_max_id;
        int mmax_max_id;

    ptrQVADArray get_MQVAD();
    ptrQVADArray set_MQVAD(const ptrQVADArray& value);
    QVAD2 get_MQVAD(const int& index);
    QVAD2 set_MQVAD(const int& index, const QVAD2& value);

    ptrArrayOfLong get_NF();
    ptrArrayOfLong set_NF(const ptrArrayOfLong& value);
    long get_NF(const int& index);
    long set_NF(const int& index, const long& value);
    ptrArrayOfLong get_MQVAD_len();
    ptrArrayOfLong set_MQVAD_len(const ptrArrayOfLong& value);
    long get_MQVAD_len(const int& index);
    long set_MQVAD_len(const int& index, const long& value);
    double get_Estron();
    double set_Estron(const double& value);

    double get_lx();
    double set_lx(const double& value);

    int get_KlocMax();
    int set_KlocMax(const int& value);

    int get_NFUNC();
    int set_NFUNC(const int& value);

    int get_Nlok();
    int set_Nlok(const int& value);

    double get_mmax();
    double set_mmax(const double& value);

    FUNC get_zp1();
    FUNC set_zp1(const FUNC& value);
    MPAR2 get_Akfun();
    MPAR2 set_Akfun(const MPAR2& value);

    ptrArrayOfLMAX get_HTMAX_p();
    ptrArrayOfLMAX set_HTMAX_p(const ptrArrayOfLMAX& value);
    LMAX get_HTMAX_p(const int& index);
    LMAX set_HTMAX_p(const int& index, const LMAX& value);

    ptrArrayOfLong get_HTMAX_len();
    ptrArrayOfLong set_HTMAX_len(const ptrArrayOfLong& value);
    long get_HTMAX_len(const int& index);
    long set_HTMAX_len(const int& index, const long& value);

    ptrArrayOfLMAXPL get_HTMAX_GB();
    ptrArrayOfLMAXPL set_HTMAX_GB(const ptrArrayOfLMAXPL& value);
    LMAXPL get_HTMAX_GB(const int& index);
    LMAXPL set_HTMAX_GB(const int& index, const LMAXPL& value);

    ptrArrayOfQVADPL get_MQVAD_GB();
    ptrArrayOfQVADPL set_MQVAD_GB(const ptrArrayOfQVADPL& value);
    QVADPL get_MQVAD_GB(const int& index);
    QVADPL set_MQVAD_GB(const int& index, const QVADPL& value);

    ptrArrayOFFUNC get_zp_max();
    ptrArrayOFFUNC set_zp_max(const ptrArrayOFFUNC& value);
    FUNC get_zp_max(const int& index);
    FUNC set_zp_max(const int& index, const FUNC& value);

    ptrArrayOfDouble get_mmax_max();
    ptrArrayOfDouble set_mmax_max(const ptrArrayOfDouble& value);
    double get_mmax_max(const int& index);
    double set_mmax_max(const int& index, const double& value);

    int myRank;

    void initId();
};
#endif
