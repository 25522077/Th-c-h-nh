#include<iostream>
#include<vector>
#ifndef DATHUC_H
#define DATHUC_H
using namespace std;
class DaThuc{
    private:
    int bac;
    vector<double> hs;
    public:
    DaThuc(int bac=0);
    friend istream &operator>>(istream &in, DaThuc &a);
    friend ostream &operator<<(ostream &out, const DaThuc &a);
    DaThuc operator +(const DaThuc &another);
    DaThuc operator -(const DaThuc &another);
    DaThuc operator *(const DaThuc &another);
    double Tinh(double x);
};
#endif