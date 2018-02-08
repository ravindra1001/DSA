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

void merge(TreeNode * root1, TreeNode * root2){
	if(root1==NULL && root2==NULL) return;
	stack<TreeNode *>st1;
	stack<TreeNode *>st2;

	TreeNode * temp = root1;
	while(temp){
		st1.push(temp);
		temp = temp->left;
	}
	temp = root2;
	while(temp){
		st2.push(temp);
		temp = temp->left;
	}

	while(!st1.empty() && !st2.empty()){
		TreeNode  * temp1 = st1.top();
		TreeNode  * temp2 = st2.top();

		if(temp1->val<temp2->val){
			cout<<temp1->val<<" ";

			st1.pop();
			temp1 = temp1->right;
			while(temp1){
				st1.push(temp1);
				temp1 = temp1->left;
			}
		}
		else{
			cout<<temp2->val<<" ";
	
			st2.pop();
			temp2 = temp2->right;
			while(temp2){
				st2.push(temp2);
				temp2 = temp2->left;
			}
		}
	}

	while(!st1.empty()){
		TreeNode * temp1 = st1.top();st1.pop();
		cout<<temp1->val<<" ";
		temp1 = temp1->right;
		while(temp1){
			st1.push(temp1);
			temp1 = temp1->left;
		}
	}

	while(!st2.empty()){
		TreeNode * temp2 = st2.top();st2.pop();
		cout<<temp2->val<<" ";
		temp2 = temp2->right;
		while(temp2){
			st2.push(temp2);
			temp2 = temp2->left;
		}
	}

}


int main(){
	vector<int>v1 = {2,4,7,3};
	TreeNode * root1 = NULL;
	for(int i=0;i<v1.size();i++){
		root1 = insert(root1,v1[i]);
	}

	vector<int>v2 = {16,50,100,200};
	TreeNode * root2 = NULL;
	for(int i=0;i<v2.size();i++){
		root2 = insert(root2,v2[i]);
	}

	merge(root1,root2);

	cout<<endl;
	return 0;
}

