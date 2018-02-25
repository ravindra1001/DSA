//https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
#include <iostream>
#include <stack>
#include <map>
using namespace std;
bool isOperator(char);
bool isOperand(char);
string infixToPostfix(string);

int main(){
	//string expr = "a+b*(c^d-e)^(f+g*h)-i";
	string expr = "A+B";

	cout<<infixToPostfix(expr)<<endl;
	return 0;
}

string infixToPostfix(string expr){
	if(expr.length()==0) return "";
	string postfix = "";
	stack<char>st;
	map<char,int>precedence;
	precedence['+'] = 1;
	precedence['-'] = 1;
	precedence['*'] = 2;
	precedence['/'] = 2;
	int n = expr.length();

	for(int i=0;i<n;i++){
		if(expr[i] == '('){
			st.push(expr[i]);
		}
		else if(expr[i] == ')'){
			while(!st.empty() && st.top()!='('){
				postfix += st.top();st.pop();
			}
			st.pop();
		}
		else if(isOperator(expr[i]) == true){
			while(!st.empty() && st.top() != '(' &&  precedence[st.top()] >= precedence[expr[i]]){
				postfix += st.top();st.pop();
			}
			st.push(expr[i]);
		}
		else{
			postfix += expr[i];
		}
	}
	while(!st.empty()){
		postfix += st.top();st.pop();
	}
	return postfix;
}

bool isOperand(char c){
	if(c>='0' && c <= '9') return true;
	if(c>='a' && c <= 'z') return true;
	if(c>='Z' && c <= 'Z') return true;
	return false;
}

bool isOperator(char c){
	if(c=='+' || c=='-' || c == '*' || c=='/') return true;
	return false;
}