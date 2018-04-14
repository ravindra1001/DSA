#include <bits/stdc++.h>
using namespace std;

vector<int> computeTemporayArray(string pat){
    int n = pat.size();
    vector<int>lps(n,0);
    int index = 0;
    int i = 1;
    while(i<n){
        if(pat[index]==pat[i]){
            index++;
            i++;
            lps[i] = index + 1;
        }
        else{
            if(index!=0){
                index = lps[index-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool kmp(string str, string pat){
    vector<int> lps = computeTemporayArray(pat);
    int i = 0;
    int j = 0;
    int n = str.size(), m = pat.size();
    while(i<n && j<m){
        if(str[i] == pat[j]){
            i++;
            j++;
        }
        else{
            if(j!=0) j = lps[j-1];
            else i++;
        }
    }
    if(j==m) {
        cout<<"found pattern at "<<i-j<<endl;
        return true;
    }
    return false;
}

int main(){
    cout<<kmp("abcd","abc")<<endl;
    return 0;
}