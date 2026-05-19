#include<iostream>
#include<cstring>
#ifndef SINHVIEN_H
#define SINHVIEN_H
using namespace std;
class SinhVien{
    protected:
    string MASV, name, address;
    int tinchi;
    double dtb;
    public:
    SinhVien(string MASV="", string name="", string address="", int tinchi=0, double dtb=0);
    virtual ~SinhVien();
    virtual void Nhap();
    virtual void Xuat();
    double DTB();
    virtual string check()=0;
    virtual bool checkTotNghiep()=0;
};
#endif