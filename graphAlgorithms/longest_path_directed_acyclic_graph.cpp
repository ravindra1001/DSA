#include <bits/stdc++.h>
using namespace std;
vector<int>visited;
vector<vector<pair<int,int> > >v;
stack<int>st;
int n;

void topo_sort(int start){
    visited[start] = 1;
    for(int i=0;i<v[start].size();i++){
        int temp = v[start][i].first;
        if(visited[temp]==0){
            topo_sort(temp);
        }
    }
    st.push(start);
}

void longest_distance(int s){
    vector<int>dist(n,INT_MAX);
    dist[s] = 0;
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            topo_sort(i);
        }
    }

    while(!st.empty()){
        int u = st.top();st.pop();
        if(dist[u] != INT_MAX){
            for(int i=0;i<v[u].size();i++){
                int temp = v[u][i].first;
                int w = v[u][i].second;
                if(dist[temp]>dist[u]+w*(-1)){
                    dist[temp] = dist[u] + w*(-1);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<"  dist[i] = "<<dist[i]* -1<<endl;
    }
}

int main(){
    int m,a,b,c;
    cin>>n>>m;
    v.resize(n);
    vector<int>temp(n,0);
    visited = temp;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
    }
    longest_distance(1);
    return 0;
}
