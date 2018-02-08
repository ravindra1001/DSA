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

int cntInRange(TreeNode * root,int start,int end, int &ans){
	if(root==NULL) return 1;
	int temp1 = cntInRange(root->left,start,end,ans);
	int temp2 = cntInRange(root->right,start,end,ans);
	if(temp1 && temp2 && root->val>start && root->val<end){
		ans++;
		return 1;
	}
	return 0;
}

int main(){
	vector<int>v= {10,5,1,50,40,100};
	TreeNode * root = NULL;
	for(int i=0;i<v.size();i++){
		root = insert(root,v[i]);
	}
	int ans = 0;
	cntInRange(root,5,45,ans);
	cout<<ans<<endl;
	return 0;
}

