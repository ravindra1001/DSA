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

void inorderPreSuc(TreeNode * root, TreeNode * &pre, TreeNode * &suc, int key, bool &flag){
	if(root==NULL) return;
	if(key<root->val){
		suc = root;
		inorderPreSuc(root->left,pre,suc,key,flag);
	}
	else if(key>root->val){
		pre = root;
		inorderPreSuc(root->right,pre,suc,key,flag);
	}
	else{
		flag = true;
		if(root->right!=NULL){
			TreeNode * temp = root->right;
			while(temp){
				suc = temp;
				temp = temp->left;
			}
		}

		if(root->left!=NULL){
			TreeNode * temp = root->left;
			while(temp){
				pre = temp;
				temp = temp->right;
			}
		}
	}
}

int main(){
	vector<int>v = {10,6,4,8,7,9,20,15,25};
	TreeNode * root = NULL;
	for(int i=0;i<v.size();i++){
		root = insert(root,v[i]);
	}
	TreeNode * pre = NULL;
	TreeNode * suc = NULL;
	bool flag = false;

	int key = 5;
	inorderPreSuc(root,pre,suc,key,flag);
	cout<<flag<<endl;
	if(pre != NULL)cout<<pre->val<<endl;
	else cout<<"-00"<<endl;
	if(suc != NULL)cout<<suc->val<<endl;
	else cout<<"00"<<endl;

	return 0;
}

