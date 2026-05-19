#ifndef NHANVIENSX_H
#define NHANVIENSX_H
#include "NhanVien.h"
class NhanVienSX:public NhanVien{
    private:
    double luongcb;
    long sosp;
    public:
    NhanVienSX(string name="", string ngaysinh="", double luong=0, double luongcb=0, long sosp=0);
    void Nhap() override;
    void Xuat() override;
    double TinhLuong() override;
    bool check() override;
};
#endif