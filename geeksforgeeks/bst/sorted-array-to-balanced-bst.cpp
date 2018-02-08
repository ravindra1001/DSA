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
TreeNode * sortedToBst(vector<int>&v, int start, int end){
	if(start>end) return NULL;
	int mid = (start+end)/2;
	TreeNode *root = new TreeNode(v[mid]);
	root->left = sortedToBst(v,start,mid-1);
	root->right = sortedToBst(v,mid+1,end);
	return root;
}


int main(){
	vector<int>v = {1,2,3,4,5,6,7,8,9};
	TreeNode * root = sortedToBst(v,0,v.size()-1);
	inorder(root);
	return 0;
}

