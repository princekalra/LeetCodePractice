class Solution {
public:
	TreeNode* getBstToGst(TreeNode* root, int& sum){
		if(root==NULL){
			return NULL;
		}								
		root->right = getBstToGst(root->right,sum);
		sum+=root->val;
		root->val = sum;
		root->left = getBstToGst(root->left, sum);
		return root;
}
 
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
       TreeNode* sol = getBstToGst(root,sum);
	return sol;
    }
};
