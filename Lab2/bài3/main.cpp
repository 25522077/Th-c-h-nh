#include<bits/stdc++.h>
#include "SoPhuc.h"
using namespace std;
int main(){
    SoPhuc a, b, c;
    cout<<"Nhap so phuc a: ";
    a.Nhap();
    cout<<"Nhap so phuc b: ";
    b.Nhap();
    cout<<"Tong 2 so phuc: ";
    c.TinhTong(a, b);
    c.Xuat();
    cout<<"\n";
    cout<<"Hieu 2 so phuc: ";
    c.TinhHieu(a, b);
    c.Xuat();
    cout<<"\n";
    cout<<"Tich 2 so phuc: ";
    c.TinhTich(a, b);
    c.Xuat();
    cout<<"\n";
    c.TinhThuong(a, b);
    return 0;
}