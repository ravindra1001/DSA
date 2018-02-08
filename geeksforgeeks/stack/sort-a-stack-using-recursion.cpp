#include <bits/stdc++.h>
using namespace std;
void sortedInsert(stack<int>&st, int value){
	if(st.empty()){
		st.push(value);
		return;
	}
	if(!st.empty() && st.top()<=value){
		st.push(value);
		return;
	}
	int temp = st.top();st.pop();
	sortedInsert(st,value);
	st.push(temp);
}
void sortStack(stack<int>&st){
	if(st.empty())return;
	int temp = st.top();st.pop();
	sortStack(st);
	sortedInsert(st,temp);
}

int main(){
	stack<int>st;
	st.push(2);
	st.push(10);
	st.push(5);
	st.push(8);
	sortStack(st);

	cout<<st.top()<<endl;st.pop();
	cout<<st.top()<<endl;st.pop();
	cout<<st.top()<<endl;st.pop();
	cout<<st.top()<<endl;st.pop();
	return 0;
}