#include<bits/stdc++.h>
#include "cArray.h"
using namespace std;

// Hàm khởi tạo đối tượng cArray (Bao gồm nhập số lượng và nhập giá trị các phần tử)
cArray::cArray(){
    cout<<"Nhap so luong so nguyen cua mang: ";
    cin>>n; // Nhập số lượng phần tử n từ bàn phím
    if(n<=0) a=NULL; // Nếu n không hợp lệ, gán con trỏ mảng bằng NULL
    else a=new int [n]; // Cấp phát động mảng số nguyên có n phần tử
    
    cout<<"Nhap mang: "<<"\n";
    int i=0;
    while(i<n){
        cin>>a[i]; // Nhập giá trị cho từng phần tử trong mảng
        i+=1;
    }
}

// Hàm hủy đối tượng cArray để giải phóng bộ nhớ động
cArray::~cArray(){
    delete []a; // Thu hồi vùng nhớ đã cấp phát cho mảng a
}

// Hàm xuất các phần tử trong mảng ra màn hình
void cArray::Xuat(){
    int i=0;
    while(i<n){
        cout<<a[i]<<" "; // In từng phần tử kèm theo khoảng trắng
        i+=1;
    }
}

// Hàm đếm số lần xuất hiện của một giá trị x trong mảng
int cArray::Count(int x){
    int i=0;
    int k=0; // Biến đếm
    while(i<n){
        if(a[i]==x) k+=1; // Nếu phần tử bằng x thì tăng biến đếm
        i+=1;
    }
    return k; // Trả về số lần xuất hiện
}

// Hàm kiểm tra xem mảng có đang sắp xếp tăng dần hay không
bool cArray::Test(){
    int i=0;
    while(i<n-1){
        if(a[i]>a[i+1]) return false; // Nếu có phần tử trước lớn hơn phần tử sau thì trả về false
        i+=1;
    }
    return true; // Nếu duyệt hết mảng mà không vi phạm thì trả về true
}

// Hàm tìm số lẻ nhỏ nhất trong mảng
int cArray::TimLe(){
    int i=0;
    int k=0; // Biến lưu số lẻ nhỏ nhất
    bool dau=true; // Biến cờ hiệu để xác định số lẻ đầu tiên tìm thấy
    while(i<n){
        // Kiểm tra tính chất lẻ (dùng abs để xử lý cả số âm)
        if(dau && abs(a[i])%2==1){
            k=a[i]; // Gán số lẻ đầu tiên tìm thấy làm mốc
            dau=false;
        }
        // Nếu tìm thấy số lẻ nhỏ hơn giá trị k hiện tại
        if(abs(a[i])%2==1 && a[i]<k) k=a[i];
        i+=1;
    }
    return k; // Trả về số lẻ nhỏ nhất
}

// Hàm phụ kiểm tra số nguyên tố
bool checkSNT(int n){
    if(n<2) return false;
    int i=2;
    while(i<=sqrt(n)){
        if(n%i==0) return false; // Nếu có ước khác 1 và chính nó
        i+=1;
    }
    return true;
}

// Hàm tìm số nguyên tố lớn nhất trong mảng
int cArray::TimSNTMax(){
    int i=0;
    int k=0; // Biến lưu số nguyên tố lớn nhất
    bool dau=true; // Biến cờ hiệu xác định SNT đầu tiên
    while(i<n){
        if(dau && checkSNT(a[i])){
            k=a[i]; // Gán SNT đầu tiên tìm thấy làm mốc
            dau=false;
        }
        // Nếu tìm thấy SNT lớn hơn giá trị k hiện tại
        if(checkSNT(a[i]) && a[i]>k) k=a[i];
        i+=1;
    }
    return k; // Trả về SNT lớn nhất
}

// Hàm sắp xếp mảng theo thứ tự tăng dần (Sử dụng đổi chỗ trực tiếp)
void cArray::SXTangDan(){
    int i=0;
    while(i<n){
        int j=i+1;
        while(j<n){
            if(a[i]>a[j]){ // Nếu phần tử trước lớn hơn phần tử sau
                int temp=a[i]; // Thực hiện hoán vị
                a[i]=a[j];
                a[j]=temp;
            }
            j+=1;
        }
        i+=1;
    }
}

// Hàm sắp xếp mảng theo thứ tự giảm dần
void cArray::SXGiamDan(){
    int i=0;
    while(i<n){
        int j=i+1;
        while(j<n){
            if(a[i]<a[j]){ // Nếu phần tử trước nhỏ hơn phần tử sau
                int temp=a[i]; // Thực hiện hoán vị
                a[i]=a[j];
                a[j]=temp;
            }
            j+=1;
        }
        i+=1;
    }
}