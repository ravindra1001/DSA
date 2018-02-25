#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int>);
void insertion_sort(vector<int>&);

int main(){
    vector<int>v = {6,7,3,8,4,5};
    insertion_sort(v);
    for(int i =0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void print_vector(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void insertion_sort(vector<int>&v){
    int n = v.size();
    if(n==0 || n==1) return;

    for(int i =1;i<n;i++){
        int key = v[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(key<v[j]){
                v[j+1] = v[j];
                v[j] = key;
            }
        }
    }
}