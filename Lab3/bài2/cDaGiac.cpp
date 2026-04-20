#include<bits/stdc++.h>
#include "cDaGiac.h"
using namespace std;

// Hàm xuất tọa độ tất cả các đỉnh của đa giác ra màn hình
void cDaGiac::Nhap(){
    cout<<"Nhap so dinh cua da giac: ";
    cin>>n; // Nhập số lượng đỉnh n từ bàn phím
    while(n<3){ // Kiểm tra điều kiện đa giác (phải có từ 3 đỉnh trở lên)
        cout<<"So dinh khong hop le vui long nhap lai: ";
        cin>>n;
    }
    int i=0;
    while(i<n){
        cout<<"Nhap a("<<i+1<<"): ";
        a[i].Nhap(); // Gọi hàm nhập của lớp Diem cho từng đỉnh của đa giác
        i+=1;
    }
}
// Hàm xuất tọa độ tất cả các đỉnh của đa giác ra màn hình
void cDaGiac::Xuat(){
    int i=0;
    while(i<n){
        cout<<"a("<<i+1<<")=";
        a[i].Xuat(); // Gọi hàm xuất của lớp Diem cho từng đỉnh
        i+=1;
    }
}

// Hàm tịnh tiến toàn bộ đa giác theo vector (dx, dy)
void cDaGiac::TinhTien(double dx, double dy){
    int i=0;
    while(i<n){
        a[i].x += dx; // Cộng độ dời dx vào hoành độ mỗi đỉnh
        a[i].y += dy; // Cộng độ dời dy vào tung độ mỗi đỉnh
        i+=1;
    }
}

// Hàm phóng to đa giác theo tỉ lệ k (tính từ tâm tọa độ)
void cDaGiac::PhongTo(double k){
    int i=0;
    while(i<n){
        a[i].x *= k; // Nhân hoành độ mỗi đỉnh với hệ số k
        a[i].y *= k; // Nhân tung độ mỗi đỉnh với hệ số k
        i+=1;
    }
}

// Hàm thu nhỏ đa giác theo tỉ lệ k (tính từ tâm tọa độ)
void cDaGiac::ThuNho(double k){
    int i=0;
    while(i<n){
        a[i].x /= k; // Chia hoành độ mỗi đỉnh cho hệ số k
        a[i].y /= k; // Chia tung độ mỗi đỉnh cho hệ số k
        i+=1;
    }
}

// Hàm quay đa giác quanh gốc tọa độ O(0,0) một góc alpha
void cDaGiac::Quay(double rad){
    double tempx, tempy;
    int i=0;
    while(i<n){
        // Áp dụng công thức ma trận quay cho từng đỉnh
        tempx = a[i].x * cos(rad) - a[i].y * sin(rad);
        tempy = a[i].x * sin(rad) + a[i].y * cos(rad);
        a[i].x = tempx; // Cập nhật hoành độ mới sau khi quay
        a[i].y = tempy; // Cập nhật tung độ mới sau khi quay
        i+=1;
    }
}

// Hàm phụ tính độ dài đoạn thẳng nối giữa 2 điểm
double dodai(Diem A, Diem B){
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}
double dodaibinh(Diem A, Diem B){
    return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
}

// Hàm kiểm tra xem đa giác là đa giác đều hay đa giác thường
void cDaGiac::Test(){
    int i=0;
    double k = dodaibinh(a[0], a[1]); // Lấy độ dài bình phương cạnh đầu tiên làm mốc so sánh
    while(i < n-1){
        // So sánh độ dài bình phương các cạnh liên tiếp
        if(k != dodaibinh(a[i], a[i+1])){
            cout << "Da giac thuong" << "\n";
            return; // Nếu có 1 cạnh không bằng mốc thì là đa giác thường
        }
        i+=1;
    }
    // Kiểm tra nốt cạnh cuối cùng nối từ đỉnh n-1 về đỉnh 0
    if(k != dodaibinh(a[n-1], a[0])){
        cout << "Da giac thuong" << "\n";
        return;
    }
    cout << "Da giac deu"; // Nếu tất cả các cạnh bằng nhau thì kết luận là đa giác đều
}

// Hàm tính chu vi của đa giác
double cDaGiac::TinhCV(){
    double k = 0;
    int i = 0;
    while(i < n-1){
        k += dodai(a[i], a[i+1]); // Cộng dồn độ dài các cạnh từ 1 đến n-1
        i+=1;
    }
    k += dodai(a[0], a[n-1]); // Cộng thêm cạnh cuối cùng để khép kín đa giác
    return k; // Trả về tổng chu vi
}

// Hàm tính diện tích đa giác theo công thức Shoelace (Tọa độ giả định)
double cDaGiac::TinhDT(){
    double k = 0;
    int i = 0;
    while(i < n-1){
        // Tính tổng tích chéo của tọa độ các cặp đỉnh liên tiếp
        k += (a[i].x * a[i+1].y - a[i+1].x * a[i].y);
        i+=1;
    }
    // Cộng thêm tích chéo của cặp đỉnh cuối và đỉnh đầu
    k += (a[n-1].x * a[0].y - a[0].x * a[n-1].y);
    return 0.5 * abs(k); // Trả về diện tích (trị tuyệt đối của nửa tổng tích chéo)
}