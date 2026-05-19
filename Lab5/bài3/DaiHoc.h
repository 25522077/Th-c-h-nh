#include "SinhVien.h"
#ifndef DAIHOC_H
#define DAIHOC_H
using namespace std;
class DaiHoc:public SinhVien{
    private:
    string tenluanvan;
    double diemluanvan;
    public:
    DaiHoc(string MASV="", string name="", string address="", int tinchi=0, double dtb=0, string tenluanvan="", double diemluanvan=0);
    void Nhap() override;
    void Xuat() override;
    string check() override;
    bool checkTotNghiep() override;
};
#endif
