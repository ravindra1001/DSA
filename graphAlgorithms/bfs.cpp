#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>visited;
vector<vector<int> >v;

void bfs(int start){
    queue<int>q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()){
        int u = q.front();q.pop();
        cout<<u<<" ";
        for(int i=0;i<v[u].size();i++){
            int temp = v[u][i];
            if(visited[temp]==0){
                q.push(temp);
                visited[temp] = 1;
            }
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
            bfs(i);
        }
    }
    return 0;
}

