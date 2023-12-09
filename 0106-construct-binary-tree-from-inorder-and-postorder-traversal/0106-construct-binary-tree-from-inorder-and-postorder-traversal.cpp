/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* buildBinaryTree(vector<int>&postorder, int &index, int start, int end, unordered_map<int,int>&mp)		{
	if(start>end){
		return NULL;
	}
	if(index<0){
		return NULL;
	}
	TreeNode* root = new TreeNode(postorder[index]);
	index--;
	root->right = buildBinaryTree(postorder, index, mp[root->val]+1,end,mp);
	root->left = buildBinaryTree(postorder, index, start, mp[root->val]-1,mp);
	return root;
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size()-1;
        unordered_map<int,int>mp;
	for(int i=0;i<inorder.size();i++)		{
		mp[inorder[i]] = i;
	}
	int len = postorder.size();
	TreeNode* root = buildBinaryTree(postorder,index,0,len-1,mp);
	return root;
    }
};

