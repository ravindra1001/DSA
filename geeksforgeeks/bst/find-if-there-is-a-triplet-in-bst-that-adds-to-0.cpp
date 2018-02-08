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


void bstToDll(TreeNode * root, TreeNode * &head, TreeNode * &tail){
	if(root==NULL) return;
	if(root->left)
		bstToDll(root->left,head,tail);

	root->left = tail;
	if(tail) tail->right = root;
	else head = root;

	tail = root;
	if(root->right)
		bstToDll(root->right,head,tail);
}

bool threeSumZero(TreeNode * root){
	if(root==NULL) return false;
	TreeNode * head = NULL;
	TreeNode * tail = NULL;

	bstToDll(root,head,tail);
	TreeNode * i = head;
	while(i->right != NULL && i->right->right!=NULL){
		TreeNode * j = i->right;
		TreeNode * k = tail;
		int target = -1*i->val;
		while(j!=k){
			if(j->val+k->val==target) return true;
			else if(j->val+k->val < target) j = j->right;
			else k = k->left;
		}
		i = i->right;
	}
	return false;
}




int main(){
	vector<int>v ={-5,-1,2,6};
	TreeNode * root = NULL;
	for(int i=0;i<v.size();i++){
		root = insert(root,v[i]);
	}
	cout<<threeSumZero(root)<<endl;
	return 0;
}

