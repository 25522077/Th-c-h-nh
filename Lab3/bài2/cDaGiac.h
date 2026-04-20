#ifndef CDAGIAC_H
#define CDAGIAC_H
#include "Diem.h"
class cDaGiac{
    private:
    int n;
    Diem a[100];
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