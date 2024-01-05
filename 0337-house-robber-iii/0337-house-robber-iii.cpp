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
    int robHelper(TreeNode* root,unordered_map<TreeNode*,int>&mp){
         if(root == NULL){
            return 0;
        }
        if(mp.count(root)){
            return mp[root];
        }
        int including_current_root = 0;
        int excluding_current_root = 0;
        including_current_root = root->val + (root->left!=NULL?(robHelper(root->left->right,mp) + robHelper(root->left->left,mp)):0) + (root->right!=NULL?(robHelper(root->right->left,mp) + robHelper(root->right->right,mp)):0);
        excluding_current_root = (robHelper(root->left,mp) + robHelper(root->right,mp));
        // cout<<root->val<<" "<<including_current_root<<" "<<excluding_current_root<<endl;
        return mp[root] =  max(including_current_root,excluding_current_root);
        
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>mp;
        int sol = robHelper(root,mp);
        return sol;
    }
};