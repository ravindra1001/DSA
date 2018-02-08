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
	inorder(root->right);
	cout<<root->val<<" ";
}

void printCommonNode(TreeNode * root1, TreeNode * root2){
	stack<TreeNode * >st1;
	stack<TreeNode * >st2;
	while(root1){
		st1.push(root1);
		root1 = root1->left;
	}

	while(root2){
		st2.push(root2);
		root2 = root2->left;
	}

	while(!st1.empty() && !st2.empty()){
		TreeNode * temp1 = st1.top();
		TreeNode * temp2 = st2.top();
		bool flag1 = false;
		bool flag2 = false;

		if(temp1->val==temp2->val){
			cout<<temp1->val<<" ";
			st1.pop();st2.pop();
			flag1 = true;
			flag2 = true;
		}
		else if(temp1->val<temp2->val){
			st1.pop();
			flag1 = true;
		}
		else{
			st2.pop();
			flag2 = true;
		}
		if(flag1==true){
			temp1 = temp1->right;
			while(temp1){
				st1.push(temp1);
				temp1 = temp1->left;
			}
		}
		if(flag2==true){
			temp2 = temp2->right;
			while(temp2){
				st2.push(temp2);
				temp2 = temp2->left;
			}
		}
	}
	cout<<endl;
}

int main(){
	vector<int>v1 = {5,1,0,4,10,7,9};
	vector<int>v2 = {10,7,4,9,20};

	TreeNode * root1 = NULL;
	TreeNode * root2 = NULL;

	for(int i=0;i<v1.size();i++){
		root1 = insert(root1,v1[i]);
	}
	for(int i=0;i<v2.size();i++){
		root2 = insert(root2,v2[i]);
	}

	printCommonNode(root1,root2);
	return 0;
}

