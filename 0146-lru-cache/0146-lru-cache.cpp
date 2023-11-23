class node {
    public:
    int value;
    int key;
    node* next;
    node* prev;
    node(int _key,int _val) {
        key = _key;
        value = _val;
    }
};
class LRUCache {
public:
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*>mp;
    LRUCache(int max) {
        cap = max;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node *nde) {
        node* temp = head->next;
        head->next = nde;
        nde->prev = head;
        nde->next = temp;
        temp->prev = nde;
    }
    
    void deleteNode(node *nde) {
       node *ndeprev = nde->prev;
        node *ndenext = nde->next;
        ndeprev->next = ndenext;
        ndenext->prev = ndeprev;
    }
    
    void put(int key, int val) {
        if(mp.find(key)!=mp.end()) {
            node * nde = mp[key];
            mp.erase(key);
            deleteNode(nde);
        }
        if(mp.size() == cap) {
           node *nde = tail->prev;
           mp.erase(nde->key);
           deleteNode(nde);
        }
        node* nde = new node(key,val);
        addNode(nde);
        mp[key] = nde;
        
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) {
            return -1;
        }
        node *nde = mp[key];
        deleteNode(nde);
        mp.erase(key);
        addNode(nde);
        mp[key] = head->next;
        return nde->value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */