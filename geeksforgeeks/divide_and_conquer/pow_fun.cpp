#include <bits/stdc++.h>
using namespace std;

int pow_fun(int x, int p){
    if(p==0) return 1;
    if(p==1) return x;
    return pow_fun(x, p/2) * pow_fun(x, p-p/2);
}

int main(){
    cout<<pow_fun(5,3)<<endl;
    return 0;
}