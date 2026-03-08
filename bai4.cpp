#include<bits/stdc++.h>
using namespace std;

// struct dùng để lưu ngày tháng năm
struct date{
    int day;
    int month;
    int year;
};
// Hàm kiểm tra năm nhuận
bool checknhuan(int n){
    // nếu chia hết cho 4 nhưng không chia hết cho 100 → năm nhuận
    if(n%4==0 && n%100!=0) return true;

    // nếu chia hết cho 400 → năm nhuận
    if(n%400==0) return true;

    // các trường hợp còn lại không phải năm nhuận
    return false;
}
// Hàm tăng thêm 1 ngày cho một ngày cho trước
date tangngay(date a){
    int maxday; // số ngày tối đa của tháng

    // xác định số ngày của từng tháng
    switch(a.month){
        case 4: case 6: case 9: case 11: 
            maxday=30; 
            break;

        case 2: 
            if(checknhuan(a.year)) 
                maxday=29;   // tháng 2 năm nhuận
            else 
                maxday=28;   // tháng 2 năm thường
            break;

        default: 
            maxday=31;      // các tháng còn lại
    }
    // kiểm tra nếu tăng ngày bị vượt số ngày của tháng
    if(a.day+1>maxday){
        a.month++;  // sang tháng mới
        a.day=1;    // ngày đầu tháng
    }
    else{
        a.day++;    // tăng ngày bình thường
    }

    // nếu tháng vượt quá 12 thì sang năm mới
    if(a.month>12){
        a.month=1;
        a.year++;
    }
    return a; // trả về ngày sau khi tăng
}
int main(){
    date a;

    // nhập ngày tháng năm
    cin>>a.day>>a.month>>a.year;

    // tăng thêm 1 ngày
    a=tangngay(a);

    // in kết quả
    cout<<a.day<<"/"<<a.month<<"/"<<a.year;

    return 0;
}