#include<iostream>
#include "CTime.h"
using namespace std;
int main(){
    CTime a, temp;
    int giaythem;
    cout<<"Nhap thoi gian: ";
    cin>>a;
    temp=a;
    cout<<"Nhap giay them: ";
    cin>>giaythem;
    cout<<"Tang them giay: "<<a+giaythem<<"\n";
    a=temp;
    cout<<"Giam them giay: "<<a-giaythem<<"\n";
    a=temp;
    cout<<"Tang them mot giay: "<<++a<<"\n";
    a=temp;
    cout<<"Giam di mot giay: "<<--a<<"\n";
    return 0;
}