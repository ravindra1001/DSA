#include <bits/stdc++.h>
using namespace std;
int fun(string str){
	int n = str.size();
	if(n==0) return 0;
	int ans = 0;
	int current = 0;
	stack<int>st;
	for(int i=0;i<n;i++){
		if(str[i]=='('){
			st.push(str[i]);
		}
		else if(str[i]==')'){
			if(!st.empty() && st.top()=='('){
				st.pop();
				current+=2;
				ans = max(current,ans);
			}
			else{
				ans = max(ans,current);
				current = 0;
			}
		}
	}
	return ans;
}
int main(){
	cout<<fun(")()())")<<endl;
	return 0;
}