#include<iostream>
#include<vector>
#include "NhanVien.h"
#include "NVLT.h"
#include "NVKC.h"
using namespace std;

int main(){
    // --- 1. KHỞI TẠO VÀ NHẬP DANH SÁCH NHÂN VIÊN ---
    vector<NhanVien*> a; // Cấp phát vector chứa con trỏ kiểu lớp cha NhanVien (để dùng tính đa hình)
    int n, loai;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    a.resize(n); // Thay đổi kích thước vector theo số lượng nhân viên nhập vào
    
    cout << "Nhap danh sach nhan vien: " << "\n";
    int i = 0;
    while(i < n){
        cout << "Nhap loai nhan vien: loai1: Lap trinh vien, loai2: Kiem chung vien: ";
        cin >> loai;
        if(loai == 1){
            a[i] = new NVLT; // Khởi tạo con trỏ đa hình cho Lập trình viên
            a[i]->Nhap();    // Gọi hàm nhập của lớp NVLT
            i += 1;
        }
        else if(loai == 2){
            a[i] = new NVKC; // Khởi tạo con trỏ đa hình cho Kiểm chứng viên
            a[i]->Nhap();    // Gọi hàm nhập của lớp NVKC
            i += 1;
        }
        else {
            cout << "Loi vui long nhap lai loai nhan vien: "<<"\n";
        }
    }
    
    // --- 2. IN TOÀN BỘ DANH SÁCH NHÂN VIÊN ---
    cout << "Danh sach nhan vien: " << "\n";
    i = 0;
    while(i < n){
        a[i]->Xuat(); // Gọi hàm xuất đa hình tương ứng với từng loại nhân viên
        i += 1;
    }
    
    // --- 3. TÌM NHÂN VIÊN CÓ LƯƠNG THẤP HƠN LƯƠNG TRUNG BÌNH ---
    i = 0;
    double S = 0; // Biến S dùng để tính tổng lương ban đầu
    while(i < n){
        S += a[i]->TinhLuong();
        i += 1;
    }
    S /= n; // Tính lương trung bình của toàn công ty
    
    cout << "Cac nhan vien co muc luong thap hon muc luong trung binh cua cong ty: " << "\n";
    i = 0;
    while(i < n){
        if(a[i]->TinhLuong() < S) {
            a[i]->Xuat();
        }
        i += 1;
    }
    
    // --- 4. TÌM NHÂN VIÊN CÓ LƯƠNG CAO NHẤT CÔNG TY ---
    i = 0;
    S = 0; // Đặt lại S làm mốc tìm lương cực đại
    cout << "Cac nhan vien co muc luong cao nhat: " << "\n";
    while(i < n){
        if(S < a[i]->TinhLuong()) S = a[i]->TinhLuong(); // Tìm mức lương lớn nhất
        i += 1;
    }
    i = 0;
    while(i < n){
        if(a[i]->TinhLuong() == S) a[i]->Xuat(); // In ra tất cả nhân viên đạt mức lương này
        i += 1;
    }
    
    // --- 5. TÌM NHÂN VIÊN CÓ LƯƠNG THẤP NHẤT CÔNG TY ---
    i = 0;
    S = a[0]->TinhLuong(); // Lấy lương nhân viên đầu tiên làm mốc cực tiểu
    cout << "Cac nhan vien co muc luong thap nhat: " << "\n";
    while(i < n){
        if(S > a[i]->TinhLuong()) S = a[i]->TinhLuong(); // Tìm mức lương nhỏ nhất
        i += 1;
    }
    i = 0;
    while(i < n){
        if(a[i]->TinhLuong() == S) a[i]->Xuat(); // In ra tất cả nhân viên đạt mức lương thấp nhất
        i += 1;
    }
    
    // --- 6. TÌM LẬP TRÌNH VIÊN (NVLT) CÓ LƯƠNG CAO NHẤT ---
    i = 0;
    S = 0;
    cout << "Cac lap trinh vien co muc luong cao nhat: " << "\n";
    while(i < n){
        // Lọc đúng loại "NVLT" và tìm lương lớn nhất trong nhóm đó
        if(a[i]->check() == "NVLT" && S < a[i]->TinhLuong()) {
            S = a[i]->TinhLuong();
        }
        i += 1;
    }
    i = 0;
    while(i < n){
        if(a[i]->TinhLuong() == S) a[i]->Xuat(); // In ra các NVLT có lương bằng mức lương cao nhất đó
        i += 1;
    }
    
    // --- 7. TÌM KIỂM CHỨNG VIÊN (NVKC) CÓ LƯƠNG THẤP NHẤT ---
    i = 0;
    S = 0;
    bool dau = true; // Biến cờ hiệu để gán giá trị lương NVKC đầu tiên tìm thấy vào S
    cout << "Cac kiem chung vien co muc luong thap nhat: " << "\n";
    while(i < n){
        if(a[i]->check() == "NVKC" && dau) {
            S = a[i]->TinhLuong();
            dau = false; // Đổi cờ để không chạy lại dòng này nữa
        }
        if(a[i]->check() == "NVKC" && S > a[i]->TinhLuong()) {
            S = a[i]->TinhLuong(); // Tìm lương thấp nhất của NVKC
        }
        i += 1;
    }
    i = 0;
    while(i < n){
        if(a[i]->TinhLuong() == S) a[i]->Xuat(); // In ra các NVKC có lương bằng mức thấp nhất đó
        i += 1;
    }
    
    // --- 8. GIẢI PHÓNG BỘ NHỚ VÙNG ĐỆM HEAP ---
    i = 0;
    while(i < n){
        delete a[i]; // Thu hồi vùng nhớ đã cấp phát bằng từ khóa `new`
        i += 1;
    }
    
    return 0;
}