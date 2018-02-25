#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>&v, int l, int m, int r);
vector<int> merge(vector<int>&, vector<int>&);
void merge_sort(vector<int>&, int, int);


void print_vector(vector<int>v){
    for(auto a : v){
        cout<<a<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>v = {1,8,5,2,15,3};
    print_vector(v);
    merge_sort(v,0,v.size()-1);
    print_vector(v);
    return 0;
}

void merge_sort(vector<int>&v, int left, int right){
    if(left>=right) return;
    int middle = left + (right-left)/2;;
    merge_sort(v, left, middle);
    merge_sort(v, middle + 1, right);

    merge(v, left, middle , right);
}

void merge(vector<int>&v, int l, int m, int r){
    vector<int>v1(v.begin() + l, v.begin() + m + 1);
    vector<int>v2(v.begin() + m+1, v.begin() + r + 1);
    auto temp = merge(v1, v2);
    int index = 0;
    for(int i=l;i<=r;i++){
        v[i] = temp[index++];
    }
}

vector<int> merge(vector<int>&v1, vector<int>&v2){
    int n1 = v1.size();
    int n2 = v2.size();

    vector<int>result;

    if(n1 == 0) return v2;
    if(n2 == 0) return v1;

    int index1 = 0;
    int index2 = 0;

    while(index1 < n1 && index2 < n2){
        if(v1[index1] <= v2[index2]){
            result.push_back(v1[index1++]);
        }
        else{
            result.push_back(v2[index2++]);
        }
    }
    if(index1<n1) result.insert(result.end(), v1.begin()+index1, v1.end());
    if(index2<n2) result.insert(result.end(), v2.begin()+index2, v2.end());

    return result;
}