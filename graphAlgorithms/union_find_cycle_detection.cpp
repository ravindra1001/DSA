#include <bits/stdc++.h>
using namespace std;
struct subset{
    int parent;
    int rank;
};
int find(vector<subset>&sbst,int x){
    if(sbst[x].parent != x)
        sbst[x].parent = find(sbst,sbst[x].parent);
    return sbst[x].parent;
}

void Union(vector<subset>&sbst,int x,int y){
    int xroot = find(sbst,x);
    int yroot = find(sbst,y);

    if(sbst[xroot].rank < sbst[yroot].rank){
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

bool isCycle(vector<vector<int> >&v){
    int n = v.size();
    vector<subset>sbst(n);
    for(int i=0;i<n;i++){
        sbst[i].parent = i;
        sbst[i].rank = 0;
    }
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            int x = i;
            int y = v[i][j];

            int xroot = find(sbst,x);
            int yroot = find(sbst,y);

            if(xroot==yroot) return 1;
            Union(sbst,x,y);
        }
    }
    return 0;
}
int main(){
    int n,m,a,b;
    cin>>n>>m;
    vector<vector<int> >v(n);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        //v[b].push_back(a);
    }
    cout<<isCycle(v)<<endl;
    return 0;
}
