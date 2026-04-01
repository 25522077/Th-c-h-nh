#ifndef TIME_H
#define TIME_H
class Time{
    private:
    int iGio;
    int iPhut;
    int iGiay;
    public:
    Time(int iGio=0, int iPhut=0, int iGiay=0);
    void Nhap();
    void Xuat();
    void TinhCongThemMotGiay();
};
#endif