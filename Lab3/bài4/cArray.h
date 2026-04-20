#ifndef CARRAY_H
#define CARRAY_H
class cArray{
    private:
    int n;
    int *a;
    public:
    cArray();
    void Xuat();
    int Count(int x);
    bool Test();
    int TimLe();
    int TimSNTMax();
    void SXTangDan();
    void SXGiamDan();
    ~cArray();
};
#endif