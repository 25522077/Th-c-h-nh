#include<iostream>
#include<vector>
#include "BDS.h"
#include "Dat.h"
#include "Nha.h"
#include "CHungCu.h"
using namespace std;

int main(){
    vector<BDS*> a;
    int n, loai;
    cout << "Nhap so luong BDS: ";
    cin >> n;
    a.resize(n);
    cout << "Nhap BDS: " << "\n";
    
    // --- VÒNG LẶP NHẬP DANH SÁCH BẤT ĐỘNG SẢN ---
    int i = 0;
    while(i < n){
        cout << "Chon BDS, 1: Dat, 2:Nha dat, 3:Chung Cu: ";
        cin >> loai;
        if(loai == 1){
            a[i] = new Dat;       // Đa hình: Khởi tạo đối tượng Đất
            a[i]->Nhap();
            i += 1;
        }
        else if(loai == 2){
            a[i] = new Nha;       // Đa hình: Khởi tạo đối tượng Nhà
            a[i]->Nhap();
            i += 1;
        }
        else if(loai == 3){
            a[i] = new ChungCu;   // Đa hình: Khởi tạo đối tượng Chung cư
            a[i]->Nhap();
            i += 1;
        }
        else cout << "Loi vui long nhap lai" << "\n";
    }
    
    // --- THỐNG KÊ SỐ LƯỢNG TỪNG LOẠI BDS ĐÃ CHOT ---
    i = 0;
    int S1 = 0; // Đếm Đất
    int S2 = 0; // Đếm Nhà
    int S3 = 0; // Đếm Chung cư
    while(i < n){
        if(a[i]->check() == "Dat") S1 += 1;
        else if(a[i]->check() == "Nha") S2 += 1;
        if(a[i]->check() == "ChungCu") S3 += 1; // Lưu ý: Chỗ này nên dùng else if để tối ưu hơn
        i += 1;
    }
    cout << "So luong dat da chot: " << S1 << "\n";
    cout << "So luong nha dat da chot: " << S2 << "\n";
    cout << "So luong chung cu da chot: " << S3 << "\n"; // Sửa lỗi logic của bạn: S1 đổi thành S3 ở đây
    
    // --- TÍNH TRUNG BÌNH TIỀN GIAO DỊCH CỦA CHUNG CƯ ---
    i = 0;
    double S = 0;
    double soluong = 0;
    bool koco = true; // Biến cờ kiểm tra xem có tồn tại chung cư nào không
    while(i < n){
        if(a[i]->check() == "ChungCu"){
            S += a[i]->TinhTien();
            soluong += 1;
            koco = false;
        }
        i += 1;
    }
    if(koco) cout << "Ko co chung cu nao duoc giao dich" << "\n";
    else cout << "Trung binh tien giao dich cua chung cu: " << fixed << setprecision(1) << S / soluong << "\n";
    
    // --- TÌM GIAO DỊCH NHÀ PHỐ (Nha) CÓ GIÁ TRỊ CAO NHẤT ---
    S = 0; // Tái sử dụng S làm biến lưu giá trị max
    i = 0;
    while(i < n){
        if(a[i]->check() == "Nha" && S < a[i]->TinhTien()) S = a[i]->TinhTien();
        i += 1;
    }
    // In ra các giao dịch nhà phố có cùng giá trị cao nhất tìm được
    if(S != 0){
        cout << "Giao dich nha pho co gia tri cao nhat: "<<"\n";
        i = 0;
        while(i < n){
            if(a[i]->check() == "Nha" && S == a[i]->TinhTien()) a[i]->Xuat();
            i += 1;
        }
    }
    else cout << "Khong co giao dich nha pho" << "\n";
    
    // --- XUẤT DANH SÁCH GIAO DỊCH TRONG THÁNG 12 NĂM 2024 ---
    koco = true; // Tái sử dụng biến cờ kiểm tra
    i = 0;
    while(i < n){
        // In tiêu đề một lần duy nhất khi tìm thấy giao dịch đầu tiên thỏa mãn
        if(a[i]->getngay() == "12/2024" && koco == true){
           cout << "Danh sach giao dich vao thang 12 nam 2024" << "\n";
           koco = false;
        }
        if(a[i]->getngay() == "12/2024") a[i]->Xuat();
        i += 1;
    }
    if(koco) cout << "Ko co giao dich vao thang 12 nam 2024" << "\n";
    
    // --- GIẢI PHÓNG BỘ NHỚ ---
    i = 0;
    while(i < n){
        delete a[i]; // Giải phóng vùng nhớ Heap đã cấp phát cho từng con trỏ
        i += 1;
    }
    return 0;
}