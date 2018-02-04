//http://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/
#include <bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<pair<int,int> > >v,int src){
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
                /*  If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.  
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them, 
                    we would never reach here.  */
                if(dist[v1]!=INT_MAX){
                    setds.erase(setds.find(make_pair(dist[v1],v1)));//vertex is already visited
                }
                dist[v1] = dist[u]+w;
                setds.insert(make_pair(dist[v1],v1));
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<"  "<<dist[i]<<endl;
    }
}

int main(){
    int n,m,a,b,c;
    cin>>n>>m;
    vector<vector<pair<int,int> > >v(n);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    dijkstra(v,0);
    return 0;
}
