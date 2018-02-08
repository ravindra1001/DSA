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
bool pairSum(TreeNode * root, int target){
	if(root==NULL) return 0;
	stack<TreeNode *>st1;
	stack<TreeNode *>st2;

	TreeNode * temp = root;
	while(temp){
		st1.push(temp);
		temp = temp->left;
	}
	temp = root;
	while(temp){
		st2.push(temp);
		temp = temp->right;
	}

	while(!st1.empty() && !st2.empty()){
		int temp1 = st1.top()->val;
		int temp2 = st2.top()->val;

		if(temp1+temp2==target && temp1!=temp2) return true;
		else if(temp1+temp2<target){
			TreeNode * temp = st1.top()->right;
			st1.pop();
			while(temp){
				st1.push(temp);
				temp = temp->left;
			}
		}

		else{
			TreeNode * temp = st2.top()->left;
			st2.pop();
			while(temp){
				st2.push(temp);
				temp = temp->right;
			}
		}
	}
	return false;
}


int main(){
	vector<int>v ={15,10,20,8,12,16,25};
	TreeNode * root = NULL;
	for(int i=0;i<v.size();i++){
		root = insert(root,v[i]);
	}
	cout<<pairSum(root,19)<<endl;
	return 0;
}

