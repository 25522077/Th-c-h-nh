#include<bits/stdc++.h>
#include<cstring>
#ifndef BDS_H
#define BDS_H
using namespace std;
class BDS{
    protected:
    string ma, ngay;
    double dongia, dt;
    public:
    BDS(string ma="", string ngay="", double dongia=0, double dt=0);
    virtual ~BDS();
    virtual void Nhap();
    virtual void Xuat();
    virtual double TinhTien()=0;
    virtual string check()=0;
    string getngay();
};
#endif