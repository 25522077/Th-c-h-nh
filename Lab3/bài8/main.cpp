#include<bits/stdc++.h>
#include "cNhanVienSX.h"
using namespace std;

int main(){
    int n;
    // Nhập số lượng nhân viên và kiểm tra tính hợp lệ
    cout<<"Nhap so luong nhan vien: ";
    cin>>n;
    while(n<=0){
        cout<<"So luong nhân vien khong hop le. Vui long nhap lai: ";
        cin>>n;
    }
    
    cin.ignore(); // Xóa bộ nhớ đệm để chuẩn bị cho getline bên trong hàm Nhap()
    
    // Cấp phát mảng động chứa n đối tượng nhân viên sản xuất
    cNhanVienSX *a = new cNhanVienSX[n];

    // Vòng lặp thực hiện nhập dữ liệu cho từng nhân viên
    int i=0;
    while(i<n){
        a[i].Nhap();
        i+=1;
    }

    // Xuất danh sách nhân viên vừa nhập ra màn hình
    cout<<"Danh sach nhan vien: "<<"\n";
    i=0;
    while(i<n){
        a[i].Xuat();
        i+=1;
    }

    // TÌM NGƯỜI CÓ LƯƠNG THẤP NHẤT
    i=0;
    double k = a[0].TinhLuong(); // Khởi tạo k bằng lương người đầu tiên
    int temp=0;
    int lan=0;
    while(i<n){
        if(k > a[i].TinhLuong()) k = a[i].TinhLuong(); // Tìm mức lương nhỏ nhất
        i+=1;
    }
    
    i=0;
    while(i<n){
        if(k == a[i].TinhLuong()){
            lan+=1;
            temp=i;
        }
        i+=1; 
    }
    
    if(lan != 1){
        cout<<"Ko co duy nhat nguoi co luong thap nhat"<<"\n";
    }
    else{
        cout<<"Nguoi co luong thap nhat: "<<"\n";
        a[temp].Xuat();
    }

    // TÍNH TỔNG LƯƠNG TOÀN CÔNG TY ---
    i=0;
    double tongluong=0;
    while(i<n){
        tongluong += a[i].TinhLuong(); // Cộng dồn lương của từng nhân viên
        i+=1;
    }
    cout<<"Tong luong cong ti phai tra cho nhan vien san xuat: "<<tongluong << "\n";

    // TÌM NGƯỜI CÓ TUỔI CAO NHẤT ---
    i=0;
    temp=0;
    lan=0;
    k = 0; // Reset k để tìm tuổi lớn nhất
    while(i<n){
        if(k < a[i].GetTuoi()) k = a[i].GetTuoi(); // Tìm số tuổi lớn nhất
        i+=1;
    }
    
    i=0;
    while(i<n){
        if(k == a[i].GetTuoi()){
            lan+=1;
            temp=i;
        }
        i+=1; 
    }
    
    if(lan != 1){
        cout<<"Ko co duy nhat nguoi co tuoi cao nhat"<<"\n";
    }
    else{
        cout<<"Nguoi co tuoi cao nhat: "<<"\n"; 
        a[temp].Xuat();
    }

    // SẮP XẾP DANH SÁCH THEO LƯƠNG TĂNG DẦN
    cout<<"Danh sach nhan vien co luong tang dan: "<<"\n";
    i=0;
    while(i<n){
        int j=i+1;
        while(j<n){
            if(a[i].TinhLuong() > a[j].TinhLuong()){
                cNhanVienSX temp_nv = a[i]; // Hoán vị đối tượng
                a[i] = a[j];
                a[j] = temp_nv;
            }
            j+=1;
        }
        i+=1;
    }

    // Xuất lại danh sách sau khi đã sắp xếp
    i=0;
    while(i<n){
        a[i].Xuat();
        i+=1;
    }

    delete[] a; // Giải phóng bộ nhớ động
    return 0;
}