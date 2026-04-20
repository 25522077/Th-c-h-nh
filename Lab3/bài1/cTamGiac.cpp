#include<bits/stdc++.h>
#include "cTamGiac.h"
using namespace std;

// Hàm nhập tọa độ 3 đỉnh của tam giác từ bàn phím
void cTamGiac::Nhap(){
    cout<<"Nhap diem A: ";
    A.Nhap(); // Gọi hàm nhập của lớp Diem cho đỉnh A
    cout<<"Nhap diem B: ";
    B.Nhap(); // Gọi hàm nhập của lớp Diem cho đỉnh B
    cout<<"Nhap diem C: ";
    C.Nhap(); // Gọi hàm nhập của lớp Diem cho đỉnh C
}

// Hàm xuất tọa độ 3 đỉnh của tam giác ra màn hình
void cTamGiac::Xuat(){
    cout<<"A=";
    A.Xuat(); // Gọi hàm xuất của lớp Diem cho đỉnh A
    cout<<"B=";
    B.Xuat(); // Gọi hàm xuất của lớp Diem cho đỉnh B
    cout<<"C=";
    C.Xuat(); // Gọi hàm xuất của lớp Diem cho đỉnh C
}

// Hàm tịnh tiến tam giác theo vector (dx, dy)
void cTamGiac::TinhTien(double dx, double dy){
    A.x+=dx; A.y+=dy; // Cộng độ dời dx, dy vào tọa độ điểm A
    B.x+=dx; B.y+=dy; // Cộng độ dời dx, dy vào tọa độ điểm B
    C.x+=dx; C.y+=dy; // Cộng độ dời dx, dy vào tọa độ điểm C
}

// Hàm phóng to tam giác theo tỉ lệ k (tính từ tâm tọa độ)
void cTamGiac::PhongTo(double k){
    A.x*=k; A.y*=k; // Nhân tọa độ điểm A với hệ số k
    B.x*=k; B.y*=k; // Nhân tọa độ điểm B với hệ số k
    C.x*=k; C.y*=k; // Nhân tọa độ điểm C với hệ số k
}

// Hàm thu nhỏ tam giác theo tỉ lệ k (tính từ tâm tọa độ)
void cTamGiac::ThuNho(double k){
    A.x/=k; A.y/=k; // Chia tọa độ điểm A cho hệ số k
    B.x/=k; B.y/=k; // Chia tọa độ điểm B cho hệ số k
    C.x/=k; C.y/=k; // Chia tọa độ điểm C cho hệ số k
}

// Hàm quay tam giác quanh gốc tọa độ O(0,0) một góc alpha
void cTamGiac::Quay(double rad){
    double tempx, tempy;
    
    // Quay điểm A
    tempx = A.x * cos(rad) - A.y * sin(rad);
    tempy = A.x * sin(rad) + A.y * cos(rad);
    A.x = tempx; A.y = tempy;

    // Quay điểm B
    tempx = B.x * cos(rad) - B.y * sin(rad);
    tempy = B.x * sin(rad) + B.y * cos(rad);
    B.x = tempx; B.y = tempy;

    // Quay điểm C
    tempx = C.x * cos(rad) - C.y * sin(rad);
    tempy = C.x * sin(rad) + C.y * cos(rad);
    C.x = tempx; C.y = tempy;
}

// Hàm phụ tính độ dài đoạn thẳng giữa 2 điểm (không thuộc lớp cTamGiac)
double dodai(Diem A, Diem B){
    // Trả về kết quả theo công thức: căn bậc hai của tổng bình phương hiệu tọa độ
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}
double dodaibinh(Diem A, Diem B){
    //Trả về kết quả theo công thức: căn tổng bình phương hiệu tọa độ
    return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
}
// Hàm kiểm tra và in ra loại tam giác
void cTamGiac::Test(){
    bool vuong = false;
    bool can = false;
    bool deu = false;

    // Kiểm tra tính chất tam giác vuông bằng định lý Pytago
    if(dodaibinh(A, B)+dodaibinh(A,C) == dodaibinh(B, C)) vuong = true;
    if(dodaibinh(A, B)+dodaibinh(B, C) == dodaibinh(A, C)) vuong = true;
    if(dodaibinh(B, C)+dodaibinh(A, C) == dodaibinh(A, B)) vuong = true;

    // Kiểm tra tính chất tam giác cân (có 2 cạnh bằng nhau)
    if(dodai(A, B) == dodai(B, C) || dodai(A, C) == dodai(B, C) || dodai(A, B) == dodai(A, C)) can = true;

    // Kiểm tra tính chất tam giác đều (3 cạnh bằng nhau)
    if(dodai(A, B) == dodai(B, C) && dodai(A, B) == dodai(A, C)) deu = true;

    // In kết quả dựa trên các tính chất đã kiểm tra
    if(vuong){
        if(can) cout << "Tam giac vuong can";
        else cout << "Tam giac vuong";
        return;
    }
    if(can){
        if(deu) cout << "Tam giac deu";
        else cout << "Tam giac can";
        return;
    }
    cout << "Tam giac thuong";
}

// Hàm tính chu vi của tam giác
double cTamGiac::TinhCV(){
    // Tổng độ dài 3 cạnh
    return dodai(A, B) + dodai(B, C) + dodai(A, C);
}

// Hàm tính diện tích của tam giác theo công thức Heron
double cTamGiac::TinhDT(){
    double p = (dodai(A, B) + dodai(B, C) + dodai(A, C)) / 2; // Tính nửa chu vi
    // Trả về diện tích theo công thức sqrt(p*(p-a)*(p-b)*(p-c))
    return sqrt(p * (p - dodai(A, B)) * (p - dodai(A, C)) * (p - dodai(B, C)));
}