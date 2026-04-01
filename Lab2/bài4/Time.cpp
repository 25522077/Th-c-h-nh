#include<bits/stdc++.h> 
#include "Time.h"      
using namespace std;   

// Hàm khởi tạo (Constructor) thời gian với giờ, phút, giây truyền vào
Time::Time(int iGio, int iPhut, int iGiay){
    this->iGio = iGio;   // Gán giá trị tham số iGio vào thuộc tính của đối tượng
    this->iPhut = iPhut; // Gán giá trị tham số iPhut vào thuộc tính của đối tượng
    this->iGiay = iGiay; // Gán giá trị tham số iGiay vào thuộc tính của đối tượng
}

// Hàm nhập thời gian từ bàn phím
void Time::Nhap(){
    cin >> iGio >> iPhut >> iGiay; // nhập 3 số nguyên cho giờ, phút, giây
}

// Hàm xuất thời gian ra màn hình
void Time::Xuat(){
    cout << iGio << ":" << iPhut << ":" << iGiay; // In ra định dạng Giờ:Phút:Giây
}

// Hàm thực hiện cộng thêm một giây vào thời gian hiện tại
void Time::TinhCongThemMotGiay(){
    // Kiểm tra nếu cộng thêm 1 giây có đạt ngưỡng 60 giây không
    if(iGiay + 1 >= 60){ 
        iGiay = 0;       // Nếu đạt 60, reset giây về 0
        iPhut++;         // Tăng thêm 1 phút cho đối tượng
    }
    else {
        iGiay++;         // Nếu chưa đủ 60, chỉ cần tăng giây hiện tại lên 1
    }

    // Kiểm tra nếu số phút sau khi tăng có đạt ngưỡng 60 phút không
    if(iPhut >= 60){     
        iPhut = 0;       // Nếu đạt 60, reset phút về 0
        iGio++;          // Tăng thêm 1 giờ cho đối tượng
    }

    // Kiểm tra nếu số giờ sau khi tăng có đạt ngưỡng 24 giờ không (hết 1 ngày)
    if(iGio >= 24){
        iGio = 0;        // Nếu đạt 24, reset giờ về 0 (bắt đầu ngày mới)
    }
}