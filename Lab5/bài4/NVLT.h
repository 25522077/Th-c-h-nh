#include "NhanVien.h"
#ifndef NVLT_H
#define NVLT_H
class NVLT:public NhanVien{
    private:
    int sogio;
    public:
    NVLT(string ma="", string name="", int tuoi=0, string sdt="", string mail="", double luongcb=0, int sogio=0);
    void Nhap() override;
    void Xuat() override;
    string check() override;
    double TinhLuong() override;
};
#endif