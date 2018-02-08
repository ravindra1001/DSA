#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
	TreeNode * left;
	TreeNode * right;
	int val;
	TreeNode(int key){
		this->val = key;
		this->left = NULL;
		this->right = NULL;
	}
};
TreeNode * insert(TreeNode * root, int key){
	if(root==NULL){
		return new TreeNode(key);
	}
	if(key<root->val) root->left = insert(root->left,key);
	else root->right = insert(root->right,key); 
	return root;
}

void inorder(TreeNode * root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}
TreeNode * fun(TreeNode * root, int start, int end){
	if(root==NULL) return NULL;
	root->left = fun(root->left,start,end);
	root->right = fun(root->right,start,end);
	if(root->val<start){
		TreeNode * temp = root->right;
		delete root;
		return temp;
	}
	else if(root->val>end){
		TreeNode * temp = root->left;
		delete root;
		return temp;
	}
	return root;	
}

int main(){
	vector<int>v = {6,-13,-8,14,13,7,15};
	TreeNode * root = NULL;
	for(int i=0;i<v.size();i++){
		root = insert(root,v[i]);
	}
	int start = -10;
	int end = 13;
	fun(root,start,end);
	inorder(root);

	return 0;
}

