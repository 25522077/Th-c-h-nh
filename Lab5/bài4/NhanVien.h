#include<bits/stdc++.h>
#ifndef NHANVIEN_H
#define NHANVIEN_H
using namespace std;
class NhanVien{
    protected: 
    string ma, name, sdt, mail;
    int tuoi;
    double luongcb;
    public:
    NhanVien(string ma="", string name="", int tuoi=0, string sdt="", string mail="", double luongcb=0);
    virtual ~NhanVien();
    virtual void Nhap();
    virtual void Xuat();
    virtual string check()=0;
    virtual double TinhLuong()=0;
};
#endif