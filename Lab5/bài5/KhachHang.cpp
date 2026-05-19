#include "KhachHang.h"

// Hàm khởi tạo (Constructor) có tham số để gán giá trị ban đầu cho thuộc tính
KhachHang::KhachHang(string name, int sl, double gia){
        this->name = name; // Gán họ tên khách hàng
        this->sl = sl;     // Gán số lượng mua
        this->gia = gia;   // Gán đơn giá sản phẩm
}

KhachHang::~KhachHang(){}

// Hàm nhập thông tin khách hàng từ bàn phím
void KhachHang::Nhap(){
    cin.ignore();        // Xóa ký tự xuống dòng '\n' còn sót lại trong bộ nhớ đệm trước đó
    getline(cin, name);  // Nhập họ tên (chấp nhận chuỗi có khoảng trắng)
    cin >> sl;           // Nhập số lượng mua
    cin >> gia;          // Nhập đơn giá
}

// Hàm tính tổng tiền khách hàng phải trả (bao gồm cả 10% thuế VAT)
double KhachHang::TinhTien(){
    // Công thức: (Số lượng * Đơn giá) * 110 / 100
    return (sl * gia) * 110.0 / 100;
}

// Hàm xuất thông tin khách hàng ra màn hình
void KhachHang::Xuat(){
    // In tên khách hàng và tổng tiền và làm tròn sau khi tính toán, mỗi thông tin nằm trên 1 dòng
    cout << name << "\n" <<fixed<<setprecision(1)<<TinhTien() << "\n";
}