#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >& floyed_warshall(vector<vector<int> >&v){
    int n = v.size();
    for(int i=0;i<n;i++){
        v[i][i] = 0;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][k] != INT_MAX && v[k][j] != INT_MAX && v[i][k]+v[k][j] < v[i][j]){
                    v[i][j] = v[i][k] + v[k][j];
                }
            }
        }
    }
    //displaying final  result;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;

    return v;
}


int main(){
    int n,m,a,b,c;
    cin>>n>>m;
    vector<vector<int> >v(n,vector<int>(n,INT_MAX));
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        v[a][b] = c;
    }
    floyed_warshall(v);
    return 0;
}
