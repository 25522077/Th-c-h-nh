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
phanso MAX(phanso a, phanso b){
    phanso c;
    if(a.ms*b.ms>0){
        if(a.ts*b.ms-b.ts*a.ms>0){
            c.ts=a.ts;
            c.ms=a.ms;
        }
        else{
            c.ts=b.ts;
            c.ms=b.ms;
        }
    }
    else{
      if(a.ts*b.ms-b.ts*a.ms>0){
            c.ts=b.ts;
            c.ms=b.ms;
        }
        else{
            c.ts=a.ts;
            c.ms=a.ms;
        }  
    }
    return c;
}
phanso tong(phanso a, phanso b){
    phanso c;
    c.ts=a.ts*b.ms+a.ms*b.ts;
    c.ms=a.ms*b.ms;
    return c;
}
phanso hieu(phanso a, phanso b){
    phanso c;
    c.ts=a.ts*b.ms-a.ms*b.ts;
    c.ms=a.ms*b.ms;
    return c;
}
phanso tich(phanso a, phanso b){
    phanso c;
    c.ts=a.ts*b.ts;
    c.ms=a.ms*b.ms;
    return c;
}
phanso thuong(phanso a, phanso b){
    phanso c;
    c.ts=a.ts*b.ms;
    c.ms=a.ms*b.ts;
    return c;
}
void rutgon(phanso a){
    if(a.ts%a.ms==0){
        cout<<a.ts/a.ms<<"\n";
    }
    else{
    int temp=UCLN(a.ts, a.ms);
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
    cin>>a.ts>>a.ms;
    cin>>b.ts>>b.ms;
    c=MAX(a, b);
    cout<<"Phan so lon nhat: ";
    rutgon(c);
    c=tong(a, b);
    cout<<"Tong hai phan so: ";
    rutgon(c);
    c=hieu(a, b);
    cout<<"Hieu hai phan so: ";
    rutgon(c);
    c=tich(a, b);
    cout<<"Tich hai phan so: ";
    rutgon(c);
    c=thuong(a, b);
    cout<<"Thuong hai phan so: "
    rutgon(c);
    return 0;

}
