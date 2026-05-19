#include "NhanVien.h"
#ifndef NVKC_H
#define NVKC_H
class NVKC:public NhanVien{
    private:
    int soloi;
    public:
    NVKC(string ma="", string name="", int tuoi=0, string sdt="", string mail="", double luongcb=0, int soloi=0);
    void Nhap() override;
    void Xuat() override;
    string check() override;
    double TinhLuong() override;
};
#endif