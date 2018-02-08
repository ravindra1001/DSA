#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
	TreeNode * left;
	TreeNode * right;
	int val;
	//TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int key){
		this->val = key;
		this->left = NULL;
		this->right = NULL;
	}
};
TreeNode * insert(TreeNode * root, int key, int & pre){
	if(root==NULL){
		root = new TreeNode(key);
	}
	else if(key<root->val) {
		pre = root->val;
		root->left = insert(root->left,key,pre);
	}
	else root->right = insert(root->right,key,pre);

	return root;
}

void inorder(TreeNode * root){
	if(root==NULL) return;
	inorder(root->left);
	inorder(root->right);
	cout<<root->val<<" ";
}

int main(){
	vector<int>v = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    int n = v.size();
    int pre = -1;
    TreeNode * root = NULL;
    for(int i=n-1;i>=0;i--){
    	pre = -1;
    	root = insert(root,v[i],pre);
    	v[i] = pre;
    }
    //inorder(root);
    for(int i=0;i<n;i++){
    	cout<<v[i]<<" ";
    }
    cout<<endl;
	return 0;
}
