#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void print_vector(vector<int>v){
    for(auto a : v){
        cout<<a<<" ";
    }
    cout<<endl;
}

int partition(vector<int>& v, int left, int right){
    int pivot = v[right];
    int i = left - 1;

    for(int j = left;j<= right-1;j++){
        if(v[j] <= pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[right]);
    return i+1;
}

void quick_sort(vector<int>&v, int left, int right){
    if(left < right){
        int pivot = partition(v, left, right);

        quick_sort(v, left, pivot-1);
        quick_sort(v, pivot + 1, right);
    }
}

int main(){
    vector<int>v = {1,4,3,7,5};
    print_vector(v);
    quick_sort(v, 0, 4);
    print_vector(v);
    return 0;
}

