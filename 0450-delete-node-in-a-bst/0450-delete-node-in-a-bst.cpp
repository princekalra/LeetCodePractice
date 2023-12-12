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
    TreeNode* deleteNode(TreeNode* &root){
        if(root->left == NULL && root->right==NULL){
            root = NULL;
            return root;
        }
        if(root->left!=NULL){
            TreeNode* curr = root->left;
            while(curr->right!=NULL){
                curr = curr->right;
            }
            swap(curr->val,root->val);
            root->left = inorder(root->left,curr->val);
        }
        else {
            TreeNode* curr = root->right;
            while(curr->left!=NULL){
                curr = curr->left;
            }
            swap(curr->val, root->val);
            root->right = inorder(root->right,curr->val);
        }
        return root;
    }
    TreeNode* inorder(TreeNode* &root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val == key){
           return deleteNode(root);
        }
        if(key>root->val){
            root->right =  inorder(root->right,key);
        }
        else{
            root->left =  inorder(root->left, key);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* sol = inorder(root,key);
        return sol;
    }
};