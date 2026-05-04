#include<iostream>
#include<cmath>
#include<vector>
#include "DaThuc.h"
using namespace std;
// Khởi tạo đa thức với bậc cụ thể.
// Vector hs (hệ số) cần có kích thước là bac + 1 để chứa các hệ số từ x^0 đến x^bac.
DaThuc::DaThuc(int bac){
    this->bac = bac;
    hs.resize(bac + 1);
}

// Nạp chồng toán tử nhập (>>):
// Nhập bậc, sau đó nhập hệ số từ bậc cao nhất đến bậc thấp nhất (x^bac -> x^0).
istream &operator >>(istream &in, DaThuc &a){
    cout << "Nhap bac da thuc: ";
    in >> a.bac;
    a.hs.resize(a.bac + 1);
    
    int i = a.bac;
    while(i >= 0){
        in >> a.hs[i];
        i -= 1;
    }
    return in;
}

// Nạp chồng toán tử xuất (<<):
// Logic in đa thức khá phức tạp vì cần xử lý dấu (+, -) và các trường hợp đặc biệt (x^1, x^0).
ostream &operator <<(ostream &out, const DaThuc &a){
    int i = a.bac;
    bool dau = true; // Biến cờ để kiểm tra xem đã in được số hạng nào chưa
    
    while(i >= 0){
        // Xử lý hệ số dương
        if(a.hs[i] > 0){
            if(dau == false) out << "+"; // In dấu cộng nếu không phải số hạng đầu tiên
            if(i == 0 || a.hs[i] != 1) out << a.hs[i]; // In hệ số nếu khác 1 hoặc là hằng số
            if(i > 0){
                out << "x";
                if(i > 1) out << "^" << i;
            }
            dau = false;
        }
        // Xử lý hệ số âm
        else if(a.hs[i] < 0){
            if(i == 0 || a.hs[i] != -1) out << a.hs[i];
            else if(a.hs[i] == -1 && i != 0) out << "-"; // In dấu trừ nếu hệ số là -1
            
            if(i > 0){
                out << "x";
                if(i > 1) out << "^" << i;
            }
            dau = false;
        }
        i--;
    }
    if(dau) out<<0; //Nếu dau vẫn giữ nguyên thì là đa thức 0
    return out;
}

// Toán tử cộng (+): Cộng hai đa thức
DaThuc DaThuc::operator +(const DaThuc &another){
    // Bậc của kết quả là bậc cao nhất của 2 đa thức
    DaThuc kq(max(bac, another.bac));
    int i = 0;
    while(i < kq.bac + 1){
        double temp1 = (i <= bac) ? hs[i] : 0;
        double temp2 = (i <= another.bac) ? another.hs[i] : 0;
        kq.hs[i] = temp1 + temp2;
        i += 1;
    }
    return kq;
}

// Toán tử trừ (-): Trừ hai đa thức
DaThuc DaThuc::operator -(const DaThuc &another){
    DaThuc kq(max(bac, another.bac));
    int i = 0;
    while(i < kq.bac + 1){
        double temp1 = (i <= bac) ? hs[i] : 0;
        double temp2 = (i <= another.bac) ? another.hs[i] : 0;
        kq.hs[i] = temp1 - temp2;
        i += 1;
    }
    return kq;
}

// Toán tử nhân (*): Nhân hai đa thức
// Kết quả đa thức mới sẽ có bậc bằng tổng hai bậc ban đầu.
DaThuc DaThuc::operator *(const DaThuc &another){
    DaThuc kq(bac + another.bac);
    // Khởi tạo tất cả hệ số bằng 0 trước khi cộng dồn
    for(int k = 0; k <= kq.bac; k++) kq.hs[k] = 0; 
    
    int i = 0;
    while(i < bac + 1){
        int j = 0;
        while(j < another.bac + 1){
            kq.hs[i + j] += hs[i] * another.hs[j];
            j += 1;
        }
        i += 1;
    }
    return kq;
}

// Hàm tính giá trị của đa thức tại x:
// Dùng pow() để tính lũy thừa.
double DaThuc::Tinh(double x){
    double S = 0;
    int i = 0;
    while(i < bac + 1){
        S += hs[i] * pow(x, i);
        i += 1;
    }
    return S;
}