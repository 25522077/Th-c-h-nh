#include<iostream>
#include<vector>
#include<algorithm> 
#include "CVector.h"
using namespace std;

// Khởi tạo vector với số chiều xác định
CVector::CVector(int chieu){
    this->chieu = chieu;
    hs.resize(chieu);
}

// Nạp chồng toán tử nhập (>>): Nhập số chiều và các phần tử
istream &operator >>(istream &in, CVector &a){
    cout << "Nhap chieu vector: ";
    in >> a.chieu;
    a.hs.resize(a.chieu); 
    int i = 0;
    while(i < a.chieu){
        in >> a.hs[i];
        i += 1;
    }
    return in;
}

// Nạp chồng toán tử xuất (<<): In vector theo định dạng (x1,x2,...,xn)
ostream &operator <<(ostream &out, const CVector &a){
    out << "(";
    int i = 0;
    while(i < a.chieu){
        out << a.hs[i];
        // Chỉ in dấu phẩy nếu không phải là phần tử cuối cùng
        if(i < a.chieu - 1) out << ","; 
        i += 1;
    }
    out << ")";
    return out;
}

// Nạp chồng toán tử cộng (+): Cộng 2 vector (xử lý trường hợp chiều dài khác nhau)
CVector CVector::operator +(const CVector &another){
    CVector kq(max(chieu, another.chieu));
    int i = 0;
    while(i < kq.chieu){
        // Lấy giá trị nếu i nằm trong phạm vi chiều dài, nếu không thì lấy 0
        double temp1 = (i < chieu) ? hs[i] : 0;
        double temp2 = (i < another.chieu) ? another.hs[i] : 0;
        kq.hs[i] = temp1 + temp2;
        i += 1;
    }
    return kq;
}

// Nạp chồng toán tử trừ (-): Trừ 2 vector
CVector CVector::operator -(const CVector &another){
    CVector kq(max(chieu, another.chieu));
    int i = 0;
    while(i < kq.chieu){
        double temp1 = (i < chieu) ? hs[i] : 0;
        double temp2 = (i < another.chieu) ? another.hs[i] : 0;
        kq.hs[i] = temp1 - temp2;
        i += 1; 
    }
    return kq;
}

// Nạp chồng toán tử nhân (*): Tính tích vô hướng của 2 vector
int CVector::operator *(const CVector &another){
    double S = 0;
    int i = 0;
    int tempchieu = max(chieu, another.chieu);
    while(i < tempchieu){
        double temp1 = (i < chieu) ? hs[i] : 0;
        double temp2 = (i < another.chieu) ? another.hs[i] : 0;
        S += temp1 * temp2;
        i += 1;
    }
    return S;
}