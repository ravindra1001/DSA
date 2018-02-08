#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int temp){
		this->val = temp;
		this->left = NULL;
		this->right = NULL;		
	}
};

bool fun(TreeNode * root){
	if(root==NULL) return true;
	if(root->left!= NULL && root->right != NULL) return false;
	else return fun(root->left) && fun(root->right);	
}
int main(){
	TreeNode * root = new TreeNode(5);
	root->left = new TreeNode(3);
	// root->right = new  TreeNode(8);
	cout<<fun(root)<<endl;
	return 0;
}