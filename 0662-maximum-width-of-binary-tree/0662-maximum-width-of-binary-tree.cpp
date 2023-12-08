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
    int widthOfBinaryTree(TreeNode* root) {
	queue<pair<TreeNode*,int>>q;
	q.push({root,0});
	int sol = 0;
	int li = INT_MAX;
	int r = INT_MIN;
        int sub=0;
	while(q.empty()==false){
		int size =q.size();
		while(size--){
		TreeNode* node = q.front().first;
		int prev = q.front().second;
		q.pop();
		if(node->left){
		q.push({node->left,(2*prev+1-sub)});
		}
		if(node->right) {
		q.push({node->right,(2*prev+2-sub)});
		}
		li = min(li,prev);
		r = max(r,prev);
		}
        sol = max(sol,(r-li+1));
        sub =r;
        
         li = INT_MAX;
	     r = INT_MIN;
		
	}
	
	return sol;
		
		
        
    }
};
