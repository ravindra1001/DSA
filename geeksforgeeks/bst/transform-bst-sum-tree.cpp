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
void preorder(TreeNode * root){
	if(root==NULL) return;
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}

void sumTree(TreeNode * root, int &sum){
	if(root==NULL) return;
	sumTree(root->right,sum);
	sum = sum+root->val;
	root->val = sum-root->val;
	sumTree(root->left,sum);
}

int main(){
	vector<int>v = {11,2,1,7,29,15,40,35};
	TreeNode * root = NULL;
	for(int i=0;i<v.size();i++){
		root = insert(root,v[i]);
	}
	int sum=0;
	sumTree(root,sum);
	preorder(root);
	return 0;
}

