#include<bits/stdc++.h>
#include "cDaGiac.h"
using namespace std;

int main(){
    // Khai báo đối tượng kq để xử lý và temp để lưu trữ trạng thái gốc
    cDaGiac kq, temp;
    // Khai báo các biến lưu thông số biến hình: tịnh tiến (dx, dy), phóng to (k), góc quay (goc)
    double dx, dy, k, goc;

    // Nhập dữ liệu cho đa giác (số đỉnh và tọa độ từng đỉnh)
    kq.Nhap(); 
    if(kq.TinhDT()==0){
        cout<<"Ko phai da giac";
        return 0;
    }
    //Gán temp=kq lưu lại đa giác gốc
    temp = kq;

    // Nhập tọa độ vector tịnh tiến từ bàn phím
    cout << "Nhap vector tinh tien: ";
    cin >> dx >> dy;

    // Nhập hệ số tỉ lệ k và kiểm tra tính hợp lệ (k không được nhỏ hơn 1)
    cout << "Nhap do phong to: ";
    cin >> k;
    while(k < 1){
        cout << "Do phong sai. Vui long nhap lai: ";
        cin >> k;
    }

    // Nhập giá trị góc quay (đơn vị rad)
    cout << "Nhap goc quay: ";
    cin >> goc;

    // --- HIỂN THỊ THÔNG TIN ĐA GIÁC BAN ĐẦU ---
    cout << "Xuat da giac: " << "\n";
    kq.Xuat(); // In tọa độ các đỉnh của đa giác
    cout << "Chu vi da giac: " << kq.TinhCV() << "\n"; // Tính và in chu vi
    cout << "Dien tich da giac: " << kq.TinhDT() << "\n"; // Tính và in diện tích
    cout << "Loai da giac: ";
    kq.Test(); // Kiểm tra và in ra loại đa giác (đều hay thường)

    // 1. Phép tịnh tiến đa giác
    cout << "\n" << "Tinh tien da giac: " << "\n";
    kq.TinhTien(dx, dy); // Di chuyển toàn bộ đa giác theo vector (dx, dy)
    kq.Xuat();           // Xuất kết quả sau khi tịnh tiến
    
    // Khôi phục đa giác về trạng thái gốc từ biến temp trước khi thực hiện phép biến hình tiếp theo
    kq = temp;

    // 2. Phép phóng to đa giác
    cout << "Phong to da giac: " << "\n";
    kq.PhongTo(k);       // Nhân tọa độ các đỉnh với hệ số k
    kq.Xuat();
    
    kq = temp; // Khôi phục lại đa giác gốc

    // 3. Phép thu nhỏ đa giác
    cout << "Thu nho da giac: " << "\n";
    kq.ThuNho(k);        // Chia tọa độ các đỉnh cho hệ số k
    kq.Xuat();
    
    kq = temp; // Khôi phục lại đa giác gốc

    // 4. Phép quay đa giác
    cout << "Quay da giac: " << "\n";
    kq.Quay(goc);        // Xoay đa giác quanh gốc tọa độ một góc 'goc'
    kq.Xuat();

    // Reset lại dữ liệu lần cuối để đảm bảo tính nhất quán của chương trình
    kq = temp;

    return 0; // Kết thúc chương trình thành công
}