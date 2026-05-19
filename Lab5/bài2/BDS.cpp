#include "BDS.h"
using namespace std;

// Hàm khởi tạo (Constructor) có tham số để gán giá trị cho các thuộc tính
BDS::BDS(string ma, string ngay, double dongia, double dt){
    this->ma = ma;
    this->ngay = ngay;
    this->dongia = dongia;
    this->dt = dt;
}

BDS::~BDS(){}

// Nhập thông tin giao dịch bất động sản từ bàn phím
void BDS::Nhap(){
    cin.ignore(); // Xóa bộ nhớ đệm tránh trôi lệnh getline
    cout << "Nhap ma giao dich: ";
    getline(cin, ma);
    cout << "Nhap ngay giao dich: ";
    getline(cin, ngay);
    cout << "Nhap don gia: ";
    cin >> dongia;
    cout << "Nhap dien tich: ";
    cin >> dt;
}

// Xuất thông tin giao dịch ra màn hình
void BDS:: Xuat(){
    cout << ma << "  " << ngay << "  " << dongia << "  " << dt << "  ";
}

// Lấy ra chuỗi Tháng/Năm (Cắt 7 ký tự từ vị trí thứ 3 của chuỗi ngay dạng DD/MM/YYYY)
string BDS::getngay(){
    return ngay.substr(3, 7);
}