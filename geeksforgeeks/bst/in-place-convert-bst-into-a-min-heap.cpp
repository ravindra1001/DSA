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
	vector<int>v={8,4,12,2,6,10,14};
	int n = v.size();
	TreeNode * root = NULL;
	for(int i=0;i<n;i++){
		root = insert(root,v[i]);
	}
	//inorder(root);

	stack<TreeNode *>st;
	queue<TreeNode *>q;

	TreeNode * temp = root;

	while(temp!=NULL) {
		st.push(temp);
		temp = temp->left;
	}

	q.push(st.top());
	st.pop();
	TreeNode * current = NULL;

	TreeNode * ans = q.front();

	while(!q.empty()){
		current = q.front();q.pop();
		current->left = NULL;
		current->right = NULL;

		TreeNode * temp1 = NULL;
		if(!st.empty()){
			temp1 = st.top();st.pop();
			q.push(temp1);
			current->left = temp1;
			temp1 = temp1->right;
		}
		while(temp1){
			st.push(temp1);
			temp1 = temp1->left;
		}

		TreeNode * temp2 = NULL;
		if(!st.empty()){
			temp2 = st.top();st.pop();
			q.push(temp2);
			current->right = temp2;
			temp2 = temp2->right;
		}
		while(temp2){
			st.push(temp2);
			temp2 = temp2->left;
		}
	}
	inorder(ans);
	return 0;
}

