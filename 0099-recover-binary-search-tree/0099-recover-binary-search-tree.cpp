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
private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
public:
    void inorder(TreeNode* &root, TreeNode *&prev,TreeNode *&first, TreeNode *&middle , TreeNode *&last) {
        if(root == NULL){
            return;
        }
        inorder(root->left,prev,first,middle,last);
        if(prev!=NULL){
            if(prev->val>root->val){
                if(middle!=NULL){
                    last = root;
                }
                else{
                    first = prev;
                    middle = root;
                }
            }
        }
        prev = root;
        inorder(root->right,prev,first,middle,last);
    }
    void recoverTree(TreeNode* root) {
        first = prev = middle = last = NULL;
        inorder(root,prev,first,middle,last);
        if(first!=NULL && last!=NULL) {
            swap(first->val,last->val);
        }
        else if(first!=NULL && middle!=NULL){
            swap(first->val, middle->val);
        }
    }
};