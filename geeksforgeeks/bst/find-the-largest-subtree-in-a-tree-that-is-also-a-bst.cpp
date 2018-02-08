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

// vector<int> largestBst(TreeNode * root){
// 	vector<int>v;
// 	if(root==NULL){
// 		v={1,INT_MIN,INT_MAX,0};
// 		return v;
// 	}
// 	vector<int>v1 = largestBst(root->left);
// 	vector<int>v2 = largestBst(root->right);

// 	if(v1[0]==1 && v2[0]==1 && root->val > v1[1] && root->val<v2[2]){
// 		v={1,v1[0],v2[2],v1[3]+v2[3]+1};
// 		return v;
// 	}
// 	else{
// 		v = {0,-1,-1,max(v1[3],v2[3])};
// 	}
// }

int largetstBSTUtil(TreeNode * root, int &minref, int &maxref, int &maxsizeref,bool &isbstref){
	if(root == NULL){
		isbstref = 1;
		return 0;
	}

	int min = INT_MAX;

	bool leftflag = false;
	bool rightflag = false;

	int ls,rs;

	maxref = INT_MIN;
	ls = largetstBSTUtil(root->left,maxref,maxsizeref,isbstref);
	if(isbstref && root->val < maxref)
		leftflag = true;

	min = minref;
	minref = INT_MAX;

	rs = largetstBSTUtil(root->right,minref,maxref,maxsizeref,isbstref);
	if(isbstref && root->val < minref)
		rightflag = true;

	if(min < minref) minref = min;
	if(root->val < minref) minref = root->val;
	if(root->val > maxref) maxref = root->val;

	if(leftflag && rightflag){
		if(ls+rs+1>maxsizeref)maxsizeref = ls+rs+1;
		return ls+rs+1;
	}
	else{
		isbstref = 0;
		return 0;
	}
}

int  largetstBST(TreeNode * root){
	int min = INT_MAX;
	int max = INT_MIN;

	int maxSize = 0;
	int isBst = 0;

	largetstBSTUtil(root,min,max,maxSize,isBst);
	return maxSize;
}




int main(){
	TreeNode * root = new TreeNode(5);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right = new TreeNode(4);

	cout<<largestBst(root)[3]<<endl;
	return 0;
}

