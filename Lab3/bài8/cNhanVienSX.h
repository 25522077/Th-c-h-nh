#include<bits/stdc++.h>
#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H
using namespace std;
class cNhanVienSX{
    private:
    string ma, name, ngaysinh;
    int sp;
    double gia;
    public:
    cNhanVienSX(string ma="", string name="", string ngaysinh ="", int sp=0, double gia=0);
    void Nhap();
    void Xuat();
    double TinhLuong();
    double GetTuoi();
    void Setgia(double a);
};
#endif