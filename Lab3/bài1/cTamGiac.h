#ifndef TAMGIAC_H
#define TAMGIAC_H
#include "Diem.h"
class cTamGiac{
    private:
    Diem A, B, C;
    public:
    void Nhap();
    void Xuat();
    double TinhCV();
    double TinhDT();
    void TinhTien(double dx, double dy);
    void Quay(double k);
    void PhongTo(double k);
    void ThuNho(double k);
    void Test();
};
#endif