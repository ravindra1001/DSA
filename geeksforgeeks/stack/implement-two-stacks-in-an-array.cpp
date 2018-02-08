#include <bits/stdc++.h>
using namespace std;
class TwoStack{
	int A[100];
	int left;
	int right;
public:
	void push1(int k);
	void push2(int k);

	void pop1();
	void pop2();

	int top1();
	int top2();
	TwoStack(){
		left=-1;
		right=100;
	}
};

void TwoStack::push1(int k){
	if(left<right-1)
		A[++left] = k;
}

void TwoStack::push2(int k){
	if(right>left+1)
		A[--right] = k;
}

void TwoStack::pop1(){
	if(left>=0)left--;
}

void TwoStack::pop2(){
	if(right<100)right++;
}
int TwoStack::top1(){
	return A[left];
}

int TwoStack::top2(){
	return A[right];
}


int main(){
	TwoStack st;
	st.push1(2);
	st.push1(5);
	st.push1(3);
	st.push2(6);
	st.push2(28);

	cout<<st.top1()<<endl;st.pop1();
	cout<<st.top1()<<endl;st.pop1();
	cout<<st.top2()<<endl;st.pop2();
	return 0;
}