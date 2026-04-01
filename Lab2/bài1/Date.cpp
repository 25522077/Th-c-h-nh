#include<bits/stdc++.h> 
#include "Date.h"      
using namespace std;    

// Hàm khởi tạo đối tượng Date với 3 tham số truyền vào
Date::Date(int iNgay, int iThang, int iNam){
    this->iNgay = iNgay; // Gán giá trị tham số iNgay vào biến thành viên của lớp
    this->iThang = iThang; // Gán giá trị tham số iThang vào biến thành viên của lớp
    this->iNam = iNam;     // Gán giá trị tham số iNam vào biến thành viên của lớp
}

// Hàm nhập dữ liệu từ bàn phím
void Date::Nhap(){
    cin >> iNgay >> iThang >> iNam; // Nhập 3 số nguyên ngày tháng năm
}
// Hàm xuất dữ liệu ra màn hình
void Date::Xuat(){
    cout << iNgay << "/" << iThang << "/" << iNam; // In ra chuỗi định dạng ngày/tháng/năm
}

// Hàm kiểm tra năm nhuận (trả về true nếu nhuận, false nếu không)
bool checknhuan(int n){
    if(n % 400 == 0) return true; // Nếu năm chia hết cho 400 thì là năm nhuận
    if(n % 4 == 0 && n % 100 != 0) return true; // Nếu chia hết cho 4 nhưng không chia hết cho 100 là năm nhuận
    return false; // Các trường hợp còn lại không phải năm nhuận
}

// Hàm cập nhật đối tượng Date sang ngày kế tiếp
void Date::NgayThangNamTiepTheo(){
    int maxday; // Biến cục bộ để lưu số ngày tối đa trong tháng
    
    // Kiểm tra tháng hiện tại để xác định maxday
    switch(iThang){
        case 4: case 6: case 9: case 11: 
            maxday = 30; // Các tháng 4, 6, 9, 11 luôn có 30 ngày
            break;
        case 2: 
            if(checknhuan(iNam)) maxday = 29; // Nếu là năm nhuận, tháng 2 có 29 ngày
            else maxday = 28;                // Nếu không nhuận, tháng 2 có 28 ngày
            break;
        default: 
            maxday = 31; // Các tháng còn lại (1, 3, 5, 7, 8, 10, 12) có 31 ngày
    }

    // Kiểm tra nếu cộng thêm 1 ngày có vượt quá số ngày trong tháng không
    if(iNgay + 1 > maxday){
        iNgay = 1;   // Nếu vượt quá, reset ngày về ngày 1 của tháng mới
        iThang++;    // Tăng tháng hiện tại lên 1
    }
    else {
        iNgay++;     // Nếu chưa vượt quá, chỉ cần tăng ngày lên 1
    }

    // Kiểm tra nếu tháng sau khi tăng vượt quá tháng 12
    if(iThang > 12){
        iNam++;      // Tăng năm hiện tại lên 1
        iThang = 1;  // Reset tháng về tháng 1 của năm mới
    }
}