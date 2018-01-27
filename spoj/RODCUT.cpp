#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
string make_double(string str){
	string result = "";
	int carry = 0;
	for(int i=str.length()-1;i>=0;i--){
		int temp = 2*(str[i]-'0') + carry;
		carry = temp/10;
		temp%=10;
		result = (char)(temp+48) + result;
	}
	if(carry) result = (char)(carry + 48) + result;
	return result;
}

int main(){
	int t,n;
	vector<string> v;
	v.push_back("1");
	for(int i=1;i<40;i++){
		v.push_back(make_double(v[i-1]));
	}

	cin>>t;
	while(t--){
		cin>>n;
		cout<<v[n-1]<<endl;
	}
	return 0;
}

