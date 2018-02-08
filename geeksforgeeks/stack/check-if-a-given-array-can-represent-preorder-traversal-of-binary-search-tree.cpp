#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int>v = {40, 30, 35, 20, 80, 100};
	stack<int>st;
	int min = INT_MIN;
	for(int i=0;i<v.size();i++){
		if(v[i]<min){
			cout<<"invalid sequense"<<endl;
			break;
		}
		int temp = min;
		while(!st.empty() && v[i]>st.top()){
			temp = st.top();st.pop();
		}
		st.push(v[i]);
		min = temp;
	}	
	cout<<"valid sequence"<<endl;
	return 0;
}