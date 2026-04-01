#include<bits/stdc++.h> 
#include "SoPhuc.h"    
using namespace std;    
// Hàm khởi tạo số phức với phần thực và phần ảo truyền vào
SoPhuc::SoPhuc(int iThuc, int iAo){
    this->iThuc = iThuc; // Gán giá trị thực cho thuộc tính iThuc của đối tượng
    this->iAo = iAo;     // Gán giá trị ảo cho thuộc tính iAo của đối tượng
}

// Hàm nhập số phức từ bàn phím
void SoPhuc::Nhap(){
    cin >> iThuc >> iAo; // Nhập lần lượt 2 số nguyên đại diện cho phần thực và ảo
}

// Hàm xuất số phức ra màn hình theo định dạng toán học 
void SoPhuc::Xuat(){
    bool co = false; // Biến cờ hiệu để kiểm tra xem đã in phần thực hay chưa
    
    // Xử lý in phần thực
    if(iThuc != 0){
        cout << iThuc; // Chỉ in khi phần thực khác 0
        co = true;     // Đánh dấu đã có phần thực
    }

    // Xử lý in phần ảo
    if(iAo > 0){
        if(co) cout << "+";        // Nếu đã in phần thực thì cần dấu + để nối
        if(iAo == 1) cout << "i";  // Nếu phần ảo bằng 1 thì chỉ in "i"
        else cout << iAo << "i";   // Nếu ảo > 1 thì in giá trị kèm "i"
    }
    else if(iAo < 0){
        if(iAo == -1) cout << "-i"; // Nếu phần ảo bằng -1 thì in "-i"
        else cout << iAo << "i";    // Nếu ảo < -1 thì in giá trị (đã có dấu trừ) kèm "i"
    }

    // Trường hợp đặc biệt: cả phần thực và ảo đều bằng 0
    if(iAo == 0 && iThuc == 0) cout << iThuc; 
}

// Hàm cộng hai số phức: 
void SoPhuc::TinhTong(SoPhuc a, SoPhuc b){
    iThuc = a.iThuc + b.iThuc; // Phần thực mới = tổng hai phần thực
    iAo = a.iAo + b.iAo;       // Phần ảo mới = tổng hai phần ảo
}

// Hàm trừ hai số phức: 
void SoPhuc::TinhHieu(SoPhuc a, SoPhuc b){
    iThuc = a.iThuc - b.iThuc; // Phần thực mới = hiệu hai phần thực
    iAo = a.iAo - b.iAo;       // Phần ảo mới = hiệu hai phần ảo
}

// Hàm nhân hai số phức: 
void SoPhuc::TinhTich(SoPhuc a, SoPhuc b){
    iThuc = a.iThuc * b.iThuc - a.iAo * b.iAo; // Tính phần thực theo công thức nhân
    iAo = a.iThuc * b.iAo + a.iAo * b.iThuc;   // Tính phần ảo theo công thức nhân
}
//Hàm làm tròn số
void lamtron(double a){
    if(a-(int)a!=0) cout<<fixed<<setprecision(1)<<a; //làm tròn thành số có 1 chữ số thập phân sau dấu phẩy
    else cout<<a;   //giữ số không làm tròn khi không phải số thập phân

}
// Hàm tính thương hai số phức a và b
void SoPhuc::TinhThuong(SoPhuc a, SoPhuc b){
    // Kiểm tra điều kiện mẫu số (số phức b) phải khác 0
    if(b.iThuc == 0 && b.iAo == 0){
        cout << "Ko chia 2 so duoc "; 
        return;
    }
    else{
        cout << "Thuong 2 so phuc: ";
        // Tính phần thực tạm thời (kiểu double để giữ độ chính xác)
        double tempthuc = (double)(a.iThuc * b.iThuc + a.iAo * b.iAo) / (b.iThuc * b.iThuc + b.iAo * b.iAo);
        // Tính phần ảo tạm thời
        double tempao = (double)(a.iAo * b.iThuc - a.iThuc * b.iAo) / (b.iThuc * b.iThuc + b.iAo * b.iAo);
        
        bool co = false; // Biến cờ hiệu hỗ trợ việc in định dạng
        // Logic in phần thực của kết quả chia
        if(tempthuc != 0){
            lamtron(tempthuc); // In thực với độ chính xác 1 chữ số nếu là số thập phân và in chính xác nếu là số nguyên
            co = true;
        }
        // Logic in phần ảo của kết quả chia
        if(tempao > 0){
            if(co) cout << "+"; 
            if(tempao == 1) cout << "i";
            else {
                lamtron(tempao);
                cout << "i";
            }
        }
        else if(tempao < 0){
            if(tempao == -1) cout << "-i";
            else {
                lamtron(tempao);
                cout << "i";
            }
        }
        // Nếu cả thực và ảo đều bằng 0 thì in số 0
        if(tempthuc == 0 && tempao == 0) cout << 0;
    }
}