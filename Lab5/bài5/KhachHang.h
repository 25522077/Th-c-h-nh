#include<bits/stdc++.h>
#ifndef KHACHHANG_H
#define KHACHHANG_H
using namespace std;
class KhachHang{
    protected:
    string name;
    int sl;
    double gia;
    public:
    KhachHang(string name="", int sl=0, double gia=0);
    virtual ~KhachHang();
    virtual void Nhap();
    void Xuat();
    virtual double TinhTien();
};
#endif