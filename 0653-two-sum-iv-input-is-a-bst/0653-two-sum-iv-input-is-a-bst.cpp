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
class BSTIterator {
    private:
    stack<TreeNode*>st;
    bool key;
    public:
    BSTIterator(TreeNode* root,bool k){
        key = k;
        if(key){
            pushLeft(root);
        }
        else {
            pushRight(root);
        }
    }
    void pushLeft(TreeNode* root){
        TreeNode* curr = root;
        while(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }
    }
    void pushRight(TreeNode* root){
        TreeNode* curr = root;
        while(curr!=NULL){
            st.push(curr);
            curr = curr->right;
        }
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        TreeNode* curr = st.top();
        return curr->val;
    }
    void pop(){
        TreeNode* curr = st.top();
        st.pop();
        if(key){
            pushLeft(curr->right);
        }
        else{
            pushRight(curr->left);
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator first(root,true);
        BSTIterator second(root,false);
        while(first.hasNext() && second.hasNext()){
            if(first.next()>=second.next()){
                return false;
            }
            if(first.next() + second.next()==k){
                return true;
            }
            if((first.next() + second.next())>k){
                second.pop();
            }
            else{
                first.pop();
            }
        }
        return false;
    }
};