class Solution {
public:
    struct node{
        int freq;
        node* arr[26];
        bool contains(char c){
            return arr[c-'a']!=NULL;
        }
        void increaseFreq(){
            freq++;
        }
        int getFreq(){
            return freq;
        }
        void put(char c){
            arr[c-'a'] = new node();
        }
        node* next(char c){
            return arr[c-'a'];
        }
    };
    struct trie{
        node *root;
        trie(){
            root = new node();
        }
        public:
        void insert(string str){
            node* r = root;
            for(auto c:str){
                if(!r->contains(c)){
                    r->put(c);
                }
                r = r->next(c);
                r->increaseFreq();
            }
        }
        string getLongestPrefix(string str,int size){
            node* r = root;
            string sol = "";
            for(auto c: str){
                if(r->contains(c)){
                    // cout<<"2";
                     r = r->next(c);
                    // cout<<r->getFreq();
                if(r->getFreq() == size){
                    sol.push_back(c);
                }
                else{
                    break;
                }
                }
                else{
                    break;
                }
               
            }
            return sol;
        }
    };
    string longestCommonPrefix(vector<string>& strs) {
        trie t;
        int size = strs.size();
        for(int i=0;i<size;i++){
            t.insert(strs[i]);
        }
        string sol = t.getLongestPrefix(strs[0],size);
        return sol;
    }
};