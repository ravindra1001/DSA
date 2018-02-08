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

void inorder1(TreeNode * root){
	if(root==NULL) return;
	inorder1(root->left);
	cout<<root->val<<" ";
	inorder1(root->right);
}

void inorder(TreeNode * root,vector<int>&v){
	if(root==NULL) return;
	inorder(root->left,v);
	v.push_back(root->val);
	inorder(root->right,v);
}
void inorderToBst(TreeNode * root,vector<int>&v,int &index){
	if(root==NULL) return;
	inorderToBst(root->left,v,index);
	root->val = v[index++];
	inorderToBst(root->right,v,index);
}

int main(){
	TreeNode * root = new TreeNode(10);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(8);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(7);

	vector<int>v;



	inorder(root,v);
	sort(v.begin(),v.end());
	int index = 0;
	inorderToBst(root,v,index);
	inorder1(root);
	return 0;
}

