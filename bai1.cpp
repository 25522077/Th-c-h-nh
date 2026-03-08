#include<bits/stdc++.h>
using namespace std;

// struct dùng để lưu phân số gồm tử số (ts) và mẫu số (ms)
struct phanso{
    int ts;
    int ms;
};
// Hàm tìm UCLN (Ước chung lớn nhất) của 2 số a và b
int UCLN(int a, int b){
    a=abs(a);  // lấy giá trị tuyệt đối để tránh số âm
    b=abs(b);
    int i=1;
    int S=1;   // biến lưu UCLN

    // duyệt từ 1 đến min(a,b) để tìm ước chung
    while(i<=a && i<=b){
        if(a%i==0 && b%i==0) S=i;  // nếu i là ước chung thì cập nhật
        i+=1;
    }
    return S;  // trả về UCLN
}
// Hàm rút gọn phân số
phanso rutgon(phanso a){
    int temp=UCLN(a.ts, a.ms);  // tìm UCLN của tử và mẫu

    // nếu mẫu dương thì chia bình thường
    if(a.ms>0){
        a.ts=a.ts/temp;
        a.ms=a.ms/temp;
    }
    else{  // nếu mẫu âm thì đổi dấu để mẫu luôn dương
        a.ts=-a.ts/temp;
        a.ms=-a.ms/temp;
    }

    return a; // trả về phân số đã rút gọn
}
int main(){
    phanso a;

    // nhập tử số và mẫu số
    cin>>a.ts>>a.ms;

    // nếu chia hết thì in số nguyên
    if(a.ts%a.ms==0){
        cout<<a.ts/a.ms;
    }
    else{
        // rút gọn phân số
        a=rutgon(a);

        // in phân số đã rút gọn
        cout<<a.ts<<"/"<<a.ms;
    }

    return 0;
}