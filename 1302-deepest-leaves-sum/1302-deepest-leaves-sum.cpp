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
    int deepestLeavesSum(TreeNode* root) {
	if(root==NULL){
		return 0;
	}
        int sum_of_deepest_leaves = 0;
         queue<TreeNode*>q;
	q.push(root);
	while(q.empty()==false) {
		int size = q.size();
		int sum_of_current_level = 0;
		for(int i=0;i<size;i++){
			TreeNode* node = q.front();
			q.pop();
			sum_of_current_level+=node->val;
			if(node->left!=NULL){
				q.push(node->left);
			}
			if(node->right!=NULL){
				q.push(node->right);
			}
		}
		sum_of_deepest_leaves = sum_of_current_level;
	}
	return sum_of_deepest_leaves;	
    }
};
