#include "NhanVien.h"

// Hàm khởi tạo (Constructor) có tham số để gán giá trị ban đầu cho đối tượng
NhanVien::NhanVien(string ma, string name, int tuoi, string sdt, string mail, double luongcb){
    this->ma = ma;         // Gán mã nhân viên
    this->name = name;     // Gán họ tên
    this->tuoi = tuoi;     // Gán tuổi
    this->sdt = sdt;       // Gán số điện thoại
    this->mail = mail;     // Gán email
    this->luongcb = luongcb; // Gán lương cơ bản
}
NhanVien::~NhanVien(){}
// Hàm nhập thông tin nhân viên từ bàn phím
void NhanVien::Nhap(){
    cin.ignore(); // Xóa ký tự xuống dòng '\n'
    
    cout << "Nhap ma nhan vien: ";
    getline(cin, ma); // Nhập chuỗi có khoảng trắng cho mã nhân viên
    
    cout << "Nhap ho ten: ";
    getline(cin, name); // Nhập chuỗi có khoảng trắng cho họ tên
    
    cout << "Nhap tuoi: ";
    cin >> tuoi; // Nhập số tuổi
    
    cin.ignore(); // Xóa ký tự xuống dòng '\n' còn sót lại trong bộ nhớ đệm sau khi nhập tuổi
    
    cout << "Nhap so dien thoai: ";
    getline(cin, sdt); // Nhập số điện thoại
    
    cout << "Nhap email: ";
    getline(cin, mail); // Nhập email
    
    cout << "Nhap luong co ban: ";
    cin >> luongcb; // Nhập lương cơ bản
}

// Hàm xuất thông tin nhân viên ra màn hình
void NhanVien::Xuat(){
    // In các thông tin ra trên một hàng, cách nhau bởi dấu cách
    cout << ma << "  " << name << "  " << tuoi << "  " << sdt << "  " << mail << "  " <<fixed<<setprecision(1)<<luongcb << "  ";
}