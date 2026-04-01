#ifndef PHANSO_H
#define PHANSO_H
class PhanSo{
    private:
    int iTu;
    int iMau;
    public:
    PhanSo(int iTu=0, int iMau=1);
    void Nhap();
    void Xuat();
    void TinhTong(PhanSo a, PhanSo b);
    void TinhHieu(PhanSo a, PhanSo b);
    void TinhTich(PhanSo a, PhanSo b);
    void TinhThuong(PhanSo a, PhanSo b);
    void SoSanh(PhanSo a, PhanSo b);
    int getTu();
};
#endif
