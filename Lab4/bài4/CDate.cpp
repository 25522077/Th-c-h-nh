#include<iostream>
#include<cmath>
#include "CDate.h"
using namespace std;

// Khởi tạo ngày tháng năm
CDate::CDate(int ngay, int thang, int nam){
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
}

// Nạp chồng toán tử nhập (>>): Nhập ngày, tháng, năm
istream &operator >>(istream &in, CDate &a){
    in >> a.ngay >> a.thang >> a.nam;
    return in;
}

// Hàm đếm số chữ số của một số nguyên (dùng để định dạng in)
int dem(int n){
    if (n == 0) return 1;
    int S = 0;
    while(n > 0){
        S += 1;
        n /= 10; 
    }
    return S;
}

// Kiểm tra năm nhuận: Năm nhuận nếu chia hết cho 400 hoặc (chia hết cho 4 và không chia hết cho 100)
bool checknhuan(int n){
    if(n % 400 == 0) return true;
    if(n % 4 == 0 && n % 100 != 0) return true;
    return false;
}

// Trả về số ngày tối đa trong một tháng cụ thể
int maxday(int thang, int nam){
    int maxday;
    switch(thang){
        case 4: case 6: case 9: case 11: maxday = 30; break;
        case 2: if(checknhuan(nam)) maxday = 29;
                else maxday = 28; break;
        default: maxday = 31; // Các tháng 1, 3, 5, 7, 8, 10, 12
    }
    return maxday;
}

// Nạp chồng toán tử xuất (<<): 
// Hàm này tự động chuẩn hóa ngày (xử lý tràn ngày/tháng) rồi mới in ra
ostream &operator <<(ostream &out, CDate a){
    // Xử lý trường hợp ngày vượt quá số ngày tối đa của tháng hiện tại
    while(a.ngay > maxday(a.thang, a.nam)){
        a.ngay -= maxday(a.thang, a.nam);
        a.thang++;
        if(a.thang > 12){
            a.thang = 1;
            a.nam++;
        }
    }
    // Xử lý trường hợp ngày <= 0 (lùi ngày)
    while(a.ngay <= 0){
        a.thang--;
        if(a.thang <= 0){
            a.nam--;
            a.thang += 12;
        }
        a.ngay += maxday(a.thang, a.nam);
    }
    out << a.ngay << "/" << a.thang << "/" << a.nam;
    return out;
}

// Toán tử cộng (+) số ngày vào ngày hiện tại
CDate CDate::operator +(const int &ngay1){
    return CDate(ngay + ngay1, thang, nam);
}

// Toán tử trừ (-) số ngày ra khỏi ngày hiện tại
CDate CDate::operator -(const int &ngay1){
    return CDate(ngay - ngay1, thang, nam);
}

// Toán tử tăng (++) tiền tố
CDate& CDate::operator ++(){
    ngay++;
    return *this;
} 

// Toán tử tăng (++) hậu tố
CDate CDate::operator ++(int){
    CDate temp = *this;
    ngay++;
    return temp;
}

// Toán tử giảm (--) tiền tố
CDate& CDate::operator --(){
    ngay--;
    return *this;
}

// Toán tử giảm (--) hậu tố
CDate CDate::operator --(int){
    CDate temp = *this;
    ngay--;
    return temp;
}

// Nạp chồng toán tử trừ (-) hai đối tượng CDate (Tính khoảng cách ngày)
int CDate::operator -(const CDate &a){
    // 1. Tạo 2 biến tạm để đếm (không làm thay đổi dữ liệu gốc của biến a và *this)
    int d1 = this->ngay, m1 = this->thang, y1 = this->nam;
    int d2 = a.ngay, m2 = a.thang, y2 = a.nam;
    
    // 2. Đưa về cùng một mốc so sánh (giả sử đưa cả 2 ngày về ngày 1/1/1)
    // Tổng số ngày = Tổng ngày từ năm 1 đến ngày đó
    auto countDays = [&](int d, int m, int y) {
        int total = 0;
        // Cộng dồn ngày của các năm trước
        int i = 1;
        while (i < y) {
            total += ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0)) ? 366 : 365;
            i++;
        }
        // Cộng dồn ngày của các tháng trước
        int j = 1;
        while (j < m) {
            // Logic tính maxday ngay tại đây để hàm "tự cung tự cấp"
            int daysInMonth = 31;
            if (j == 4 || j == 6 || j == 9 || j == 11) daysInMonth = 30;
            else if (j == 2) daysInMonth = ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) ? 29 : 28;
            
            total += daysInMonth;
            j++;
        }
        // Cộng ngày hiện tại
        total += d;
        return total;
    };

    // 3. Tính khoảng cách
    int day1 = countDays(d1, m1, y1);
    int day2 = countDays(d2, m2, y2);
    
    // 4. Trả về hiệu số dương (trị tuyệt đối)
    int diff = day1 - day2;
    return (diff < 0) ? -diff : diff;
}
