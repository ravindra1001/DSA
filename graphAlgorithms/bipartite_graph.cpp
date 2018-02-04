#include <bits/stdc++.h>
using namespace std;
bool bipartite(vector<vector<int> >&v){
    int n = v.size();
    vector<int>color(n,-1);
    color[0] = 1;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<v[u].size();i++){
            int temp = v[u][i];
            if(color[temp]==-1){
                color[temp] = 1-color[u];
                q.push(temp);
            }
            else if(color[temp]==color[u]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n,m,a,b;
    cin>>n>>m;
    vector<vector<int> >v(n);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int>color(n,-1);
    color[0] = 0;
    cout<<bipartite(v)<<endl;
    return 0;
}
