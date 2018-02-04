//https://www.codechef.com/problems/SUBMAT
//https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
#include <iostream>
using namespace std;
int main(){
	int t,m,n, result;
	int mat[100][100];
	int dp[100][100];
	cin>>t;
	while(t--){
		result = 0;
		cin>>m>>n;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>mat[i][j];
				if(i==0 || j==0 || mat[i][j] == 0){
					dp[i][j] = mat[i][j];
				}
				else{
					dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
				}
				result = max(result, dp[i][j]);
			}
		}
		cout<<result<<endl;
	}
	return 0;
}