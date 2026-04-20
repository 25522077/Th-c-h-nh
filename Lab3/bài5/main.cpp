#include<bits/stdc++.h>
#include "cDaThuc.h"
using namespace std;
int main(){
    cDaThuc a, b, c;
    double x;
    cout<<"Nhap da thuc a: "<<"\n";
    a.Nhap();
    cout<<"Nhap da thuc b: "<<"\n";
    b.Nhap();
    cout<<"Nhap x: ";
    cin>>x;
    cout<<"Da thuc a: ";
    a.Xuat();
    cout<<"\n"<<"Da thuc b: ";
    b.Xuat();
    cout<<"\n"<<"Gia tri cua da thuc a voi gia tri x: "<<a.Tinh(x)<<"\n";
    cout<<"Gia tri cua da thuc b voi gia tri x: "<<b.Tinh(x)<<"\n";
    cout<<"Cong 2 da thuc: ";
    c.Cong2DT(a, b);
    c.Xuat();
    cout<<"\n"<<"Tru 2 da thuc: ";
    c.Tru2DT(a, b);
    c.Xuat();
    return 0;
}

