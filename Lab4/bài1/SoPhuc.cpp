#include<iostream>
#include "SoPhuc.h"
using namespace std;

// Thiết lập giá trị ban đầu cho phần thực và phần ảo của đối tượng số phức
SoPhuc::SoPhuc(double thuc, double ao){
    this->thuc = thuc;
    this->ao = ao;
}

// Nạp chồng toán tử nhập (>>): 
istream &operator>>(istream &in, SoPhuc &a){
    in >> a.thuc >> a.ao; // Lần lượt nhập phần thực rồi đến phần ảo
    return in;
}

// Nạp chồng toán tử xuất (<<): 
// In số phức ra màn hình theo định dạng đại số (ví dụ: 3+4i, 5-i, 2, -3i, 0...)
ostream &operator<<(ostream &out, const SoPhuc &a){
    // 1. In phần thực nếu nó khác 0
    if(a.thuc != 0) out << a.thuc;
    
    // 2. In dấu '+' nối nếu phần thực khác 0 và phần ảo dương (để tạo dạng a+bi)
    if(a.thuc != 0 && a.ao > 0) out << "+";
    
    // 3. Xử lý in phần ảo
    if(a.ao > 0){
        // Phần ảo dương: nếu khác 1 thì in số, bằng 1 thì bỏ qua số 1 (chỉ in 'i')
        if(a.ao != 1) out << a.ao;
        out << "i";
    }
    else if(a.ao < 0){
        // Phần ảo âm: nếu khác -1 thì in cả số và dấu trừ, bằng -1 thì chỉ in dấu trừ '-'
        if(a.ao != -1) out << a.ao;
        else out << "-";
        out << "i";
    }
    
    // 4. Xử lý trường hợp đặc biệt: Số phức có giá trị bằng 0 (cả thực và ảo đều = 0)
    if(a.thuc == 0 && a.ao == 0) out << 0;
    
    return out;
}

// Nạp chồng toán tử cộng (+): 
// Trả về một đối tượng số phức mới là tổng của 2 số phức (thực+thực, ảo+ảo)
SoPhuc SoPhuc::operator +(const SoPhuc &another){
    return SoPhuc(thuc + another.thuc, ao + another.ao);
}

// Nạp chồng toán tử trừ (-): 
// Trả về một đối tượng số phức mới là hiệu của 2 số phức (thực-thực, ảo-ảo)
SoPhuc SoPhuc::operator -(const SoPhuc &another){
    return SoPhuc(thuc - another.thuc, ao - another.ao);
}

// Nạp chồng toán tử nhân (*): 
// Nhân 2 số phức theo công thức (a+bi)(c+di) = (ac-bd) + (ad+bc)i
SoPhuc SoPhuc::operator *(const SoPhuc &another){
    return SoPhuc(thuc * another.thuc - ao * another.ao, 
                  thuc * another.ao + ao * another.thuc);
}

// Nạp chồng toán tử chia (/): 
// Chia 2 số phức bằng cách nhân cả tử và mẫu cho số phức liên hợp của mẫu
SoPhuc SoPhuc::operator /(const SoPhuc &another){
    // Bình phương độ lớn của mẫu số (c^2 + d^2)
    double mau = another.thuc * another.thuc + another.ao * another.ao;
    
    // Tính phần thực và phần ảo mới
    double thucMoi = (thuc * another.thuc + ao * another.ao) / mau;
    double aoMoi = (ao * another.thuc - thuc * another.ao) / mau;
    
    return SoPhuc(thucMoi, aoMoi);
}

// Nạp chồng toán tử so sánh bằng (==): 
// Kiểm tra 2 số phức có bằng nhau không (thực == thực VÀ ảo == ảo)
bool SoPhuc::operator ==(const SoPhuc &another){
    return (thuc == another.thuc && ao == another.ao);
}

// Nạp chồng toán tử so sánh khác (!=): 
// Kiểm tra 2 số phức có khác nhau không (phủ định của toán tử ==)
bool SoPhuc::operator !=(const SoPhuc &another){
    return !(thuc == another.thuc && ao == another.ao);
}
// Lấy thực
int SoPhuc::getthuc(){
    return this->thuc;
}
// Lấy ảo
int SoPhuc::getao(){
    return this->ao;
}