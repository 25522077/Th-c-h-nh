#include "Dat.h"
using namespace std;

// Hàm khởi tạo kế thừa từ lớp cha BDS và gán giá trị cho loaidat
Dat::Dat(string ma, string ngay, double dongia, double dt, string loaidat)
    : BDS(ma, ngay, dongia, dt), loaidat(loaidat){}

// Nhập thông tin: Gọi hàm Nhập của lớp cha và nhập loaidat (có vòng lặp kiểm tra tính hợp lệ)
void Dat::Nhap(){
    BDS::Nhap();
    cin.ignore(); // Xóa bộ nhớ đệm để tránh trôi lệnh getline tiếp theo
    cout << "Nhap loai dat A hoac B hoac C: ";
    getline(cin, loaidat);
    
    // Vòng lặp bắt buộc người dùng nhập đúng một trong ba loại A, B hoặc C
    while(loaidat != "A" && loaidat != "B" && loaidat != "C"){
        cout << "Loi. Vui long nhap lai loai dat: ";
        getline(cin, loaidat);
    }
}

// Xuất thông tin: Gọi hàm lớp cha, in ra phân loại, loại đất và tổng tiền (lấy 1 chữ số thập phân)
void Dat::Xuat(){
    BDS::Xuat();
    cout << "Dat" << "  " << "loai" << loaidat << "  " << fixed << setprecision(1) << TinhTien()<<"\n";
}

// Tính tiền: Loại A tính bằng Diện tích * Đơn giá, loại B và C được nhân thêm hệ số 1.5
double Dat::TinhTien(){
    if(loaidat == "A") return dt * dongia;
    else return dt * dongia * 1.5;
}

// Hàm kiểm tra, trả về chuỗi "Dat" để nhận diện phân loại đối tượng
string Dat::check(){
    return "Dat";
}