#include "TT.h"

// Hàm khởi tạo: Gán các giá trị mặc định cho tham số, gọi constructor của KhachHang và gán thuộc tính 'nam'
TT::TT(string name, int sl, double gia, int nam)
    : KhachHang(name, sl, gia), nam(nam) {}

// Hàm nhập thông tin khách hàng thân thiết
void TT::Nhap(){
    KhachHang::Nhap(); // Kế thừa hàm nhập tên, số lượng, đơn giá từ lớp cha
    cin >> nam;        // Nhập thêm số năm thân thiết
}

// Hàm tính tiền (Đã sửa lỗi chia số thực bằng cách thêm .0)
double TT::TinhTien(){
    // Công thức: (Thành tiền chưa thuế) * (1 - Tỷ lệ giảm giá) * 1.1 (Thuế VAT 10%)
    return (sl * gia) * (1 - max(nam * 5.0 / 100, 50.0 / 100)) * 110.0 / 100;
}