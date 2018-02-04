//http://www.spoj.com/problems/EDIST/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	int t;
	string A,B;
	cin>>t;
	while(t--){
		cin>>A>>B;
		int n=A.length(),m=B.length();
		vector<vector<int> >dp(n+1, vector<int>(m+1, 0));
		for(int i=0;i<=n;i++) dp[i][0] = i;
		for(int j=0;j<=m;j++) dp[0][j] = j;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(A[i-1]==B[j-1]){
					dp[i][j] = dp[i-1][j-1];
					continue;
				}
				dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
			}
		}
		cout<<dp[n][m]<<endl;
	}
	return 0;
}