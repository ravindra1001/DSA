#include <bits/stdc++.h>
using namespace std;
struct subset{
    int parent;
    int rank;
};

class Compare{
    public:
    bool operator()(pair<int,pair<int,int> >&a,pair<int,pair<int,int> >&b){
        return a.first>b.first;
    }
};

int find(subset sbst[],int i){
    if(sbst[i].parent != i)
        sbst[i].parent = find(sbst,sbst[i].parent);
    return sbst[i].parent;
}
void Union(subset sbst[],int x,int y){
    int xroot = find(sbst,x);
    int yroot = find(sbst,y);

    if(sbst[xroot].rank<sbst[yroot].rank){
        sbst[xroot].parent = yroot;
    }
    else if(sbst[xroot].rank > sbst[yroot].rank){
        sbst[yroot].parent = xroot;
    }
    else{
        sbst[yroot].parent = xroot;
        sbst[xroot].rank++;
    }
}

void kruskal(priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > > ,Compare>v,int n){
    subset sbst[n];
    int e = 1;
    for(int i=0;i<n;i++){
        sbst[i].rank = 0;
        sbst[i].parent = i;
    }
    while(e<n){
        int w = v.top().first;
        int u = v.top().second.first;
        int v1 = v.top().second.second;
        v.pop();

        int x = find(sbst,u);
        int y = find(sbst,v1);

        if(x!=y){
            Union(sbst,x,y);
            cout<<u<<" "<<v1<<"  "<<w<<endl;
            e++;
        }
    }
}

int main(){
    int n,m,a,b,c;
    priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > > ,Compare>v;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        v.push(make_pair(c,make_pair(a,b)));
    }
    kruskal(v,n);
    return 0;
}
