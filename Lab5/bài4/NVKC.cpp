#include "NVKC.h"

// Hàm khởi tạo: Gọi constructor của lớp cha (NhanVien) trước, sau đó gán giá trị cho 'soloi'
NVKC::NVKC(string ma, string name, int tuoi, string sdt, string mail, double luongcb, int soloi)
    : NhanVien(ma, name, tuoi, sdt, mail, luongcb), soloi(soloi) {}

// Hàm nhập thông tin nhân viên kiểm chứng
void NVKC::Nhap(){
    NhanVien::Nhap(); // Gọi lại hàm Nhap() của lớp cha để nhập các thông tin cơ bản
    cout << "Nhap so loi phat hien duoc: ";
    cin >> soloi;     // Nhập số lỗi tìm được (đặc trưng của tester)
}

// Hàm xuất thông tin nhân viên kiểm chứng
void NVKC::Xuat(){
    NhanVien::Xuat(); // Gọi lại hàm Xuat() của lớp cha để in các thông tin cơ bản
    // In thêm chức danh và tổng lương sau khi tính toán và làm tròn, sau đó xuống dòng
    cout << "KiemChungVien" << "  " <<fixed<<setprecision(1)<< TinhLuong() << "\n";
}

// Hàm nhận diện loại nhân viên (Trả về chuỗi "NVKC")
string NVKC::check(){
    return "NVKC";
}

// Hàm tính tổng lương của nhân viên kiểm chứng
double NVKC::TinhLuong(){
    // Tổng lương = Lương cơ bản + (Số lỗi phát hiện * 50.000đ)
    return luongcb + soloi * 50000;
}