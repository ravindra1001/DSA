//https://www.codechef.com/problems/CD1IT4
//https://www.hackerearth.com/practice/notes/dynamic-programming-problems-involving-grids/
#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
int main(){
	int M,N,P,i,j;
	cin>>M>>N>>P;
	vector<vector<int> >grid(M, vector<int>(N,0));
	vector<vector<int> >dp(M, vector<int>(N,0));	
	while(P--){
		cin>>i>>j;
		grid[i-1][j-1] = -1;
	}

	if(M==0 || N==0){
		cout<<0<<endl;
		return 0;
	}

	if(grid[0][0] < 0 || grid[M-1][N-1] < 0){
		cout<<0<<endl;
		return 0;
	}


	dp[0][0] = 1;

	for(int i=0;i<M;i++){
		if(grid[i][0]<0) break;
		dp[i][0] = 1;
	}

	for(int i=0;i<N;i++){
		if(grid[0][i]<0) break;
		dp[0][i] = 1;
	}

	for(int i=1;i<M;i++){
		for(int j=1;j<N;j++){
			if(grid[i][j]<0) dp[i][j] = 0;
			else dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
		}
	}

	cout<<dp[M-1][N-1]<<endl;
	return 0;
}