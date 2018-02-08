#include <bits/stdc++.h>
using namespace std;
int fun(string str){
	if(str.size()%2==1) return -1;
	stack<char>st;
	for(int i=0;i<str.size();i++){
		if(str[i]=='}' && !st.empty() && st.top()=='{')
			st.pop();
		else st.push(str[i]);
	}
	int cnt1=0,cnt2=0;
	while(!st.empty()){
		if(st.top()=='{'){
			cnt1++;
			st.pop();
		}
		else if(st.top()=='}'){
			cnt2++;
			st.pop();
		}
	}
	return 2*min(cnt1,cnt2)+(max(cnt1,cnt2)-min(cnt1,cnt2))/2;
}
int main(){
	cout<<fun("{{{{}}")<<endl;
	return 0;
}