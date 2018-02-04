#include <bits/stdc++.h>
using namespace std;
int V,E;

class Compare{
    public:
        bool operator()(const pair<int,int>&a,const pair<int,int>&b){
        return a.second>b.second;
    }
};
void prim(vector<pair<int,int> >graph[]){
    vector<int>parent(V,-1);
    vector<int>key(V,INT_MAX);
    vector<bool>mstSet(V,0);
    key[0] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int> >, Compare >pq;
    pq.push(make_pair(0,0));

    while(!pq.empty()){
        pair<int,int>p = pq.top();
        pq.pop();
        int u = p.first;
        mstSet[u] = true;
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i].first;
            int w = graph[u][i].second;

            if(mstSet[v]==false && key[v]>w){
                key[v] = w;
                pq.push(make_pair(v,w));
                parent[v] = u;
            }
        }
    }
    for(int i=1;i<V;i++){
        cout<<i<<"  "<<parent[i]<<" "<<key[i]<<endl;
    }
}
int main(){
    int a,b,c;
    cin>>V>>E;
    vector<pair<int,int> >graph[V];
    for(int i=0;i<E;i++){
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    prim(graph);
    return 0;
}
