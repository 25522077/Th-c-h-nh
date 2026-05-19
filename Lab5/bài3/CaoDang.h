#include "SinhVien.h"
#ifndef CAODANG_H
#define CAODANG_H
using namespace std;
class CaoDang:public SinhVien{
    private:
    double diemtn;
    public:
    CaoDang(string MASV="", string name="", string address="", int tinchi=0, double dtb=0, double diemtn=0);
    void Nhap() override;
    void Xuat() override;
    string check() override;
    bool checkTotNghiep() override;
};
#endif
