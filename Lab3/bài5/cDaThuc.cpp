#include<bits/stdc++.h>
#include "cDaThuc.h"
using namespace std;

// Hàm khởi tạo đa thức với bậc n cho trước
cDaThuc::cDaThuc(int n){
    this->n = n; // Gán giá trị bậc của đa thức
    hs = new double [n+1]; // Cấp phát động mảng hệ số (đa thức bậc n có n+1 hệ số)
    int i = 0;
    while(i < n+1){
        hs[i] = 0; // Khởi tạo tất cả các hệ số bằng 0
        i += 1;
    }
}

// Hàm hủy đối tượng đa thức để giải phóng bộ nhớ
cDaThuc::~cDaThuc(){
    delete []hs; // Thu hồi vùng nhớ mảng hệ số đã cấp phát động
}

// Hàm nhập bậc và các hệ số của đa thức từ bàn phím
void cDaThuc::Nhap(){
    delete []hs; // Giải phóng mảng hệ số cũ trước khi nhập mới
    cout<<"Nhap bac cua da thuc: "; 
    cin >> n; // Nhập bậc của đa thức mới
    hs = new double [n+1]; // Cấp phát lại mảng hệ số theo bậc mới
    int i = n;
    while(i >= 0){
        cin >> hs[i]; // Nhập hệ số của x^i (nhập từ bậc cao nhất về bậc 0)
        i -= 1;
    }
}

// Hàm xuất đa thức ra màn hình theo định dạng chuẩn (ví dụ: ax^n + bx^(n-1) + ...)
void cDaThuc::Xuat(){
    int i = n;
    bool dau = true; // Biến kiểm tra hạng tử đầu tiên để xử lý dấu '+'
    while(i >= 0){
        bool co = false; // Biến đánh dấu hạng tử hiện tại có giá trị khác 0 không
        // Xử lý hạng tử có hệ số dương
        if(hs[i] > 0){
            if(dau == false) cout << "+"; // Nếu không phải hạng tử đầu, in dấu '+'
            if(hs[i] != 1 || i == 0) cout << hs[i]; // Chỉ in hệ số nếu khác 1 hoặc là số hạng tự do
            dau = false;
            co = true;
        }
        // Xử lý hạng tử có hệ số âm
        if(hs[i] < 0){
            if(hs[i] == -1 && i != 0) cout << "-"; // Nếu hệ số là -1, chỉ in dấu '-' trừ số hạng tự do
            else cout << hs[i]; // In giá trị hệ số âm
            dau = false;
            co = true;
        }
        // Xử lý in phần biến x và số mũ
        if(i > 0 && co){
            cout << "x"; // In biến x
            if(i > 1){
                cout << "^" << i; // Nếu bậc > 1 thì in thêm số mũ
            }
        }
        i -= 1;
    }
    if(dau) cout << 0; // Nếu tất cả các hệ số bằng 0, in ra số 0
}

// Hàm tính giá trị của đa thức tại vị trí x cụ thể
double cDaThuc::Tinh(double x){
    int i = 0;
    double S = 0; // Biến tích lũy kết quả
    while(i < n+1){
        S += (hs[i] * pow(x, i)); // Cộng dồn giá trị từng hạng tử: hs_i * x^i
        i += 1;
    }
    return S; // Trả về tổng giá trị của đa thức
}

// Hàm cộng hai đa thức a và b, lưu kết quả vào đối tượng hiện tại
void cDaThuc::Cong2DT(const cDaThuc &a, const cDaThuc &b){
    int i = 0;
    int bac = max(a.n, b.n); // Bậc của đa thức tổng là bậc lớn nhất của a và b
    n = bac;
    delete []hs; // Xóa hệ số cũ của đa thức hiện hành
    hs = new double [n+1]; // Cấp phát bộ nhớ cho đa thức tổng
    while(i <= bac){
        // Lấy hệ số bậc i của a và b (nếu bậc i vượt quá n thì coi hệ số là 0)
        double hs1 = (i <= a.n) ? a.hs[i] : 0;
        double hs2 = (i <= b.n) ? b.hs[i] : 0;
        hs[i] = hs1 + hs2; // Hệ số tổng bằng tổng hai hệ số tương ứng
        i += 1;
    }
}

// Hàm trừ hai đa thức a và b (a - b), lưu kết quả vào đối tượng hiện tại
void cDaThuc::Tru2DT(const cDaThuc &a, const cDaThuc &b){
    int i = 0;
    int bac = max(a.n, b.n);
    n = bac;
    delete []hs;
    hs = new double [n+1];
    while(i <= bac){
        // Lấy hệ số bậc i tương ứng của hai đa thức
        double hs1 = (i <= a.n) ? a.hs[i] : 0;
        double hs2 = (i <= b.n) ? b.hs[i] : 0;
        hs[i] = hs1 - hs2; // Hệ số hiệu bằng hiệu hai hệ số tương ứng
        i += 1;
    }
}