#include <iostream>
#include <vector>
using namespace std;
void bubble_sort(vector<int>&);

int main(){
    vector<int>v = {4,7,2,8,4,5};
    bubble_sort(v);
    for(int i =0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void bubble_sort(vector<int>&v){
    int n = v.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }
}