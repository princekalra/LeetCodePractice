struct Node {
    Node* links[26];
    int cnt = 0;
    bool contains(char key) {
        return links[key-'a']!=NULL;
    }
    void put(char key) {
        links[key-'a'] = new Node();
    }
    void increaseCount() {
        cnt++;
    }
    int getCount() {
        return cnt;
    }
    Node* get(char c) {
        return links[c-'a'];
    }
};
class Trie {
    private:
    Node* root;
    
    public:
    Trie() {
        root = new Node();
    }
    void insert(string str) {
        Node* node = root;
     for(int i=0;i<str.length();i++) {
         if(!node->contains(str[i])) {
             node->put(str[i]);
         }
                 node = node->get(str[i]);

         node->increaseCount();
     }
    }
    string findSol(string str, int sz) {
        Node* node = root;
        string sol = "";
        for(int i=0;i<str.length();i++) {
           node = node->get(str[i]);
            if(node->getCount() == sz){
                sol.push_back(str[i]);
            }
            else{
                return sol;
            }
        }
        return sol;
    }
    
    
    
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for(auto str: strs) {
           trie.insert(str);
        }
        string sol = trie.findSol(strs[0], strs.size());
        return sol;
    }
};