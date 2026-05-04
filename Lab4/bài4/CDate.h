#include<iostream>
#ifndef CDATE_H
#define CDATE_H
using namespace std;
class CDate{
    private:
    int ngay, thang, nam;
    public:
    CDate(int ngay=0, int thang=0, int nam=0);
    friend istream &operator>>(istream &in, CDate &a);
    friend ostream &operator <<(ostream &out, CDate a);
    CDate operator +(const int &ngay1);
    CDate operator -(const int &ngay1);
    CDate &operator ++();
    CDate &operator --();
    CDate operator ++(int);
    CDate operator --(int);
    int operator -(const CDate &a);
};
#endif
