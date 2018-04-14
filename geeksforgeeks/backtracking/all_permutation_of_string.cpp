#include <bits/stdc++.h>
using namespace std;
void print_combination(string str, int index){
    int n = str.length();
    if(index>=n){
        cout<<str<<endl;
        return;
    }
    
    for(int i=index;i<n;i++){
        swap(str[index],str[i]);
        print_combination(str, index+1);
        swap(str[i],str[index]);//backtracking
    }
}


int main(){
    print_combination("abc", 0);
    return 0;
}