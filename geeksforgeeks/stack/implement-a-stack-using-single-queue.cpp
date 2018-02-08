#include <bits/stdc++.h>
using namespace std;
class Stack{
	queue<int>q;

public:
	void pop(){
		q.pop();
	}
	void push(int k){
		int temp = q.size();
		q.push(k);
		for(int i=0;i<temp;i++){
			int temp2 = q.front();q.pop();q.push(temp2);
		}
	}
	int top(){
		return q.front();
	}
	bool empty(){
		return q.empty();
	}
};


int main(){
	Stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	cout<<st.top()<<endl;st.pop();
	cout<<st.top()<<endl;st.pop();
	cout<<st.empty()<<endl;
	return 0;
}