#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>visited;
vector<vector<int> >v;
stack<int>st;
void topo_sort(int start){
    visited[start] = 1;
    for(int i=0;i<v[start].size();i++){
        int temp = v[start][i];
        if(visited[temp]==0){
            topo_sort(temp);
        }
    }
    st.push(start);
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
            topo_sort(i);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}

