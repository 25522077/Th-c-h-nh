#include<iostream>
#include<vector>
#include "SinhVien.h"
#include "DaiHoc.h"
#include "CaoDang.h"
using namespace std;
int main(){
    vector<SinhVien*> a;
    int n;
    cout<<"Nhap so luong sinh vien: ";
    cin>>n;
    a.resize(n);
    int loai;
    cout<<"Nhap danh sach sinh vien:  "<<"\n";
    int i=0;
    while(i<n){
        cout<<"Nhap loai sinh vien: 1: DaiHoc hoac 2: CaoDang: ";
        cin>>loai;
        if(loai==1){
            a[i]=new DaiHoc;
            a[i]->Nhap();
            i+=1;
        }
        else if(loai==2){
            a[i]=new CaoDang;
            a[i]->Nhap();
            i+=1;
        }
        else cout<<"Loi vui long nhap lai "<<"\n";
    }
    cout<<"Danh sach sinh vien: "<<"'\n";
    i=0;
    while(i<n){
        a[i]->Xuat();
        i+=1;
    }
    cout<<"Danh sach cac sinh vien du dieu kien tot nghiep: "<<"\n";
    i=0;
    while(i<n){
        if(a[i]->checkTotNghiep()) a[i]->Xuat();
        i+=1;
    }  
    cout<<"Danh sach cac sinh vien khong du dieu kien tot nghiep: "<<"\n";
    i=0;
    while(i<n){
        if(a[i]->checkTotNghiep()==false) a[i]->Xuat();
        i+=1;
    }  
    i=0;
    double S=0;
    while(i<n){
        if(a[i]->check()=="DaiHoc" && S<a[i]->DTB()) S=a[i]->DTB();
        i+=1;
    }
    i=0;
    cout<<"Sinh vien dai hoc co diem trung binh cao nhat: "<<"\n";
    while(i<n){
        if(a[i]->check()=="DaiHoc" && a[i]->DTB()==S) a[i]->Xuat();
        i+=1;
    }
    i=0;
    S=0;
    while(i<n){
        if(a[i]->check()=="CaoDang" && S<a[i]->DTB()) S=a[i]->DTB();
        i+=1;
    }
    i=0;
    cout<<"Sinh vien cao dang co diem trung binh cao nhat: "<<"\n";
    while(i<n){
        if(a[i]->check()=="CaoDang" && a[i]->DTB()==S) a[i]->Xuat();
        i+=1;
    }
    cout<<"Danh sach cac sinh vien dai hoc khong du dieu kien tot nghiep: "<<"\n";
    i=0;
    while(i<n){
        if(a[i]->check()=="DaiHoc" && a[i]->checkTotNghiep()==false) a[i]->Xuat();
        i+=1;
    }  
    cout<<"Danh sach cac sinh vien cao dang khong du dieu kien tot nghiep: "<<"\n";
    i=0;
    while(i<n){
        if(a[i]->check()=="CaoDang" && a[i]->checkTotNghiep()==false) a[i]->Xuat();
        i+=1;
    } 
    i=0;
    while(i<n){
        delete a[i];
        i+=1;
    }
    return 0;
}
