#include<iostream>
#include "PhanSo.h"
using namespace std;
int main(){
    PhanSo a, b;
    cout<<"Nhap phan so a: ";
    cin>>a;
    cout<<"Nhap phan so b: ";
    cin>>b;
    cout<<"Tong 2 phan so: "<<a+b<<"\n";
    cout<<"Hieu 2 phan so: "<<a-b<<"\n";
    cout<<"Tich 2 phan so: "<<a*b<<"\n";
    if(b==0){
        cout<<"Khong co thuong cua 2 phan so"<<"\n";
    }
    else{
        cout<<"Thuong 2 phan so: "<<a/b<<"\n";
    }
    if(a==b){
        cout<<"2 phan so bang nhau";
    }
    if(a>b){
        cout<<"Phan so a lon hon phan so b";
    }
    if(a<b){
        cout<<"Phan so a be hon phan so b";
    }
    return 0;
}