#include<iostream>
#include "SoPhuc.h"
using namespace std;
int main(){
    SoPhuc a, b;
    cout<<"Nhap so phuc a: ";
    cin>>a;
    cout<<"Nhap so phuc b: ";
    cin>>b;
    cout<<"Tong 2 so phuc: "<<a+b<<"\n";
    cout<<"Hieu 2 so phuc: "<<a-b<<"\n";
    cout<<"Tich 2 so phuc: "<<a*b<<"\n";
    if(b.getthuc()==0 && b.getao()==0) cout<<"Khong co thuong 2 so phuc"<<"\n";
    else cout<<"Thuong 2 so phuc: "<<a/b<<"\n";
    if(a==b){
        cout<<"2 so phuc bang nhau";
    }
    if(a!=b){
        cout<<"2 so phuc khac nhau";
    }
    return 0;
}