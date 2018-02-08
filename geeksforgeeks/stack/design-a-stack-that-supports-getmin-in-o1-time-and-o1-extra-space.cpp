#include <bits/stdc++.h>
using namespace std;
class Stack{
	stack<int>st;
	int minEle;

	int getMin(){
		if(st.empty()) return INT_MAX;
		return minEle;
	}

	int top(){
		if(st.empty()) return INT_MAX;
		return st.top();
	}


	void pop(){
		if(st.empty()) return;
		minEle = 2*minEle-st.top();
		st.pop();
	}

	void push(int k){
		if(st.empty()){
			st.push(k);
			minEle = k;
			return;
		}

		if(k<minEle){
			st.push(2*k-minEle);
			minEle = k;
		}
		else{
			st.push(k);
		}
	}
};
int main(){
		
	return 0;
}