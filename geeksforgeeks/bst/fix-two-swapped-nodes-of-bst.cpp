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

void correctBst(TreeNode * root, TreeNode * &first, TreeNode * &middle, TreeNode * &last, TreeNode *&pre){
	if(root==NULL) return;
	correctBst(root->left,first,middle,last,pre);
	if(pre){
		if(pre->val>root->val){
			if(!first){
				first=pre;
				middle = root;
			}
			else{
				last = root;
			}
		}
	}
	pre = root;
	correctBst(root->right,first,middle,last,pre);
}

void inorder(TreeNode * root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}


int main(){
	TreeNode * root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(20);
	root->right = new TreeNode(8);
	inorder(root);cout<<endl;
	TreeNode * first=NULL, *middle=NULL,*last,*pre=NULL;
	correctBst(root,first,middle,last,pre);
	if(first&&last) {
		int temp = first->val;
		first->val = last->val;
		last->val = temp;
	}
	else if(first&&middle){
		int temp = first->val;
		first->val = middle->val;
		middle->val = temp;
	} //swap(first->val,middle->val);
//swap(first->val,last->val);
	inorder(root);cout<<endl;
	return 0;
}
