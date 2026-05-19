#include "CaoDang.h"
using namespace std;

// Hàm khởi tạo kế thừa từ lớp cha SinhVien và gán giá trị cho diemtn (điểm tốt nghiệp)
CaoDang::CaoDang(string MASV, string name, string address, int tinchi, double dtb, double diemtn)
    : SinhVien(MASV, name, address, tinchi, dtb), diemtn(diemtn){}

// Nhập thông tin: Gọi hàm Nhập của lớp cha rồi nhập tiếp điểm tốt nghiệp
void CaoDang::Nhap(){
    SinhVien::Nhap();
    cout << "Nhap diem tot nghiep: ";
    cin >> diemtn;
}

// Xuất thông tin: In ra phân loại hệ đào tạo và điểm tốt nghiệp
void CaoDang::Xuat(){
    SinhVien::Xuat();
    cout << "CaoDang  " << diemtn << "\n";
}

// Hàm kiểm tra, trả về chuỗi "CaoDang" để nhận diện phân loại đối tượng
string CaoDang::check(){
    return "CaoDang";
}

// Xét tốt nghiệp hệ Cao đẳng: Đạt nếu tổng tín chỉ >= 120, ĐTB >= 5 và Điểm tốt nghiệp >= 5
bool CaoDang::checkTotNghiep(){
    if(tinchi >= 120 && dtb >= 5 && diemtn >= 5) return true;
    return false;
}
