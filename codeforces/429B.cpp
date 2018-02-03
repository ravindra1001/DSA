#include <iostream>
#include <vector>
#define LL long long
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<LL> > cal(n, vector<LL>(m,0));

	vector<vector<LL> > quad1(n, vector<LL>(m,0));
	vector<vector<LL> > quad2(n, vector<LL>(m,0));
	vector<vector<LL> > quad3(n, vector<LL>(m,0));
	vector<vector<LL> > quad4(n, vector<LL>(m,0));

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>cal[i][j];
		}
	}

	quad1[0][m-1] = cal[0][m-1];
	for(int i=1;i<n;i++){
		quad1[i][m-1] = cal[i][m-1] + quad1[i-1][m-1];
	} 
	for(int j=m-2;j>=0;j--){
		quad1[0][j] = cal[0][j] + quad1[0][j+1];
	}
	for(int i=1;i<n;i++){
		for(int j=m-2;j>=0;j--){
			quad1[i][j] = max(quad1[i-1][j], quad1[i][j+1]) + cal[i][j];
		}
	}


	quad2[0][0] = cal[0][0];
	for(int i=1;i<n;i++){
		quad2[i][0] = cal[i][0] + quad2[i-1][0];
	} 
	for(int j=1;j<m;j++){
		quad2[0][j] = cal[0][j] + quad2[0][j-1];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			quad2[i][j] = max(quad2[i-1][j], quad2[i][j-1]) + cal[i][j];
		}
	}
	


	quad3[n-1][0] = cal[n-1][0];
	for(int i=n-2;i>=0;i--){
		quad3[i][0] = cal[i][0] + quad3[i+1][0];
	} 
	for(int j=1;j<m;j++){
		quad3[n-1][j] = cal[n-1][j] + quad3[n-1][j-1];
	}
	for(int i=n-2;i>=0;i--){
		for(int j=1;j<m;j++){
			quad3[i][j] = max(quad3[i+1][j], quad3[i][j-1]) + cal[i][j];
		}
	}


	quad4[n-1][m-1] = cal[n-1][m-1];
	for(int i=n-2;i>=0;i--){
		quad4[i][m-1] = cal[i][m-1] + quad4[i+1][m-1];
	} 
	for(int j=m-2;j>=0;j--){
		quad4[n-1][j] = cal[n-1][j] + quad4[n-1][j+1];
	}
	for(int i=n-2;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			quad4[i][j] = max(quad4[i+1][j], quad4[i][j+1]) + cal[i][j];
		}
	}

	LL ans = 0;
	for(int i=1;i<n-1;i++){
		for(int j=1;j<m-1;j++){
			ans = max(ans, quad1[i][j+1] + quad2[i-1][j] + quad3[i][j-1] + quad4[i+1][j]);
			ans = max(ans, quad1[i-1][j] + quad2[i][j-1] + quad3[i+1][j] + quad4[i][j+1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}