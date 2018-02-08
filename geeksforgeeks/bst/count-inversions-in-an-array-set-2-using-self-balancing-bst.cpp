#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
	int key;
	int height;
	TreeNode * left,*right;
	int size;
	TreeNode(int key){
		this->key = key;
		this->left=NULL;
		this->right = NULL;
		this->height = 1;
		this->size = 1;
	}
};
int height(TreeNode * root){
	if(root==NULL) return 0;
	return root->height;
}
int size(TreeNode * root){
	if(root==NULL) return 0;
	return root->size;
}
int getBlance(TreeNode * root){
	if(root==NULL)return 0;
	return height(root->left)-height(root->right);
}

TreeNode * rightRotate(TreeNode * root){
	TreeNode * A = root;
	TreeNode * B = A->left;
	TreeNode * T2 = B->right;
	//rotation
	B->right = A;
	A->left = T2;
	//heights
	A->height = max(height(A->left),height(A->right))+1;
	B->height = max(height(B->left),height(B->right))+1;
	//size
	A->size = size(A->left)+size(A->right)+1;
	B->size = size(B->left)+size(B->right)+1;

	return B;
}

TreeNode * leftRotate(TreeNode * root){
	TreeNode * A = root;
	TreeNode * C = A->right;
	TreeNode * T3 = C->left;

	C->left = A;
	A->right = T3;

	A->height = max(height(A->left),height(A->right))+1;
	C->height = max(height(C->left),height(C->right))+1;

	A->size = size(A->left)+size(A->right)+1;
	C->size = size(C->left)+size(C->right)+1;

	return C;
}

TreeNode * insert(TreeNode * root, int key, int &result){
	if(root==NULL) return new TreeNode(key);
	if(key<root->key){
		root->left = insert(root->left,key,result);
		result+=(size(root->right)+1);
	}
	else{
		root->right = insert(root->right,key,result);
	}

	root->height = max(height(root->left),height(root->right))+1;
	root->size = size(root->left)+size(root->right)+1;

	int balance = getBlance(root);

	if(balance>1 && key<root->left->key)
		return rightRotate(root);
	if(balance<-1 && key>root->right->key)
		return leftRotate(root);
	if(balance>1 && key>root->left->key){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if(balance<-1 && key<root->right->key){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

int getInversion(vector<int>&v){
	int n = v.size();
	int result = 0;
	TreeNode * root = NULL;
	for(int i=0;i<n;i++){
		root = insert(root,v[i],result);
	}
	return result;
}
int main(){
	vector<int>v= {8,4,2,1};
	cout<<getInversion(v)<<endl;
	return 0;
}