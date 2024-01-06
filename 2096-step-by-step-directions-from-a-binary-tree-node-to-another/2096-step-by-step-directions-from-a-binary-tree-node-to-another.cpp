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
	unordered_map<int, TreeNode*>mp;
	unordered_set<int>visited;
	TreeNode* DFS(TreeNode* root, int &value,TreeNode* parent)	{
		if(root==NULL){
			return NULL;
		}
       
		mp[root->val] = parent;
		TreeNode* left = DFS(root->left,value,root);
		TreeNode* right = DFS(root->right, value, root);
        if(root->val == value){
            return root;
        }
		if(left!=NULL){
			return left;
		}
		return right;
	}
	
		






 bool find_path(TreeNode* root, int &des, string &sol, string& path){
if(root==NULL){
return false;
}
if(visited.find(root->val)!=visited.end()){
	return false;
}
if(root->val == des){
	sol = path;
	return true;
}
visited.insert(root->val);
     path.push_back('L');
     bool res = false;
res = find_path(root->left ,des,sol,path);
     path.pop_back();
     if(res){
         return res;
     }
     path.push_back('R');
res = find_path(root->right,des,sol,path);
     path.pop_back();
     if(res){
         return res;
     }
     path.push_back('U');
res = find_path(mp[root->val],des,sol,path);
     path.pop_back();
     return res;
}
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* startNode = DFS(root,startValue,NULL);
       
	string sol = "";
        string path = "";
	
	find_path(startNode, destValue,sol,path);
	return sol;
    }
};
