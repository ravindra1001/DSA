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

int main(){
	vector<int>v = {20, 10, 5, 13, 12};
	int pre = v[0];
	int start = INT_MIN;
	int end = INT_MAX;
	bool flag  = false;
	for(int i=1;i<v.size();i++){
		if(i==1){
			if(v[i]>v[0]){
				start = v[0];
				end = v[i];
				pre = v[i];
			}
			else{
				end = v[0];
				start = v[i];
				pre = v[i];
			}
		}
		else{
			if(v[i]>start && v[i]<end){
				if(pre<v[i]){
					start = pre;
				}
				else{
					end = pre;
										}
				pre = v[i];
			}
			else{
				flag = true;
				cout<<"invalid"<<endl;
			}
		}
	}
	if(!flag)
		cout<<"valid"<<endl;
	return 0;
}

