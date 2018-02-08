#include <bits/stdc++.h>
using namespace std;
int main(){
	string expr = "((a+b)+((c+d)))";
	int n  = expr.size();
	stack<char>st;
	for(int i=0;i<n;i++){
		if(expr[i]!=')'){
			st.push(expr[i]);
		}
		else{
			int cnt = 0;
			while(!st.empty() && st.top()!='('){
				cnt++;
				st.pop();
			}
			st.pop();
			if(cnt==0){
				cout<<"duplicate parenthasis"<<endl;
				//break;
			}
		}
	}
	return 0;
}