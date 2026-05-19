#include "BDS.h"
#ifndef NHA_H
#define NHA_H
using namespace std;
class Nha:public BDS{
    private:
    string loainha;
    public:
    Nha(string ma="", string ngay="", double dongia=0, double dt=0, string loainha="");
    void Nhap() override;
    void Xuat() override;
    double TinhTien() override;
    string check() override;
};
#endif