#include<iostream>
using namespace std;
int btd(int n){
    int res=0;
    int base=1; // 2^0
    while(n){
        int last_dig = n%10;
        n=n/10;
        res=res+last_dig*base;
        base *=2;
    }
    return res;
}
int main(){
    int n=1011;
    cout<<btd(n)<<endl;
}