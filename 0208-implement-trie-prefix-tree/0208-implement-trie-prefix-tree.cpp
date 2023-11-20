struct Node {
    bool flag= false;
    Node* links[26];
    Node* get(char c){
        return links[c-'a'];
    }
    void put(char c){
        links[c-'a'] = new Node();
    }
    void setEnd() {
        flag = true;
    }
    bool getEnd() {
        return flag;
    }
    bool contains(char c) {
        return links[c-'a']!=NULL;
    }
};
class Trie {
    private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int len = word.length();
        Node *node = root;
        for(int i=0;i<len;i++) {
            if(!node->contains(word[i])){
                                node->put(word[i]);
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        int len = word.length();
        Node* node = root;
        for(int i=0;i<len;i++) {
            if(node->contains(word[i])){
                node = node->get(word[i]);
                
            }
            else{
                return false;
            }
        }
        return node->getEnd();
    }
    
    bool startsWith(string prefix) {
         int len = prefix.length();
        Node* node = root;
        for(int i=0;i<len;i++) {
            if(node->contains(prefix[i])){
                node = node->get(prefix[i]);
                
            }
            else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */