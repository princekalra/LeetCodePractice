class Solution {
public:
    struct Node {
        Node* links[2];
        bool contains(int bit){
            return (links[bit]!=NULL);
        }
        void insert(int bit) {
            links[bit] = new Node();
        }
        Node* get(int bit) {
            return links[bit];
        }
    };
    class Trie {
        private:
        Node* root;
        
        public:
        Trie()
        {
        root = new Node();
        }
        void insert(int num) {
            Node* node = root;
            for(int i = 31;i>=0;i-- ){
                int bit = (num>>i & 1);
                if(!node->contains(bit)) {
                    node->insert(bit);
                }
                node = node->get(bit);
            }
        }
        int findMax(int num) {
            Node* node = root;
            int val = 0;
            for(int i=31;i>=0;i--) {
                int bit = (num>>i&(1));
                if(node->contains(!bit)) {
                    node = node->get(!bit);
                    val = val|(1<<i);
                }
                else{
                    node = node->get(bit);
                }
            }
            return val;
        }
        
    };
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector< pair<int,pair<int,int>> >vec;
        int index = 0;
        sort(nums.begin(),nums.end());
        for(auto x: queries) {
            vec.push_back({x[1],{x[0],index++}});
        }
        int n = nums.size();
        sort(vec.begin(), vec.end());
        vector<int>sol(queries.size(),-1);
        Trie trie;
        int i=0;
        for(auto y: vec) {
        while(i<n && nums[i]<=y.first){
            trie.insert(nums[i]);
            i++;
        }
            if(i!=0){
                int max = trie.findMax(y.second.first);
                sol[y.second.second] = max;
            }
           
        }
        return sol;
    }
};