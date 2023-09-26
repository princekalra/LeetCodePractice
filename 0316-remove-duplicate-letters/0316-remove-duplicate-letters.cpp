class Solution {
public:
    string removeDuplicateLetters(string s) {
        string sol = "";
        stack<char>st;
        vector<int>freq(26,0);
        vector<int>ins(26,0);
        for(auto c: s){
            freq[c-'a']+=1;
        }
        for(auto c: s) {
             freq[c-'a']--;
            if(ins[c-'a']>0){
                continue;
            }
                while(st.empty()==false && st.top()>=c && freq[st.top()-'a']>0){
                    ins[st.top()-'a']=0;
                    st.pop();
                    
                }
                
                 st.push(c);
                    ins[c-'a']=1;
             
    
        }
        while(st.empty()==false){
            sol =  st.top()+sol;
            st.pop();
        }
        return sol;
    }
};