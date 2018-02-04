#include <bits/stdc++.h>
using namespace std;
void bellman(vector<pair<pair<int,int>,int > >v,int n, int src){
    int m = v.size();
    vector<int>dist(n,INT_MAX);
    dist[src] = 0;

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int u = v[j].first.first;
            int v1 = v[j].first.second;
            int w = v[j].second;

            if(dist[u]!=INT_MAX && dist[u]+w < dist[v1]){
                dist[v1] = dist[u] + w;
            }
        }
    }
    for(int i=0;i<m;i++){
        int u = v[i].first.first;
        int v1 = v[i].first.second;
        int w = v[i].second;
        if(dist[u]!=INT_MAX && dist[u]+w < dist[v1]){
            cout<<"negative weight cycle detected"<<endl;
            return;
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
}
int main(){
    int n,m,a,b,c;
    cin>>n>>m;
    vector<pair<pair<int,int>,int > >v;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        v.push_back(make_pair(make_pair(a,b),c));//directed graph
        //v.push_back(make_pair(make_pair(b,a),c));//uncomment this for directed graph
    }
    bellman(v,n,0);
    return 0;
}
