//https://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>price(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>price[i];
	}
	vector<int>dp(n+1,INT_MIN);
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		dp[i] = price[i];
		for(int j=1;j<i;j++){
			dp[i] = max(dp[i],price[j] + dp[i-j]);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}