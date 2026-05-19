#include<vector>
#include "KhachHang.h"
#include "TT.h"
#include "DB.h"
using namespace std;

int main(){
    // --- 1. CẤU HÌNH ĐỌC/GHI FILE VÀ KHỞI TẠO ---
    freopen("input.inp", "r", stdin);   // Chuyển hướng luồng nhập dữ liệu từ file input.inp
    freopen("output.out", "w", stdout); // Chuyển hướng luồng xuất dữ liệu ra file output.out
    
    vector <KhachHang*> a; // Mảng con trỏ lớp cha để quản lý đa hình danh sách khách hàng
    int x, y, z;
    cin >> x >> y >> z;    // Nhập số lượng từng loại: x (Thường), y (Thân thiết), z (Đặc biệt)
    
    int n = x + y + z;     // Tổng số lượng khách hàng
    a.resize(n);           // Cấp phát kích thước mảng vừa đủ n phần tử
    
    int i = 0;
    
    // --- 2. NHẬP DANH SÁCH KHÁCH HÀNG 
    // Nhập x khách hàng thường
    while(i < x){
        a[i] = new KhachHang;
        a[i]->Nhap();
        i += 1;
    }
    // Nhập y khách hàng thân thiết
    while(i < x+y){ 
        a[i] = new TT;
        a[i]->Nhap();
        i += 1;
    }
    // Nhập z khách hàng đặc biệt
    while(i < x+y+z){
        a[i] = new DB;
        a[i]->Nhap();
        i += 1;
    }
    
    // --- 3. XUẤT THÔNG TIN VÀ TÍNH TỔNG DOANH THU ---
    cout<<x<<" "<<y<<" "<<z<<"\n";
    i = 0;
    double S = 0; // Biến tích lũy tổng số tiền công ty thu được
    while(i < n){
        a[i]->Xuat();        // In thông tin từng khách hàng
        S += a[i]->TinhTien(); // Cộng dồn tiền của từng khách hàng vào S
        i += 1;
    }
    cout << "Tong so tien cong ti thu duoc: " << S;
    
    // --- 4. GIẢI PHÓNG BỘ NHỚ ĐỘNG ---
    i = 0;
    while(i < n){
        delete a[i]; // Thu hồi vùng nhớ Heap đã cấp phát cho từng con trỏ
        i += 1;
    }
    return 0;
}