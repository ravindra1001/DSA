#include <iostream>
#include <vector>
#include <utility>
#include <stdio.h>
#include <cstdlib>

using namespace std;

int get_max_value(vector<int>v){
    int max_value = -123456;
    for(int i=0;i<v.size();i++){
        max_value = max(max_value, v[i]);
    }
    return max_value;
}

void count_sort(vector<int> &v){
    int max_value = get_max_value(v);
    vector<int>count(max_value + 1, 0);

    for(int i : v){
        count[i]++;
    }

    int index = 0;
    for(int i=0;i<count.size();i++){
        for(int j=0;j<count[i];j++){
            v[index++] = i;
        }
    }    
}

int main(){
    vector<int>v = {1,4,5,2,6};
    count_sort(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}

