#include<iostream>
#include "NhanVienSX.h"

// Hàm khởi tạo kế thừa từ lớp cha NhanVien và gán giá trị cho luongcb, sosp
NhanVienSX::NhanVienSX(string name, string ngaysinh, double luong, double luongcb, long sosp)
    : NhanVien(name, ngaysinh, luong), luongcb(luongcb), sosp(sosp){}

// Nhập thông tin: Gọi hàm Nhập của lớp cha rồi nhập tiếp luongcb và sosp
void NhanVienSX::Nhap(){
    NhanVien::Nhap();
    cout << "Nhap luong co ban: ";
    cin >> luongcb;
    cout << "Nhap so san pham da san xuat: ";
    cin >> sosp;
}

// Tính tổng lương = Lương cơ bản + Số sản phẩm * 5 (don vi la nghin dong)
double NhanVienSX::TinhLuong(){
    return luongcb + sosp * 5000;
}

// Xuất thông tin: Gọi hàm Xuất lớp cha, in ra và làm tròn tổng lương và in ra loại nhân viên
void NhanVienSX::Xuat(){
    NhanVien::Xuat();
    cout <<fixed<<setprecision(1)<< TinhLuong() << " " << "NhanVienSX" << "\n"; 
}

// Hàm kiểm tra, mặc định trả về true (dùng để phân loại đối tượng)
bool NhanVienSX::check(){
    return true;
}