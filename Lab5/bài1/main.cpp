#include<iostream>
#include<vector>
#include "NhanVien.h"
#include "NhanVienSX.h"
#include "NhanVienVP.h"
using namespace std;

int main(){
    vector<NhanVien*> a;
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    
    int loai;
    cout << "Nhap loai nhan vien: 0 la NhanVienSX con 1 la NhanVienVP" << "\n";
    a.resize(n);
    
    // --- VÒNG LẶP NHẬP DANH SÁCH NHÂN VIÊN ---
    int i = 0;
    while(i < n){
        cout << "Nhap loai nhan vien: ";
        cin >> loai;
        if(loai == 0){
            a[i] = new NhanVienSX; // Cấp phát động đối tượng Nhân viên sản xuất
            a[i]->Nhap();          // Gọi hàm Nhập (đa hình)
            i += 1;
        }
        else if(loai == 1){
            a[i] = new NhanVienVP; // Cấp phát động đối tượng Nhân viên văn phòng
            a[i]->Nhap();          // Gọi hàm Nhập (đa hình)
            i += 1;
        }
        else cout << "Loi vui long nhap lai" << "\n";
    }
    
    // --- VÒNG LẶP XUẤT DANH SÁCH NHÂN VIÊN ---
    cout << "Danh sach nhan vien: " << "\n";
    i = 0;
    while(i < n){
        a[i]->Xuat(); // Gọi hàm Xuất (đa hình)
        i += 1;
    }
    
    // --- TÍNH TỔNG LƯƠNG CÔNG TY ---
    double S = 0;
    i = 0;
    while(i < n){
        S += a[i]->TinhLuong(); // Cộng dồn lương của từng nhân viên
        i += 1;
    }
    cout << "Tong luong ma cong ti phai tra cho nhan vien: " <<fixed<<setprecision(1)<<S << "\n"; //Làm tròn tổng lương
    
    // --- TÌM LƯƠNG THẤP NHẤT CỦA NHÂN VIÊN SẢN XUẤT (NhanVienSX) ---
    i = 0;
    bool dau = true; // Biến đánh dấu để khởi tạo giá trị min đầu tiên tìm thấy
    S = 0;           // Tái sử dụng biến S làm biến lưu lương min
    while(i < n){
        // Nếu là NhanVienSX (check == true) và là người đầu tiên xét
        if(a[i]->check() && dau == true){
            S = a[i]->TinhLuong();
            dau = false;
        }
        // Cập nhật lương nhỏ hơn nếu tìm thấy NhanVienSX khác có lương thấp hơn
        if(dau == false && a[i]->check() && S > a[i]->TinhLuong()) {
            S = a[i]->TinhLuong();
        }
        i += 1;
    }
    
    // In ra các Nhân viên sản xuất có cùng mức lương thấp nhất
    cout << "Nhan vien san xuat co luong thap nhat: " << "\n";
    i = 0;
    while(i < n){
        if(a[i]->check() && S == a[i]->TinhLuong()) {
            a[i]->Xuat();
        }
        i += 1;
    }
    
    // --- TÌM TUỔI CAO NHẤT CỦA NHÂN VIÊN VĂN PHÒNG (NhanVienVP) ---
    S = 0; // Tái sử dụng biến S làm biến lưu tuổi max
    i = 0;
    while(i < n){
        // Nếu là NhanVienVP (check == false) và có tuổi lớn hơn tuổi max hiện tại
        if(a[i]->check() == false && S < a[i]->TinhTuoi()){
            S = a[i]->TinhTuoi();
        }
        i += 1;
    }
    
    // In ra các Nhân viên văn phòng có cùng số tuổi cao nhất
    cout << "Nhan vien van phong co tuoi cao nhat: " << "\n";
    i = 0;
    while(i < n){
        if(a[i]->check() == false && S == a[i]->TinhTuoi()) {
            a[i]->Xuat();
        }
        i += 1;
    }
    //Giải phóng bộ nhớ
    i=0;
    while(i<n){
        delete a[i];
        i+=1;
    }
    return 0;
}