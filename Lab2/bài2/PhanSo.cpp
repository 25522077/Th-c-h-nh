#include<bits/stdc++.h> 
#include "PhanSo.h"     
using namespace std;   

// Hàm khởi tạo phân số với tử số và mẫu số truyền vào
PhanSo::PhanSo(int iTu, int iMau){
    this->iTu = iTu;    // Gán giá trị tham số iTu vào thuộc tính của đối tượng
    this->iMau = iMau;  // Gán giá trị tham số iMau vào thuộc tính của đối tượng
}

// Hàm nhập phân số từ bàn phím
void PhanSo::Nhap(){
    cin >> iTu >> iMau; // Nhập tử số và mẫu số
    // Vòng lặp kiểm tra tính hợp lệ: mẫu số không được bằng 0
    while(!iMau){ 
        cout << "Mau ko hop le. Vui long nhap lai: "; // Thông báo lỗi
        cin >> iTu >> iMau; // Yêu cầu nhập lại cho đến khi mẫu khác 0
    }
}

// Hàm tìm Ước Chung Lớn Nhất (UCLN) của hai số nguyên
int UCLN(int a, int b){
    int i = min(abs(a), abs(b)); // Lấy giá trị nhỏ nhất trong trị tuyệt đối của a và b
    // Vòng lặp chạy lùi từ số nhỏ nhất về 1
    while(i >= 1){
        if(a % i == 0 && b % i == 0) return i; // Nếu cả a và b đều chia hết cho i thì i là UCLN
        i--; // Giảm i để tiếp tục tìm
    }
    return 1; // Nếu không tìm thấy ước chung nào khác thì trả về 1
}

// Hàm xuất phân số ra màn hình ở dạng tối giản
void PhanSo::Xuat(){
    int temp = UCLN(iTu, iMau); // Tìm UCLN để tối giản phân số
    // Kiểm tra nếu tử chia hết cho mẫu (phân số là số nguyên)
    if(iTu % iMau == 0){
        cout << iTu / iMau << "\n"; // In ra kết quả số nguyên
    }
    else{
        // Xử lý dấu của mẫu số để đảm bảo mẫu luôn dương khi in ra
        if(iMau > 0){
            cout << iTu / temp << "/" << iMau / temp << "\n"; // In tử và mẫu đã tối giản
        }
        else{
            // Nếu mẫu âm, chuyển dấu trừ lên tử số
            cout << -iTu / temp << "/" << -iMau / temp << "\n"; 
        }
    }
}

// Hàm tính tổng hai phân số a và b, lưu kết quả vào đối tượng hiện tại
void PhanSo::TinhTong(PhanSo a, PhanSo b){
    iTu = a.iTu * b.iMau + a.iMau * b.iTu; // Công thức: (t1*m2 + t2*m1)
    iMau = a.iMau * b.iMau;                // Công thức: (m1*m2)
}

// Hàm tính hiệu hai phân số a và b, lưu kết quả vào đối tượng hiện tại
void PhanSo::TinhHieu(PhanSo a, PhanSo b){
    iTu = a.iTu * b.iMau - a.iMau * b.iTu; // Công thức: (t1*m2 - t2*m1)
    iMau = a.iMau * b.iMau;                // Công thức: (m1*m2)
}

// Hàm tính tích hai phân số a và b, lưu kết quả vào đối tượng hiện tại
void PhanSo::TinhTich(PhanSo a, PhanSo b){
    iTu = a.iTu * b.iTu;   // Tử nhân tử
    iMau = a.iMau * b.iMau; // Mẫu nhân mẫu
}

// Hàm tính thương hai phân số a và b, lưu kết quả vào đối tượng hiện tại
void PhanSo::TinhThuong(PhanSo a, PhanSo b){
    iTu = a.iTu * b.iMau;  // Tử phân số 1 nhân mẫu phân số 2 (nhân nghịch đảo)
    iMau = a.iMau * b.iTu; // Mẫu phân số 1 nhân tử phân số 2
}

// Hàm so sánh hai phân số a và b
void PhanSo::SoSanh(PhanSo a, PhanSo b){
    // Kiểm tra nếu tích hai mẫu số dương (để quy đồng đơn giản)
    if(a.iMau * b.iMau > 0){
        // So sánh bằng cách nhân chéo: (t1*m2) - (t2*m1)
        if(a.iTu * b.iMau - a.iMau * b.iTu > 0){
            cout << "Phan so a lon hon phan so b";
        }
        else if(a.iTu * b.iMau - a.iMau * b.iTu == 0){
            cout << "2 Phan so bang nhau";
        }
        else{
            cout << "Phan so a nho hon phan so b"; 
        }
    }
}

// Hàm lấy giá trị tử số (Getter)
int PhanSo::getTu(){
    return this->iTu; // Trả về giá trị của biến thành viên iTu
}
