#include<iostream>
#include<vector>
#include "CMatrix.h"
using namespace std;

// Khởi tạo ma trận với số dòng và số cột cho trước
CMatrix::CMatrix(int dong, int cot){
    this->cot = cot;
    this->dong = dong;
    // Khởi tạo vector 2 chiều với kích thước (dong x cot)
    hs.resize(dong, vector<double>(cot));
}

// Nạp chồng toán tử nhập (>>): Nhập dữ liệu cho ma trận
istream &operator >>(istream &in, CMatrix &a){
    cout << "Nhap so dong: ";
    in >> a.dong;
    cout << "Nhap so cot: ";
    in >> a.cot;
    // Thay đổi kích thước vector dựa trên dữ liệu vừa nhập
    a.hs.resize(a.dong, vector<double>(a.cot));
    
    int i = 0;
    while(i < a.dong){
        int j = 0;
        while(j < a.cot){
            // SỬA LỖI: Dùng 'in' thay vì 'cin' để tuân thủ luồng nhập
            in >> a.hs[i][j];
            j += 1;
        }
        i += 1;
    }
    return in;
}

// Nạp chồng toán tử xuất (<<): In ma trận ra màn hình
ostream &operator <<(ostream &out, const CMatrix &a){
    int i = 0;
    while(i < a.dong){
        int j = 0;
        while(j < a.cot){
            // In phần tử và cách
            out << a.hs[i][j] << " ";
            j += 1;
        }
        // Xuống dòng sau khi kết thúc 1 dòng của ma trận
        out << "\n";
        i += 1;
    }
    return out;
}

// Nạp chồng toán tử cộng (+): Cộng 2 ma trận (yêu cầu cùng kích thước)
CMatrix CMatrix::operator +(const CMatrix &another){
    CMatrix kq(dong, cot);
    int i = 0;
    while(i < dong){
        int j = 0;
        while(j < cot){
            kq.hs[i][j] = hs[i][j] + another.hs[i][j];
            j += 1;
        }
        i += 1;
    }
    return kq;
}

// Nạp chồng toán tử trừ (-): Trừ 2 ma trận
CMatrix CMatrix::operator -(const CMatrix &another){
    CMatrix kq(dong, cot);
    int i = 0;
    while(i < dong){
        int j = 0;
        while(j < cot){
            kq.hs[i][j] = hs[i][j] - another.hs[i][j];
            j += 1;
        }
        i += 1;
    }
    return kq;
}

// Nạp chồng toán tử nhân (*): Nhân 2 ma trận
// Công thức: C[i][j] = tổng của (A[i][k] * B[k][j])
CMatrix CMatrix::operator *(const CMatrix &another){
    CMatrix kq(dong, another.cot);
    int i = 0;
    while(i < dong){
        int j = 0;
        while(j < another.cot){
            int k = 0;
            // Thực hiện tính tích vô hướng hàng i của ma trận 1 và cột j của ma trận 2
            while(k < cot){ 
                kq.hs[i][j] += hs[i][k] * another.hs[k][j];
                k += 1;
            }
            j += 1;
        }
        i += 1;
    }
    return kq;
}

// Toán tử nhân vector với ma trận
CMatrix operator *(vector<double> a, const CMatrix &another){
    CMatrix kq(1, another.cot);
    int i = 0;
    while(i < another.cot){
        int j = 0;
        while(j < another.dong){
            kq.hs[0][i] += a[j] * another.hs[j][i];
            j += 1;
        }
        i += 1;
    }
    return kq;
}

// Getter trả về số dòng
int CMatrix::getdong(){
    return this->dong;
}

// Getter trả về số cột
int CMatrix::getcot(){
    return this->cot;
}