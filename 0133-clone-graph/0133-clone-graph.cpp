/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*>mp;
    Node* sol;
    void doCopy(Node* node, Node* copy) {
        for(auto x:node->neighbors) {
            if(mp.find(x->val)==mp.end()) {
                Node* newnode = new Node(x->val);
                mp[x->val] = newnode;
                copy->neighbors.push_back(newnode);
                doCopy(x,newnode);
            }
            else
            {
                copy->neighbors.push_back(mp[x->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) {
            return NULL;
        }
        sol = new Node(node->val);
        mp[node->val] = sol;
        doCopy(node, sol);
        return sol;
    }
};