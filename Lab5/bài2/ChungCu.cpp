#include "ChungCu.h"
using namespace std;

// Hàm khởi tạo kế thừa từ lớp cha BDS và gán giá trị cho ma1 (mã căn), vitri (vị trí tầng)
ChungCu::ChungCu(string ma, string ngay, double dongia, double dt, string ma1, int vitri)
    : BDS(ma, ngay, dongia, dt), ma1(ma1), vitri(vitri){}

// Nhập thông tin: Gọi hàm Nhập của lớp cha rồi nhập tiếp mã căn và vị trí tầng
void ChungCu::Nhap(){
    BDS::Nhap();
    cin.ignore(); // Xóa bộ nhớ đệm để tránh trôi lệnh khi nhập chuỗi ma1 tiếp theo
    cout << "Nhap ma can: ";
    getline(cin, ma1);
    cout << "Nhap vi tri tang: ";
    cin >> vitri;
}

// Xuất thông tin: In ra mã căn, số tầng và tổng tiền (lấy 1 chữ số thập phân)
void ChungCu::Xuat(){
    cout << ma1 << "  " << "tang " << vitri << "  " << fixed << setprecision(1) << TinhTien()<<"\n";
}

// Tính tiền chung cư dựa trên vị trí tầng:
// - Tầng 1: Nhân hệ số 2
// - Tầng 15 trở lên: Nhân hệ số 1.2
// - Các tầng còn lại: Tính giá gốc (Diện tích * Đơn giá)
double ChungCu::TinhTien(){
    if(vitri == 1) return dt * dongia * 2;
    else if(vitri >= 15) return dt * dongia * 1.2;
    else return dt * dongia;
}

// Hàm kiểm tra, trả về chuỗi "ChungCu" để nhận diện phân loại đối tượng
string ChungCu::check(){
    return "ChungCu";
}
