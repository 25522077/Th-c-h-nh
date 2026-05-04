#include<iostream>
#include<vector>
#ifndef CMATRIX_H
#define CMATRIX_H
using namespace std;
class CMatrix{
    private:
    int cot, dong;
    vector<vector<double>> hs;
    public:
    CMatrix (int dong=0, int cot=0);
    friend istream &operator >>(istream &in, CMatrix &a);
    friend ostream &operator <<(ostream &out, const CMatrix &a);
    CMatrix operator +(const CMatrix &another);
    CMatrix operator -(const CMatrix &another);
    CMatrix operator *(const CMatrix &another);
    friend CMatrix operator *(vector<double> a, const CMatrix &another);
    int getdong();
    int getcot();
};
#endif