#include"DaiHoc.h"
using namespace std;

// Hàm khởi tạo kế thừa từ lớp cha SinhVien và gán giá trị cho tenluanvan, diemluanvan
DaiHoc::DaiHoc(string MASV, string name, string address, int tinchi, double dtb, string tenluanvan, double diemluanvan)
    : SinhVien(MASV, name, address, tinchi, dtb), tenluanvan(tenluanvan), diemluanvan(diemluanvan){} 
    // Lưu ý: Bạn cần truyền thêm tham số dtb vào constructor lớp cha SinhVien cho đúng cú pháp.

// Nhập thông tin: Gọi hàm Nhập của lớp cha rồi nhập tiếp tên và điểm luận văn
void DaiHoc::Nhap(){
    SinhVien::Nhap();
    cin.ignore(); // Xóa bộ nhớ đệm tránh trôi lệnh nhập chuỗi tenluanvan tiếp theo
    cout << "Nhap ten luan van: ";
    getline(cin, tenluanvan);
    cout << "Nhap diem luan van: ";
    cin >> diemluanvan;
}

// Xuất thông tin: In ra phân loại hệ đào tạo, tên luận văn và điểm luận văn
void DaiHoc::Xuat(){
    SinhVien::Xuat();
    cout << "Dai hoc" << "  " << tenluanvan << "  " << diemluanvan << "\n";
}

// Hàm kiểm tra, trả về chuỗi "DaiHoc" để nhận diện phân loại đối tượng
string DaiHoc::check(){
    return "DaiHoc";
}

// Xét tốt nghiệp hệ Đại học: Đạt nếu tổng tín chỉ >= 170, ĐTB >= 5 và Điểm luận văn >= 5
bool DaiHoc::checkTotNghiep(){
    if(tinchi >= 170 && dtb >= 5 && diemluanvan >= 5) return true;
    return false;
}