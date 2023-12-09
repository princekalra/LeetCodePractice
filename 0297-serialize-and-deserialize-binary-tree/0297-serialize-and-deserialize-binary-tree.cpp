/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "";
        }
     string str = "";
	queue<TreeNode*>q;
	q.push(root);
	while(q.empty() == false)	{
		TreeNode* node = q.front();
		q.pop();
		if(node == NULL){
		str.append("#,");
		}
		else{
	
		str.append(to_string(node->val) + ",");
		q.push(node->left);
		q.push(node->right);
	
		    }
	}
	return str;
	}

    // Decodes your encoded data to tree.
 
    TreeNode* deserialize(string data) {
        if(data==""){
            return NULL;
        }
      stringstream s(data);
	string str = "";
	getline(s,str,',');
	TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*>q;
	q.push(root);
	while(q.empty()==false) {
		TreeNode* node = q.front();
		q.pop();
		getline(s,str,',');
		
		if(str!="#"){
			TreeNode* newLeftNode = new TreeNode(stoi(str));
			node->left = newLeftNode;
			q.push(newLeftNode);
		}
		getline(s,str,',');
		if(str!="#"){
			TreeNode* newRightNode = new TreeNode(stoi(str));
			node->right = newRightNode;
			q.push(newRightNode);
		}
	}
	return root;
		
    }
};




// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));