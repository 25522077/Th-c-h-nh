#include<iostream>
#include<vector>
#include "CMatrix.h"
using namespace std;

int main(){
    CMatrix a, b; 
    
    int n;
    cout << "Nhap ma tran a: " << "\n";
    cin >> a;
    
    cout << "Nhap ma tran b: " << "\n";
    cin >> b;
    
    cout << "Nhap chieu vector (so phan tu): ";
    cin >> n;
    vector<double> c(n); 
    
    cout << "Nhap cac phan tu cua vector: ";
    int i = 0;
    while(i < n){
        cin >> c[i];
        i += 1;
    }

    // Logic xử lý
    // Kiểm tra điều kiện cộng trừ ma trận (cùng số dòng, cùng số cột)
    if(a.getdong() == b.getdong() && a.getcot() == b.getcot()){
        cout << "Tong 2 ma tran: " << "\n" << a + b << "\n";
        cout << "Hieu 2 ma tran: " << "\n" << a - b << "\n";
    }
    else {
        cout << "Khong co tong va hieu cua hai ma tran" << "\n";
    }

    // Kiểm tra điều kiện nhân ma trận (cột ma trận a = dòng ma trận b)
    if(a.getcot() == b.getdong()){
        cout << "Tich cua ma tran a voi b: " << "\n" << a * b << "\n";
    }
    else {
        cout << "Khong co tich cua ma tran a voi b" << "\n";
    }

    // Kiểm tra điều kiện nhân vector với ma trận (số phần tử vector = số dòng ma trận a)
    if(n == a.getdong()){
        cout << "Tich cua vector voi ma tran a: " << "\n" << c * a << "\n";
    }
    else {
        cout << "Khong co tich cua vector voi ma tran a" << "\n";
    }

    return 0;
}