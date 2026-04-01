#ifndef DATE_H
#define DATE_H
class Date{
    private:
    int iNgay;
    int iThang;
    int iNam;
    public:
    Date(int iNgay=0, int iThang=0, int iNam=0);
    void Nhap();
    void Xuat();
    void NgayThangNamTiepTheo();
};
#endif