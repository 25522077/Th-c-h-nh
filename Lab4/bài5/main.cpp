#include<iostream>
#include "DaThuc.h"
using namespace std;
int main(){
    DaThuc a, b;
    double x;
    cout<<"Nhap da thuc a: "<<"\n";
    cin>>a;
    cout<<"Nhap da thuc b: "<<"\n";
    cin>>b;
    cout<<"Nhap x: ";
    cin>>x;
    cout<<"Tong 2 da thuc: "<<a+b<<"\n";
    cout<<"Hieu 2 da thuc: "<<a-b<<"\n";
    cout<<"Tich 2 da thuc: "<<a*b<<"\n";
    cout<<"Gia tri da thuc a: "<<a.Tinh(x)<<"\n";
    cout<<"Gia tri da thuc b: "<<b.Tinh(x);
    return 0;
}