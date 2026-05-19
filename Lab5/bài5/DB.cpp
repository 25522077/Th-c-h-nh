#include "DB.h"

// Hàm khởi tạo: Gọi constructor của lớp cha KhachHang để gán tên, số lượng và đơn giá
DB::DB(string name, int sl, double gia)
    : KhachHang(name, sl, gia) {}

// Hàm tính tiền cho Khách hàng Đặc biệt (Đang dính lỗi chia số nguyên giống bài trước)
double DB::TinhTien(){
    // Công thức hiện tại: Giảm giá 50% trước, sau đó tính thêm 10% thuế VAT
    // LƯU Ý: Phép toán nhân với 50/100 và 110/100 cần được đổi thành số thực (.0) để tránh sai số
    return ((sl * gia) * 50.0 / 100) * 110.0 / 100;
}