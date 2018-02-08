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

TreeNode * preorderToBst(vector<int>&v){
	stack<TreeNode *>st;
	TreeNode * root = new TreeNode(v[0]);
	st.push(root);
	for(int i=1;i<v.size();i++){
		TreeNode * temp = NULL;

		while(!st.empty() && v[i]>st.top()->val){
			temp = st.top();
			st.pop();
		}

		if(temp!=NULL){
			temp->right = new TreeNode(v[i]);
			st.push(temp->right);
		}
		else{
			st.top()->left = new TreeNode(v[i]);
			st.push(st.top()->left);
		}
	}
	return root;
}

int main(){
	vector<int>v = {10,5,1,7,40,50};
	TreeNode * root = preorderToBst(v);
	inorder(root);
	return 0;
}

