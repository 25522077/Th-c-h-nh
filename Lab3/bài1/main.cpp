#include<bits/stdc++.h>
#include "cTamGiac.h"
using namespace std;

int main(){
    // Khai báo đối tượng tam giác 'kq' để xử lý và 'temp' để lưu bản sao gốc
    cTamGiac kq, temp;
    // Khai báo các biến lưu thông số biến hình: độ dời (dx, dy), tỉ lệ (k), góc quay (goc)
    double dx, dy, k, goc;

    // Nhập dữ liệu cho tam giác từ bàn phím
    cout << "Nhap tam giac: " << "\n";
    kq.Nhap(); 
    //Kiểm tra có phải tam giác không
    if(kq.TinhDT()==0){
        cout<<"Ko phai tam giac";
        return 0;
    }
    
    // Sao chép trạng thái ban đầu của tam giác vào biến 'temp' để phục vụ các phép biến hình độc lập
    temp = kq;

    // Nhập vector tịnh tiến (dx, dy)
    cout << "Nhap vector tinh tien: ";
    cin >> dx >> dy;

    // Nhập tỉ lệ phóng to/thu nhỏ k và kiểm tra điều kiện (k phải >= 1)
    cout << "Nhap do phong to: ";
    cin >> k;
    while(k < 1){
        cout << "Do phong sai. Vui long nhap lai: ";
        cin >> k;
    }

    // Nhập giá trị góc quay (đơn vị radian)
    cout << "Nhap goc quay: ";
    cin >> goc;

    // --- HIỂN THỊ THÔNG TIN CƠ BẢN CỦA TAM GIÁC BAN ĐẦU ---
    cout << "Xuat tam giac: " << "\n"; //Xuat tam giac
    kq.Xuat();
    cout << "Chu vi tam giac: " << kq.TinhCV() << "\n"; //Tinh chu vi tam giac
    cout << "Dien tich tam giac: " << kq.TinhDT() << "\n"; // Tinh dien tich tam giac
    cout << "Loai tam giac: ";// Kiem tra tam giac thuoc loai vuong, can, deu, vuong can, thuong
    kq.Test(); // Kiểm tra và in ra loại tam giác (cân, đều, vuông,...)
    // 1. Phép tịnh tiến
    cout << "\n" << "Tinh tien tam giac: " << "\n";
    kq.TinhTien(dx, dy); // Thay đổi tọa độ các đỉnh theo dx, dy
    kq.Xuat();           // Xuất kết quả sau khi tịnh tiến
    
    // 2. Phép phóng to (Sử dụng lại tam giác gốc từ 'temp')
    kq = temp; 
    cout << "Phong to tam giac: " << "\n";
    kq.PhongTo(k);       // Nhân tọa độ các đỉnh với k
    kq.Xuat();
    
    // 3. Phép thu nhỏ (Sử dụng lại tam giác gốc từ 'temp')
    kq = temp;
    cout << "Thu nho tam giac: " << "\n";
    kq.ThuNho(k);        // Chia tọa độ các đỉnh cho k
    kq.Xuat();
    
    // 4. Phép quay (Sử dụng lại tam giác gốc từ 'temp')
    kq = temp;
    cout << "Quay tam giac: " << "\n";
    kq.Quay(goc);        // Xoay các đỉnh quanh gốc tọa độ một góc 'goc'
    kq.Xuat();

    // Reset lại kq về trạng thái gốc trước khi kết thúc chương trình
    kq = temp;
    
    return 0;
}