#include<iostream>
#include<cmath>
#include "CVector.h"
using namespace std;
int main(){
    CVector a, b;
    cout<<"Nhap vector a: "<<"\n";
    cin>>a;
    cout<<"Nhap vector b: "<<"\n";
    cin>>b;
    cout<<"Tong 2 vector: "<<a+b<<"\n";
    cout<<"Hieu 2 vector: "<<a-b<<"\n";
    cout<<"Tich vo huong 2 vector: "<<a*b<<"\n";
    cout<<"Do dai vector a: "<<sqrt(a*a)<<"\n";
    cout<<"Do dai vector b: "<<sqrt(b*b)<<"\n";
}