#include<bits/stdc++.h>
using namespace std;
struct date{
    int day;
    int month;
    int year;
};
bool checknhuan(int n){
    if(n%4==0 && n%100!=0) return true;
    if(n%400==0) return true;
    return false;
}
date tangngay(date a){
    int maxday;
    switch(a.month){
        case 4: case 6: case 9: case 11: maxday=30; break;
        case 2: if(checknhuan(a.year)) maxday=29; else maxday=28; break;
        default: maxday=31;
    }
    if(a.day+1>maxday){
        a.month++;
        a.day=1;
    }
    else{
        a.day++;
    }
    if(a.month>12) a.year++;
    return a;
}
int main(){
    date a;
    cin>>a.day>>a.month>>a.year;
    a=tangngay(a);
    cout<<a.day<<"/"<<a.month<<"/"<<a.year;
    return 0;
}