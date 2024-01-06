class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        string str="";
        for(auto c:num){
            while(st.empty()==false && (st.top())>c && k){
                st.pop();
                k--;
            }
           st.push(c);
        }
        while(st.empty()==false){
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(),str.end());
        if(k!=0){
            str = str.substr(0,str.length()-k);
        }
        int index= 0;
        while(index<str.length() && str[index]=='0'){
            index++;
        }
        str = str.substr(index);
        if(str==""){
            str="0";
        }
        return str;
    }
};