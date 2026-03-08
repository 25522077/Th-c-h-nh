#include<bits/stdc++.h>
using namespace std;

// struct lưu thông tin của một học sinh
struct hocsinh{
    string ten;   // tên học sinh
    float toan;   // điểm toán
    float ly;     // điểm lý
    float hoa;    // điểm hóa
    float DTB;    // điểm trung bình
};

// Hàm nhập thông tin học sinh
void nhap(hocsinh &a){
    // nhập tên học sinh (getline để nhập được khoảng trắng)
    getline(cin, a.ten);
    // nhập điểm 3 môn
    cin>>a.toan>>a.ly>>a.hoa;
    // tính điểm trung bình
    a.DTB=(a.toan+a.ly+a.hoa)/3;
}

// Hàm xuất thông tin học sinh
void xuat(hocsinh a){
    cout<<"Ten: "<<a.ten<<"\n"<<"Toan: "<<a.toan<<"\n" <<"Ly: "<<a.ly<<"\n"<<"Hoa: "<<a.hoa<<"\n"<<"DTB: "<<fixed<<setprecision(1)<<a.DTB;
}

int main(){
    hocsinh a;   // khai báo biến a kiểu hocsinh
    nhap(a);     // gọi hàm nhập thông tin
    xuat(a);     // gọi hàm xuất thông tin
    return 0;
}