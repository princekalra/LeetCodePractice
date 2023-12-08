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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         vector< vector<int> >sol;
        queue<pair<TreeNode*,pair<int,int > >>q;
	map<int,map<int,vector<int> >>mp;
        
	q.push({root,{0,0}});
	while(q.empty() == false) 	{
		int size = q.size();
		while(size--){
			TreeNode* node = q.front().first;
			int level = q.front().second.first;
			int index = q.front().second.second;
            q.pop();
			mp[index][level].push_back(node->val);
			if(node->left){
				q.push({node->left,{level+1,index-1}});
			}
			if(node->right){
				q.push({node->right,{level+1,index+1}});
			}
		}
	}
	for(auto x:mp) {
        vector<int>temp;
        for(auto y:x.second){
           vector<int>vec =  y.second;
            sort(vec.begin(),vec.end());
            for(auto z:vec){
                temp.push_back(z);
            }
        }
sol.push_back(temp);	
	}
	return sol;
    }
};
