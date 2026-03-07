#include<bits/stdc++.h>
using namespace std;
struct phanso{
    int ts;
    int ms;
};
int UCLN(int a, int b){
    a=abs(a);
    b=abs(b);
    int i=1;
    int S=1;
    while(i<=a && i<=b){
        if(a%i==0 && b%i==0) S=i;
        i+=1;
    }
    return S;
}
phanso rutgon(phanso a){
    int temp=UCLN(a.ts, a.ms);
    if(a.ms>0){
        a.ts=a.ts/temp;
        a.ms=a.ms/temp;
    }
    else{
         a.ts=-a.ts/temp;
        a.ms=-a.ms/temp;
    }
    return a;
}
int main(){
    phanso a;
    cin>>a.ts>>a.ms;
    if(a.ts%a.ms==0){
        cout<<a.ts/a.ms;
    }
    else{
    a=rutgon(a);
    cout<<a.ts<<"/"<<a.ms;
    }
    return 0;

}
