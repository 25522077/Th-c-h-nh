#include<iostream>
#include "CDate.h"
using namespace std;
int main(){
    CDate a, temp, b;
    int ngay1;
    cout<<"Nhap ngay, thang, nam: ";
    cin>>a;
    temp=a;
    cout<<"Nhap ngay them va bot: ";
    cin>>ngay1;
    cout<<"Nhap ngay, thang, nam de tinh khoang cach: ";
    cin>>b;
    cout<<"Ngay, thang, nam sau khi them ngay: "<<a+ngay1<<"\n";
    a=temp;
    cout<<"Ngay, thang, nam sau khi bot ngay: "<<a-ngay1<<"\n";
    a=temp;
    cout<<"Ngay, thang, nam sau khi them 1 ngay: "<<++a<<"\n";
    a=temp;
    cout<<"Ngay, thang nam sau khi bot mot ngay: "<<--a<<'\n';
    a=temp;
    cout<<"Khoang cach cua 2 ngay, thang, nam: "<<a-b;
    return 0;
}
