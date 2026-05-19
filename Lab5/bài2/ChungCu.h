#include "BDS.h"
#ifndef CHUNGCU_H
#define CHUNGCU_H
class ChungCu:public BDS{
    private:
    string ma1;
    int vitri;
    public:
    ChungCu(string ma="", string ngay="", double dongia=0, double dt=0, string ma1="", int vitri=0);
    void Nhap() override;
    void Xuat() override;
    double TinhTien() override;
    string check() override;
};
#endif