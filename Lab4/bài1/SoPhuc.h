#include<iostream>
#ifndef SOPHUC_H
#define SOPHUC_H
using namespace std;
class SoPhuc{
    private:
    double thuc, ao;
    public:
    SoPhuc(double thuc=0, double ao=0);
    friend istream &operator >>(istream &in, SoPhuc &a);
    friend ostream &operator <<(ostream &out, const SoPhuc &a);
    SoPhuc operator +(const SoPhuc &another);
    SoPhuc operator -(const SoPhuc &another);
    SoPhuc operator *(const SoPhuc &another);
    SoPhuc operator /(const SoPhuc &another);
    bool operator ==(const SoPhuc &another);
    bool operator !=(const SoPhuc &another);
    int getthuc();
    int getao();
};
#endif