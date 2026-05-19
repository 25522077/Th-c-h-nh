#include "NVLT.h"

// Hàm khởi tạo: Gọi constructor của lớp cha (NhanVien) trước, sau đó gán giá trị cho 'sogio'
NVLT::NVLT(string ma, string name, int tuoi, string sdt, string mail, double luongcb, int sogio)
    : NhanVien(ma, name, tuoi, sdt, mail, luongcb), sogio(sogio) {}

// Hàm nhập thông tin nhân viên lập trình
void NVLT::Nhap(){
    NhanVien::Nhap(); // Gọi lại hàm Nhap() của lớp cha để nhập các thông tin cơ bản
    cout << "Nhap so gio overtime: ";
    cin >> sogio;     // Nhập thêm số giờ làm thêm (đặc trưng của lập trình viên)
}

// Hàm xuất thông tin nhân viên lập trình
void NVLT::Xuat(){
    NhanVien::Xuat(); // Gọi lại hàm Xuat() của lớp cha để in các thông tin cơ bản
    // In thêm chức danh và tổng lương sau khi tính toán va lam tron, sau đó xuống dòng
    cout << "LapTrinhVien" << "  " <<fixed<<setprecision(1)<<TinhLuong() << "\n";
}

// Hàm nhận diện loại nhân viên (Trả về chuỗi "NVLT")
string NVLT::check(){
    return "NVLT";
}

// Hàm tính tổng lương của nhân viên lập trình
double NVLT::TinhLuong(){
    // Tổng lương = Lương cơ bản + (Số giờ overtime * 200.000đ)
    return luongcb + sogio * 200000;
}