#include<iostream>
#include "NhanVien.h"
using namespace std;

// Hàm khởi tạo (Constructor) có tham số
NhanVien::NhanVien(string name, string ngaysinh, double luong){
    this->name = name;
    this->ngaysinh = ngaysinh;
    this->luong = luong;
}

NhanVien::~NhanVien(){}

// Nhập thông tin nhân viên từ bàn phím
void NhanVien::Nhap(){
    cin.ignore(); // Xóa bộ nhớ đệm tránh trôi lệnh
    cout << "Nhap ten cua nhan vien: ";
    getline(cin, name);
    cout << "Nhap ngay sinh cua nhan vien: ";
    getline(cin, ngaysinh);
}

// Xuất thông tin nhân viên ra màn hình
void NhanVien::Xuat(){
    cout << name << " " << ngaysinh << " ";
}

// Tính tuổi nhân viên (Cắt lấy 4 ký tự năm từ vị trí thứ 6 của chuỗi ngaysinh)
long NhanVien::TinhTuoi(){
    return 2026 - stol(ngaysinh.substr(6, 4));
}