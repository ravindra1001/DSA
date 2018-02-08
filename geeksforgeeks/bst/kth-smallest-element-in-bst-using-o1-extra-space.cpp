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

void kthsmalles(TreeNode * root, int &k, int &ans){
	if(root==NULL || k<=0) return;
	kthsmalles(root->left,k,ans);
	k--;
	if(k==0){
		ans = root->val;
		return;
	}
	kthsmalles(root->right,k,ans);
}

int main(){
	vector<int>v = {20,8,4,12,10,14,22};
	TreeNode * root = NULL;
	for(int i=0;i<v.size();i++){
		root = insert(root,v[i]);
	}
	int ans = -1;
	int k=5;
	kthsmalles(root,k,ans);
	cout<<ans<<endl;
	return 0;
}

