#include "KhachHang.h"
#ifndef TT_H
#define TT_H
class TT:public KhachHang{
    private:
    int nam;
    public:
    TT(string name="", int sl=0, double gia=0, int nam=0);
    void Nhap() override;
    double TinhTien() override;
};
#endif