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
    TreeNode* getBstFromPreorder(vector<int>&preorder,int &index,TreeNode* left,TreeNode*right){
        if(index>=preorder.size()){
            return NULL;
        }
        if(preorder[index]<=(left==NULL?INT_MIN:left->val)||preorder[index]>=(right==NULL?INT_MAX:right->val)) {
                return NULL;
        }
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        root->left = getBstFromPreorder(preorder,index,left,root);
        root->right = getBstFromPreorder(preorder,index,root,right);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        TreeNode* root = getBstFromPreorder(preorder,index,NULL,NULL);
        return root;
    }
};