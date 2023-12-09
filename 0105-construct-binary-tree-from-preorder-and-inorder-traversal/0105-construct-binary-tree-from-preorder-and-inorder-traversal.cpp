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
TreeNode* buildBinaryTree(vector<int>&preorder, int& index,int start, int end, unordered_map<int,int>&mp)	{
	if(start>end){
		return NULL;
	}
	if(index>=preorder.size()){
		return NULL;
	}
	TreeNode* root = new TreeNode(preorder[index]);
		index++;
		root->left = buildBinaryTree(preorder,index,start,mp[root->val]-1,mp);
		root->right = buildBinaryTree(preorder,index,mp[root->val]+1,end,mp);
		return root;
	}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
	for(int i=0;i<inorder.size();i++)		{
		mp[inorder[i]] = i;
	}
	int index = 0;
	TreeNode* root =buildBinaryTree(preorder,index,0,preorder.size()-1,mp);
	return root;
    }
};
