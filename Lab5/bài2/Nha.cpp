#include "Nha.h"
using namespace std;

// Hàm khởi tạo kế thừa từ lớp cha BDS và gán giá trị cho loainha
Nha::Nha(string ma, string ngay, double dongia, double dt, string loainha)
    : BDS(ma, ngay, dongia, dt), loainha(loainha){}

// Nhập thông tin: Gọi hàm Nhập của lớp cha và nhập loainha (có vòng lặp kiểm tra tính hợp lệ)
void Nha::Nhap(){
    BDS::Nhap();
    cin.ignore(); // Xóa bộ nhớ đệm để tránh trôi lệnh getline tiếp theo
    cout << "Nhap loai nha thuong nhap N hoac cao cap nhap L: ";
    getline(cin, loainha);
    
    // Vòng lặp bắt buộc người dùng nhập đúng 'N' (Thường) hoặc 'L' (Cao cấp)
    while(loainha != "N" && loainha != "L"){
        cout << "Loi. Vui long nhap lai loai nha: ";
        getline(cin, loainha);
    }
}

// Xuất thông tin: Gọi hàm Xuất lớp cha, in ra phân loại nhà và tổng tiền (lấy 1 chữ số thập phân)
void Nha::Xuat(){
    BDS::Xuat();
    cout << "Nha" << "  " << "loai";
    if(loainha == "N") cout << " binh thuong" << "  " << fixed << setprecision(1) << TinhTien()<<"\n";
    if(loainha == "L") cout << " binh thuong" << "  " << fixed << setprecision(1) << TinhTien()<<"\n"; 
    // Lưu ý: Ở dòng trên cho loại "L", bạn có thể muốn sửa chữ "binh thuong" thành "cao cap" cho đúng ngữ nghĩa.
}

// Tính tiền: Loại thường (N) được giảm giá bằng 90% Đơn giá * Diện tích, loại cao cấp (L) tính đủ 100%
double Nha::TinhTien(){
    if(loainha == "N") return dt * dongia * 90 / 100;
    else return dt * dongia;
}

// Hàm kiểm tra, trả về chuỗi "Nha" để nhận diện phân loại đối tượng
string Nha::check(){
    return "Nha";
}