#include<iostream>
#include<vector>
#ifndef CVECTOR_H
#define CVECTOR_H
using namespace std;
class CVector{
    private:
    int chieu;
    vector <double> hs;
    public:
    CVector(int chieu=0);
    friend istream &operator >>(istream &in, CVector &a);
    friend ostream &operator <<(ostream &out, const CVector &a);
    CVector operator +(const CVector &another);
    CVector operator -(const CVector &another);
    int operator *(const CVector &another);
};
#endif