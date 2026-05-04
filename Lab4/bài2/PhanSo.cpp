#include<iostream>
#include<cmath>
#include "PhanSo.h"
using namespace std;

//Khởi tạo phân số với tử số (ts) và mẫu số (ms)
PhanSo::PhanSo(int ts, int ms){
    this->ts = ts;
    this->ms = ms;
}

// Nạp chồng toán tử nhập: Kiểm tra mẫu số khác 0
istream &operator >>(istream &in, PhanSo &a){
    in >> a.ts >> a.ms;
    while(a.ms == 0){ // Mẫu số không được phép bằng 0
        cout << "Phan so khong hop le. Vui long nhap lai: ";
        in >> a.ms;
    }
    return in;
}

// Hàm tìm Ước chung lớn nhất (UCLN) - Cách làm thủ công
int UCLN(int a, int b){
    int i = 1;
    int S = 1;
    // Tìm UCLN bằng cách duyệt từ 1 đến giá trị nhỏ nhất của a hoặc b
    while(i <= abs(a) && i <= abs(b)){
        if(abs(a) % i == 0 && abs(b) % i == 0) S = i;
        i += 1;
    }
    return S;
}

// Nạp chồng toán tử xuất: In phân số ra màn hình
ostream &operator <<(ostream &out, const PhanSo &a){
    // Nếu tử số chia hết cho mẫu số, in ra số nguyên
    if(a.ts % a.ms == 0){
        out << a.ts / a.ms;
    }
    else{
        // Rút gọn phân số trước khi in
        int common = UCLN(a.ts, a.ms);
        int temptu = a.ts / common;
        int tempmau = a.ms / common;
        
        // Đảm bảo mẫu số luôn dương khi in ra
        if(a.ms > 0){
            out << temptu << "/" << tempmau;
        }
        else{
            out << -temptu << "/" << -tempmau;
        }
    }
    return out;
}

// Toán tử cộng
PhanSo PhanSo::operator +(const PhanSo &another){
    return PhanSo(ts * another.ms + ms * another.ts, ms * another.ms);
}

// Toán tử trừ
PhanSo PhanSo::operator -(const PhanSo &another){
    return PhanSo(ts * another.ms - ms * another.ts, ms * another.ms);
}

// Toán tử nhân
PhanSo PhanSo::operator *(const PhanSo &another){
    return PhanSo(ts * another.ts, ms * another.ms);
}

// Toán tử chia
PhanSo PhanSo::operator /(const PhanSo &another){
    return PhanSo(ts * another.ms, ms * another.ts);
}

// Toán tử so sánh bằng
bool PhanSo::operator ==(const PhanSo &another){
    int common1 = UCLN(ts, ms);
    int temptu1 = ts / common1;
    int tempmau1 = ms / common1;
    
    int common2 = UCLN(another.ts, another.ms);
    int temptu2 = another.ts / common2;
    int tempmau2 = another.ms / common2;
    
    // Chuẩn hóa dấu để so sánh chính xác (mẫu số dương)
    if(tempmau1 < 0) { temptu1 = -temptu1; tempmau1 = -tempmau1; }
    if(tempmau2 < 0) { temptu2 = -temptu2; tempmau2 = -tempmau2; }
    
    return (temptu1 == temptu2 && tempmau1 == tempmau2);
}

// Toán tử so sánh lớn hơn
bool PhanSo::operator >(const PhanSo &another){
    // So sánh bằng cách quy đồng: (ts1*ms2) > (ts2*ms1)
    if(ms * another.ms > 0) return (ts * another.ms - ms * another.ts) > 0;
    else return (ts * another.ms - ms * another.ts) < 0;
}

// Toán tử so sánh nhỏ hơn
bool PhanSo::operator <(const PhanSo &another){
    if(ms * another.ms > 0) return (ts * another.ms - ms * another.ts) < 0;
    else return (ts * another.ms - ms * another.ts) > 0;
}