#include<bits/stdc++.h>
using namespace std;
// struct lưu phân số gồm tử số (ts) và mẫu số (ms)
struct phanso{
    int ts;
    int ms;
};
// Hàm tìm UCLN (ước chung lớn nhất) của 2 số
int UCLN(int a, int b){
    a=abs(a);  // lấy trị tuyệt đối để tránh số âm
    b=abs(b);
    int i=1;
    int S=1;   // biến lưu UCLN

    // duyệt các số từ 1 đến min(a,b)
    while(i<=a && i<=b){
        if(a%i==0 && b%i==0) S=i; // nếu i là ước chung thì cập nhật
        i+=1;
    }
    return S; // trả về UCLN
}
// Hàm tìm phân số lớn nhất giữa a và b
phanso MAX(phanso a, phanso b){
    phanso c;
    // nếu hai mẫu cùng dấu
    if(a.ms*b.ms>0){
        // so sánh bằng cách quy đồng chéo
        if(a.ts*b.ms-b.ts*a.ms>0){
            c.ts=a.ts;
            c.ms=a.ms;
        }
        else{
            c.ts=b.ts;
            c.ms=b.ms;
        }
    }
    else{ // nếu hai mẫu khác dấu
      if(a.ts*b.ms-b.ts*a.ms>0){
            c.ts=b.ts;
            c.ms=b.ms;
        }
        else{
            c.ts=a.ts;
            c.ms=a.ms;
        }  
    }
    return c; // trả về phân số lớn hơn
}
// Hàm tính tổng hai phân số
phanso tong(phanso a, phanso b){
    phanso c;
    c.ts=a.ts*b.ms+a.ms*b.ts; // tử số sau khi quy đồng
    c.ms=a.ms*b.ms;           // mẫu số sau khi quy đồng
    return c;
}
// Hàm tính hiệu hai phân số
phanso hieu(phanso a, phanso b){
    phanso c;
    c.ts=a.ts*b.ms-a.ms*b.ts;
    c.ms=a.ms*b.ms;
    return c;
}

// Hàm tính tích hai phân số
phanso tich(phanso a, phanso b){
    phanso c;
    c.ts=a.ts*b.ts;
    c.ms=a.ms*b.ms;
    return c;
}
// Hàm tính thương hai phân số
phanso thuong(phanso a, phanso b){
    phanso c;
    c.ts=a.ts*b.ms; // nhân với nghịch đảo của b
    c.ms=a.ms*b.ts;
    return c;
}
// Hàm rút gọn phân số và in ra màn hình
void rutgon(phanso a){
    // nếu phân số là số nguyên
    if(a.ts%a.ms==0){
        cout<<a.ts/a.ms<<"\n";
    }
    else{
        int temp=UCLN(a.ts, a.ms); // tìm UCLN

        // đảm bảo mẫu số luôn dương
        if(a.ms>0){
            cout<<a.ts/temp<<"/"<<a.ms/temp<<"\n";
        }
        else{
            cout<<-a.ts/temp<<"/"<<-a.ms/temp<<"\n";
        }
   }
}
int main(){
    phanso a, b, c;
    // nhập hai phân số
    cin>>a.ts>>a.ms;
    cin>>b.ts>>b.ms;
    // tìm phân số lớn nhất
    c=MAX(a, b);
    cout<<"Phan so lon nhat: ";
    rutgon(c);
    // tính tổng
    c=tong(a, b);
    cout<<"Tong hai phan so: ";
    rutgon(c);
    // tính hiệu
    c=hieu(a, b);
    cout<<"Hieu hai phan so: ";
    rutgon(c);
    // tính tích
    c=tich(a, b);
    cout<<"Tich hai phan so: ";
    rutgon(c);
    // tính thương
    c=thuong(a, b);
    cout<<"Thuong hai phan so: ";
    rutgon(c);
    return 0;
}