#include "BDS.h"
#ifndef DAT_H
#define DAT_H
class Dat:public BDS{
    private:
    string loaidat;
    public:
    Dat(string ma="", string ngay="", double dongia=0, double dt=0, string loaidat="");
    void Nhap() override;
    void Xuat() override;
    double TinhTien() override;
    string check() override;
};
#endif