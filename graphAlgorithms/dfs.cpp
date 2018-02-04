#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>visited;
vector<vector<int> >v;

void dfs(int start){
    visited[start] = 1;
    cout<<start<<" ";
    for(int i=0;i<v[start].size();i++){
        int temp = v[start][i];
        if(visited[temp]==0){
            dfs(temp);
        }
    }

}
int main(){
    int n,m,a,b;
    cin>>n>>m;
    vector<int>temp(n,0);
    visited = temp;
    v.resize(n);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            dfs(i);
        }
    }
    return 0;
}
