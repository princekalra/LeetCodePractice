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
 bool isValidBSTUtil(TreeNode* root, TreeNode* left, TreeNode*right)
{
	if(root==NULL){
		return true;
	}
	if(left!=NULL && root->val<=left->val){
		return false;
	}
	if(right!=NULL && root->val>=right->val){
		return false;
	}
	return isValidBSTUtil(root->left,left,root) && isValidBSTUtil(root->right, root, right);
}
    bool isValidBST(TreeNode* root) {
        return isValidBSTUtil(root,NULL,NULL);
    }
};
