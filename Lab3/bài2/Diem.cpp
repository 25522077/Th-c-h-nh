#include<bits/stdc++.h>
#include "Diem.h"
using namespace std;
// Hàm khởi tạo đối tượng Diem với 2 tham số truyền vào
Diem::Diem(double x, double y){
    this->x = x; // Gán giá trị tham số x vào biến thành viên (hoành độ) của lớp
    this->y = y; // Gán giá trị tham số y vào biến thành viên (tung độ) của lớp
}
// Hàm nhập dữ liệu tọa độ từ bàn phím
void Diem::Nhap(){
    cin >> x >> y; // Nhập 2 số thực đại diện cho tọa độ x và y từ bàn phím
}
// Hàm xuất dữ liệu tọa độ ra màn hình
void Diem::Xuat(){
    cout << "(" << x << ";" << y << ")" << "\n"; // In ra tọa độ theo định dạng (x;y) 
}
