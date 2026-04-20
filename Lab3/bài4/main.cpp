#include<bits/stdc++.h>
#include "cArray.h"
using namespace std;
int main(){
    cArray a;
    int k;
    cout<<"Nhap so can tim: ";
    cin>>k;
    cout<<"Xuat phan tu mang: "<<"\n";
    a.Xuat();
    cout<<"\nSo lan xuat hien cua so: "<<a.Count(k)<<"\n";
    if(a.Test()){
        cout<<"Mang tang dan"<<"\n";
    }
    else{
        cout<<"Mang khong tang dan"<<"\n";
    }
    int temp=a.TimLe();//temp gán cho hàm tìm lẻ
    if(temp==0){
        cout<<"Khong co phan le trong mang"<<"\n"; 
    }
    else{
        cout<<"Phan le nho nhat trong mang: "<<temp<<"\n";
    }
    temp=a.TimSNTMax();//temp gán cho hàm tìm SNT MAX
    if(temp==0){
        cout<<"Khong co SNT trong mang"<<"\n";
    }
    else{
        cout<<"SNT lon nhat trong mang: "<<temp<<"\n";
    }
    a.SXTangDan();
    cout<<"Mang da sap xep theo tang dan: "<<"\n";
    a.Xuat();
    a.SXGiamDan();
    cout<<"\n"<<"Mang da sap xep theo giam dan: "<<"\n";
    a.Xuat();
    return 0;
}