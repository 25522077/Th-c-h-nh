#include<bits/stdc++.h>
#include "PhanSo.h"
using namespace std;
int main(){
    PhanSo a, b, c;
    cout<<"Nhap phan so a: ";
    a.Nhap();
    cout<<"Nhap phan so b: ";
    b.Nhap();
    cout<<"Tong 2 phan so: ";
    c.TinhTong(a, b);
    c.Xuat();
    cout<<"Hieu 2 phan so: ";
    c.TinhHieu(a, b);
    c.Xuat();
    cout<<"Tich 2 phan so: ";
    c.TinhTich(a, b);
    c.Xuat();
    if(b.getTu()==0){
        cout<<"Ko tinh duoc thuong"<<"\n"; //Tử phân số b=0 thì ko có phép chia
    }
    else{
        cout<<"Thuong 2 phan so: ";
        c.TinhThuong(a, b);
        c.Xuat();
    }
    cout<<"So sanh 2 phan so: "<<"\n";
    c.SoSanh(a, b);
    return 0;
}