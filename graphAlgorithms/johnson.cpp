#include <bits/stdc++.h>
using namespace std;
vector<int> bellman(vector<pair<pair<int,int>,int > >v,int n, int src){
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
    cout<<"dist"<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
    cout<<endl;
    return dist;
}

void dijkstra(vector<vector<pair<int,int> > >v,vector<int>h, int src){
    int n = v.size();
    vector<int>dist(n,INT_MAX);
    set<pair<int,int> >setds;
    setds.insert(make_pair(0,src));
    dist[src] = 0;

    while(!setds.empty()){
        pair<int,int>p = *(setds.begin());
        setds.erase(setds.begin());
        int u = p.second;

        vector<pair<int,int> >::iterator it;
        for(it=v[u].begin();it!=v[u].end();it++){
            int v1 = (*it).first;
            int w = (*it).second;

            if(dist[v1] > dist[u] + w){
                if(dist[v1]!=INT_MAX){
                    setds.erase(setds.find(make_pair(dist[v1],v1)));//vertex is already visited
                }
                dist[v1] = dist[u]+w;
                setds.insert(make_pair(dist[v1],v1));
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<"  "<<dist[i]-(h[src]-h[i])<<endl;//need to subtract previously added terms
    }
}


int main(){
    int n,m,a,b,c;
    cin>>n>>m;
    vector<pair<pair<int,int>,int > >v;
    vector<pair<pair<int,int>,int > >v2;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        v.push_back(make_pair(make_pair(a,b),c));
    }
    v2 = v;
    for(int i=0;i<n;i++){
        v2.push_back(make_pair(make_pair(n,i),0));
    }
    vector<int>dist = bellman(v2,n+1,n);


    vector<vector<pair<int,int> > >v3(n);
    for(int i=0;i<m;i++){
        int a = v[i].first.first;
        int b = v[i].first.second;
        int c = v[i].second;

        c = c + dist[a]-dist[b];
        v3[a].push_back(make_pair(b,c));
        cout<<"a = "<<a<<"  b="<<b<<"  c="<<c<<endl;
    }
    dijkstra(v3,dist,0);
    return 0;
}
