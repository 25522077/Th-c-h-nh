#include<iostream>
#ifndef PHANSO_H
#define PHANSO_H
using namespace std;
class PhanSo{
    private:
    int ts, ms;
    public:
    PhanSo(int ts=0, int ms=1);
    friend istream &operator >>(istream &in, PhanSo &a);
    friend ostream &operator <<(ostream &out, const PhanSo &a);
    PhanSo operator +(const PhanSo &another);
    PhanSo operator -(const PhanSo &another);
    PhanSo operator *(const PhanSo &another);
    PhanSo operator /(const PhanSo &another);
    bool operator ==(const PhanSo &another);
    bool operator >(const PhanSo &another);
    bool operator <(const PhanSo &another);
};
#endif