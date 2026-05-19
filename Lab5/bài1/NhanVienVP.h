#ifndef NHANVIENVP_H
#define NHANVIENVP_H
#include "NhanVien.h"
class NhanVienVP:public NhanVien{
    private:
    long songay;
    public:
    NhanVienVP(string name="", string ngaysinh="", double luong=0, long songay=0);
    void Nhap() override;
    void Xuat() override;
    double TinhLuong() override;
    bool check() override;
};
#endif