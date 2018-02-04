#include <bits/stdc++.h>
using namespace std;
bool detectCycle(vector<vector<int> >&v,vector<int>&visited, vector<int>&st, int s){
    visited[s]=1;
    st[s] = 1;

    for(int i=0;i<v[s].size();i++){
        if(!visited[v[s][i]] && detectCycle(v,visited,st,v[s][i])){
            return true;
        }
        else if(st[v[s][i]]==1){
            return true;
        }
    }
    st[s] = 0;
    return false;
}
int main(){
    int n,m,a,b;
    cin>>n>>m;
    vector<vector<int> >v(n);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
    }
    vector<int>st(n,-1);
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(detectCycle(v,visited,st,i)){
                cout<<"cycle detected"<<endl;
                return 0;
            }
        }
    }
    cout<<"no cycle detected"<<endl;
    return 0;
}
