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

struct ListNode{
	int val;
	ListNode * next;
	ListNode(int key){
		this->val = key;
		this->next = NULL;
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

int listLength(ListNode * head){
	int cnt = 0;
	while(head){
		head = head->next;
		cnt++;
	}
	return cnt;
}

TreeNode * listToBst(ListNode * &head,int len){
	if(len<=0) return NULL;
	TreeNode * left = listToBst(head,len/2);
	TreeNode * root = new TreeNode(head->val);
	root->left = left;
	head = head->next;
	root->right = listToBst(head,len-len/2-1);
	return root;
}

int main(){

	return 0;
}

