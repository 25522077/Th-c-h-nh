#include<iostream>
#include<cstring>
#include<string> 
#include "CTime.h"
using namespace std;

//Khởi tạo đối tượng thời gian với giờ, phút, giây
CTime::CTime(int gio, int phut, int giay){
    this->gio = gio;
    this->phut = phut;
    this->giay = giay;
}

// Nạp chồng toán tử nhập (>>): Nhập thông tin thời gian từ bàn phím
istream &operator >>(istream &in, CTime &a){
    in >> a.gio >> a.phut >> a.giay;
    return in;
}

// Hàm bổ trợ: Đếm số chữ số của một số nguyên (dùng để định dạng in ra)
// Ví dụ: đếm(5) = 1, đếm(12) = 2
int dem(int n){
    if(n == 0) return 1;
    int S = 0;
    while(n > 0){
        S += 1;
        n /= 10;
    }
    return S;
}

// Nạp chồng toán tử xuất (<<): In thời gian ra màn hình theo định dạng chuẩn HH:MM:SS
ostream &operator <<(ostream &out, const CTime &a){
    int tonggiay = a.gio * 3600 + a.phut * 60 + a.giay;
    
    // Tính lại giờ, phút, giây sau khi đã cộng dồn (chuẩn hóa về dạng 0-23h, 0-59p, 0-59s)
    int gio1 = tonggiay / 3600 % 24;
    int phut1 = tonggiay % 3600 / 60;
    int giay1 = tonggiay % 3600 % 60;
    
    // Định dạng in: Dùng string(2-dem(n), '0') để chèn số 0 phía trước nếu số nhỏ hơn 10
    out << gio1 << ":" 
        << string(2 - dem(phut1), '0') << phut1 << ":" 
        << string(2 - dem(giay1), '0') << giay1;
    return out;
} 

// Toán tử cộng: Cộng thêm giây vào thời gian hiện tại
// Trả về đối tượng CTime mới (lưu ý: hàm này chưa thực hiện chuẩn hóa bên trong object)
CTime CTime::operator +(const int &giay1){
    return CTime(gio, phut, giay + giay1);
}

// Toán tử trừ: Trừ giây ra khỏi thời gian hiện tại
CTime CTime::operator -(const int &giay1){
    return CTime(gio, phut, giay - giay1);
}

// Toán tử tiền tố (++obj): Tăng giây rồi trả về chính đối tượng đó
CTime &CTime::operator ++(){
    giay++;
    return *this;
}

// Toán tử hậu tố (obj++): Trả về đối tượng cũ (trước khi tăng) rồi mới tăng giây
CTime CTime::operator ++(int){
    CTime temp = *this;
    giay++;
    return temp;
}

// Toán tử tiền tố (--obj): Giảm giây rồi trả về chính đối tượng đó
CTime &CTime::operator --(){
    giay--;
    return *this;
}

// Toán tử hậu tố (obj--): Trả về đối tượng cũ (trước khi giảm) rồi mới giảm giây
CTime CTime::operator --(int){
    CTime temp = *this;
    giay--;
    return temp;
}