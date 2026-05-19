#include<bits/stdc++.h>
#ifndef NHANVIEN_H
#define NHANVIEN_H
using namespace std;
class NhanVien{
    protected:
    string name, ngaysinh;
    double luong;
    public:
    NhanVien(string name="", string ngaysinh="", double luong=0);
    virtual ~NhanVien();
    virtual void Nhap();
    virtual void Xuat();
    virtual double TinhLuong()=0;
    virtual bool check()=0;
    long TinhTuoi();
};
#endif