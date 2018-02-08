#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
	TreeNode * left;
	TreeNode * right;
	pair<int,int>val;
	TreeNode(pair<int,int>key){
		this->val = key;
		this->left = NULL;
		this->right = NULL;
	}
};
int compare(pair<int,int>a,pair<int,int>b){
	if(a.first<b.first && a.second<b.first) return -1;
	if(a.first>b.second && a.second>b.second) return 1;
	return 0;
}

TreeNode * insert(TreeNode * root, pair<int,int>key){
	if(root==NULL){
		return new TreeNode(key);
	}
	if(compare(key,root->val)==-1) root->left = insert(root->left,key);
	else if(compare(key,root->val)==1) root->right = insert(root->right,key); 
	else{
		cout<<"conflict ("<<key.first<<", "<<key.second<<" )   with ("<<root->val.first<<", "<<root->val.second<<" )"<<endl;
	}
	return root;
}

int main(){
	TreeNode * root;
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		root = insert(root,make_pair(a,b));
	}
	return 0;
}