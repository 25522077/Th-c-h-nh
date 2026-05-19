#include "KhachHang.h"
#ifndef DB_H
#define DB_H
class DB:public KhachHang{
    public:
    DB(string name="", int sl=0, double gia=0);
    double TinhTien() override;
};
#endif