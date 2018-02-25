#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void selection_sort(vector<int>&v){
    int n = v.size();
    if(n==0 || n==1) return;
    int index = 0;

    for(int i=0;i<n;i++){
        int min_index = i;
        int min_element = INT32_MAX;
        
        for(int j=i;j<n;j++){
            if(v[j] < min_element){
                min_element = v[j];
                min_index = j;
            }
        }
        swap(v[i], v[min_index]);
    }
}

int main(){
    vector<int> v = {1,5,3,8,5};
    selection_sort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}



