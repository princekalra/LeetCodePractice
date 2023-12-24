class Solution {
public:
	int isBalancedTree(TreeNode* root){
		if(root==NULL){
			return 0;
		}
		int left_height = isBalancedTree(root->left);
		int right_height = isBalancedTree(root->right);
		if(left_height==-1||right_height==-1){
			return -1;
		}
		int diff = abs(left_height-right_height);
		if(diff>1){
			return -1;
		}
		return 1+ max(left_height,right_height);
	}
    bool isBalanced(TreeNode* root) {
      int isBalanced = isBalancedTree(root);
	if(isBalanced!=-1){
		return true;
	}
	return false;
    }
};
