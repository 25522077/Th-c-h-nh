#include "SinhVien.h"
using namespace std;

// Hàm khởi tạo (Constructor) có tham số để gán giá trị ban đầu cho các thuộc tính
SinhVien::SinhVien(string MASV, string name, string address, int tinchi, double dtb){
    this->MASV = MASV;
    this->name = name;
    this->address = address;
    this->tinchi = tinchi;
    this->dtb = dtb;
}

// Nhập thông tin sinh viên từ bàn phím
void SinhVien::Nhap(){
    cin.ignore(); // Xóa bộ nhớ đệm tránh trôi lệnh khi dùng getline
    cout << "Nhap ma sinh vien: ";
    getline(cin, MASV);
    cout << "Nhap ten: ";
    getline(cin, name);
    cout << "Nhap dia chi: ";
    getline(cin, address);
    cout << "Nhap tong so tin chi: ";
    cin >> tinchi;
    cout << "Nhap diem trung binh: ";
    cin >> dtb;
}

SinhVien::~SinhVien(){}

// Xuất thông tin sinh viên ra màn hình
void SinhVien::Xuat(){
    cout << MASV << "  " << name << "  " << "  " << address << "  " << tinchi << "  " << dtb << "  ";
}

// Hàm Getter để lấy ra giá trị điểm trung bình của sinh viên
double SinhVien::DTB(){
    return this->dtb;
}