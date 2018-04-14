#include <bits/stdc++.h>
using namespace std;

int find_median(int arr[], int n){
    if(n==0)return -1;

    if(n%2==0)
        return (arr[n/2-1] + arr[n/2])/2;
    else
        return arr[n/2];
}

int find_median(int arr1[], int arr2[], int n){
    if(n<=0) return -1;
    if(n==1) return (arr1[0] + arr2[0])/2;
    if(n==2) return (max(arr1[0],arr2[0])+min(arr1[1],arr2[1]))/2;

    int m1 = find_median(arr1,n);
    int m2 = find_median(arr2,n);

    if(m1==m2) return m1;

    if(m1<m2){
        if(n%2==0) return find_median(arr1 + n/2 -1, arr2, n-n/2+1);
        else return find_median(arr1 + n/2, arr2, n-n/2);
    }
    else{
        if(n%2==0) return find_median(arr1, arr2 + n/2 -1, n-n/2+1);
        else return find_median(arr1, arr2 + n/2, n-n/2);
    }
}

int main(){
    int arr1[] = {1,2,3,4};
    int arr2[] = {1,2,3,4};
    cout<<find_median(arr1,arr2,4)<<endl;
    return 0;
}