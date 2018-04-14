#include <bits/stdc++.h>
using namespace std;

int find_median(int arr1[], int arr2[], int n){
    int count = 0;
    int m1 = -1, m2 = -1;
    int i=0, j=0;

    while(count<=n){
        if(i==n){
            m1 = m2;
            m2 = arr2[0];
            break;
        }
        if(j==n){
            m1 = m2;
            m2 = arr1[0];
            break;
        }

        if(arr1[i]<arr2[j]){
            m1 = m2;
            m2 = arr1[i];
            i++;
        }
        else{
            m1 = m2;
            m2 = arr2[j];
            j++;
        }
        count++;
    }
    return (m1+m2)/2;
}
int main(){
    int arr1[] = {1,2,3,4};
    int arr2[] = {1,2,3,4};
    cout<<find_median(arr1,arr2,4)<<endl;

    return 0;
}