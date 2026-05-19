#include<iostream>
#include "NhanVienVP.h"
using namespace std;

// Hàm khởi tạo kế thừa từ lớp cha NhanVien và gán giá trị cho songay
NhanVienVP::NhanVienVP(string name, string ngaysinh, double luong, long songay)
    : NhanVien(name, ngaysinh, luong), songay(songay){}

// Nhập thông tin: Gọi hàm Nhập lớp cha rồi nhập số ngày làm việc
void NhanVienVP::Nhap(){
    NhanVien::Nhap();
    cout << "Nhap so ngay lam viec: "; 
    cin >> songay;
}

// Tính tổng lương = Số ngày làm việc * 100 (đơn vị là nghìn đồng)
double NhanVienVP::TinhLuong(){
    return songay * 100000;
}

// Xuất thông tin: Gọi hàm Xuất lớp cha, in ra, làm tròn tổng lương và in ra loại nhân viên
void NhanVienVP::Xuat(){
    NhanVien::Xuat();
    cout <<fixed<<setprecision(1)<<TinhLuong() << " NhanVienVP" << "\n";
}

// Hàm kiểm tra, mặc định trả về false (dùng để phân biệt với NhanVienSX)
bool NhanVienVP::check(){
    return false;
}