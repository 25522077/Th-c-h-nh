#include<bits/stdc++.h>
using namespace std;
struct hocsinh{
    string ten;
    float toan;
    float ly;
    float hoa;
    float DTB;
};
int main(){
    hocsinh a;
    getline(cin, a.ten);
    cin>>a.toan>>a.ly>>a.hoa;
    a.DTB=(a.toan+a.ly+a.hoa)/3;
    cout<<"Ten: "<<a.ten<<"\n"<<"Toan: "<<a.toan<<"\n"<<"Ly: "<<a.ly<<"\n"<<"Hoa: "<<a.hoa<<"\n"<<"DTB: "<<fixed<<setprecision(3)<<a.DTB;
    return 0;
}