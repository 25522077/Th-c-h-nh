#ifndef SOPHUC_H
#define SOPHUC_H
class SoPhuc{
    private:
    int iThuc;
    int iAo;
    public:
    SoPhuc(int iThuc=0, int iAo=0);
    void Nhap();
    void Xuat();
    void TinhTong(SoPhuc a, SoPhuc b);
    void TinhHieu(SoPhuc a, SoPhuc b);
    void TinhTich(SoPhuc a, SoPhuc b);
    void TinhThuong(SoPhuc a, SoPhuc b);
};
#endif