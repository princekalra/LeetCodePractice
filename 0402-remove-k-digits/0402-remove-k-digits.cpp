class Solution {
public:
    string removeKdigits(string num, int k) {
      stack<char>st;
        for(auto c: num){
            while(st.empty()==false && st.top()>c && k){
                st.pop();
                k--;
            }
            if(st.empty() && c=='0'){
                
            }
            else{
                st.push(c);
            }
        }
        while(st.empty()==false && k!=0){
            k--;
            st.pop();
        }
        
        string sol = "";
        if(st.empty()){
            sol = "0";
        }
        while(st.empty()==false){
            sol.push_back(st.top());
            st.pop();
        }
        reverse(sol.begin(),sol.end());
        return sol;
        
    }
    
};