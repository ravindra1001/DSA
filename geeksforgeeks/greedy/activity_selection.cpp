#include <bits/stdc++.h>
using namespace std;

//here activities are sorted based on the end time
void activity_selection(int start[], int end[], int n){
    cout<<start[0]<<" "<<end[0]<<endl;
    int preEnd = end[0];
    for(int i=0;i<n;i++){
        if(start[i]>=preEnd){
            cout<<start[i]<<" "<<end[i]<<endl;
            preEnd = end[i];
        }
    }
}

int main(){
    int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    activity_selection(s,f,n);
    return 0;
}