#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int> >g, int s, int t, vector<int>&parent){
    int n = g.size();
    queue<int>q;
    vector<int>visited(n,0);
    visited[s] = 1;
    parent[s] = -1;
    q.push(s);
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int i=0;i<n;i++){
            if(visited[i]==0 &&  g[u][i]>0){
                visited[i] = 1;
                parent[i] = u;
                q.push(i);
            }
        }
    }
    return  (visited[t]==1);
}

int ford_fulkerson(vector<vector<int> >&g, int s,int t){
    int n = g.size();
    vector<vector<int> >rg = g;
    vector<int>parent(n,-1);
    int max_flow = 0;
    while(bfs(rg,s,t,parent)){
        int path_flow = INT_MAX;
        for(int v = t; v!=s; v = parent[v]){
            int u = parent[v];
            path_flow = min(path_flow,rg[u][v]);
        }
        for(int v = t; v!=s; v = parent[v]){
            int u = parent[v];
            rg[u][v]-=path_flow;
            rg[v][u]+=path_flow;
        }
        max_flow+=path_flow;
    }
    return max_flow;
}
int main(){
    int n ,m ,a, b, c;
    cin>>n>>m;
    vector<vector<int> >g(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        g[a][b] = c;
    }
    cout<<ford_fulkerson(g,0,5)<<endl;
    return 0;
}
