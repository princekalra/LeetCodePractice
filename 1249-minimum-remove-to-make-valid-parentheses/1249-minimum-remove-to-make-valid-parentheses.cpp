class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string sol = "";
        stack<char>st;
        for(auto c:s){
            if(c=='('){
                sol+=c;
                st.push('(');
            }
            else if(c==')'){
                if(st.empty()==false && st.top()=='('){
                    sol+=c;
                    st.pop();
                }
            }
            else{
                sol+=c;
            }
        }
        int cnt = st.size();
        if(cnt>0)
        {
            for(int i=sol.length()-1;i>=0;i--){
                if(sol[i]=='('){
                    sol = sol.substr(0,i) + sol.substr(i+1);
                    cnt--;
                    if(cnt==0){
                        break;
                    }
                }
            }
        }
        return sol;
    }
};