#include<bits/stdc++.h>
#include "cNhanVienSX.h"
using namespace std;

// Hàm khởi tạo nhân viên sản xuất với đầy đủ tham số truyền vào
cNhanVienSX::cNhanVienSX(string ma, string name, string ngaysinh, int sp, double gia){
    this->ma = ma;           // Gán mã nhân viên
    this->name = name;       // Gán họ tên nhân viên
    this->ngaysinh = ngaysinh; // Gán ngày tháng năm sinh
    this->sp = sp;           // Gán số lượng sản phẩm làm được
    this->gia = gia;         // Gán đơn giá trên mỗi sản phẩm
}

// Hàm nhập thông tin nhân viên sản xuất từ bàn phím
void cNhanVienSX::Nhap(){
    cout<<"Nhap ma nhan vien: ";
    getline(cin, ma);        // Nhập chuỗi mã nhân viên
    
    cout<<"Nhap ten nhan vien: ";
    getline(cin, name);      // Nhập đầy đủ họ tên
    
    cout<<"Nhap ngay thang nam sinh nhan vien: ";
    getline(cin, ngaysinh);  // Nhập ngày sinh (định dạng giả định DD/MM/YYYY)
    
    cout<<"Nhap so san pham da gia cong: ";
    cin>>sp;                 // Nhập số lượng sản phẩm (kiểu int)
    
    cout<<"Nhap gia cua mot san pham: ";
    cin>>gia;                // Nhập đơn giá sản phẩm (kiểu double)
    
    // Xóa bộ nhớ đệm để tránh lỗi khi nhập cho nhân viên tiếp theo
    cin.ignore();
}

// Hàm xuất thông tin nhân viên ra màn hình
void cNhanVienSX::Xuat(){
    // In ra mã, tên, ngày sinh, số SP, đơn giá và lương (Lương = Số SP * Đơn giá)
    cout<<ma<<"  "<<name<<"  "<<ngaysinh<<"  "<<sp<<"  "<<gia<<"  "<<(double)sp*gia<<"\n";
}

// Hàm tính và trả về tổng lương của nhân viên sản xuất
double cNhanVienSX::TinhLuong(){
    // Lương được tính bằng tích của số lượng sản phẩm và đơn giá
    return (double)sp * gia;
}

// Hàm tính tuổi của nhân viên dựa vào năm sinh
double cNhanVienSX::GetTuoi(){
    // Cắt chuỗi lấy 4 ký tự năm sinh từ vị trí thứ 6 (định dạng DD/MM/YYYY)
    string namsinh = ngaysinh.substr(6, 4);
    
    // Chuyển chuỗi năm sinh sang kiểu số thực (stod) và tính tuổi dựa trên mốc năm 2026
    return 2026 - stod(namsinh);
}

// Hàm cập nhật (thay đổi) đơn giá của một sản phẩm
void cNhanVienSX::Setgia(double a){
    this->gia = a; // Gán giá trị mới 'a' cho thuộc tính đơn giá
}