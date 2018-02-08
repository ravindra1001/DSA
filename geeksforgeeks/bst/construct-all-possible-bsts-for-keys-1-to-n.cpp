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

void preorder(TreeNode * root){
	if(root==NULL) return;
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}

vector<TreeNode *> constructTrees(int start,int end){
	vector<TreeNode *>list;
	if(start>end){
		list.push_back(NULL);
		return list;
	}

	for(int i=start;i<=end;i++){
		vector<TreeNode *> leftSubtree = constructTrees(start,i-1);
		vector<TreeNode *> rightSubtree = constructTrees(i+1,end);

		for(int j=0;j<leftSubtree.size();j++){
			for(int k=0;k<rightSubtree.size();k++){
				TreeNode * temp = new TreeNode(i);
				temp->left = leftSubtree[j];
				temp->right = rightSubtree[k];
				list.push_back(temp);
			}
		}
	}
	return list;
}

int main(){
	vector<TreeNode * >v = constructTrees(1,3);
	for(int i=0;i<v.size();i++){
		preorder(v[i]);
		cout<<endl;
	}
	return 0;
}

