#include<iostream>
#ifndef CTIME_H
#define CTIME_H
using namespace std;
class CTime{
    private:
    int gio, phut, giay;
    public:
    CTime(int gio=0, int phut=0, int giay=0);
    friend istream &operator >>(istream &in, CTime &a);
    friend ostream &operator <<(ostream &out, const CTime &a);
    CTime operator +(const int &giay1);
    CTime operator -(const int &giay1);
    CTime &operator ++();
    CTime operator ++(int);
    CTime &operator --();
    CTime operator --(int);
};
#endif