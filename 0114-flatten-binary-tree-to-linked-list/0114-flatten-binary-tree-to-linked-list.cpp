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
   TreeNode* flat(TreeNode* root){
       if(root==NULL){
           return root;
       }
       TreeNode* left = flat(root->left);
       TreeNode* right = flat(root->right);
       TreeNode* leftroot = root->left;
       TreeNode* rightroot = root->right;
       
       root->left = NULL;
       if(leftroot!=NULL){
             root->right = leftroot;
            left->right = rightroot;
       }
        if(right!=NULL){
            return right;
        }
       if(left!=NULL){
           return left;
       }
      return root;
   }
    void flatten(TreeNode* root) {
      if(root==NULL){
          return ;
      }
     flat(root);
    
    }
};