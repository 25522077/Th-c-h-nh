#ifndef CDATHUC_H
#define CDATHUC_H
class cDaThuc{
    private:
    int n;
    double *hs;
    public:
    cDaThuc(int n=0);
    ~cDaThuc();
    void Nhap();
    void Xuat();
    double Tinh(double x);
    void Cong2DT(const cDaThuc &a, const cDaThuc &b);
    void Tru2DT(const cDaThuc &a, const cDaThuc &b);
};
#endif