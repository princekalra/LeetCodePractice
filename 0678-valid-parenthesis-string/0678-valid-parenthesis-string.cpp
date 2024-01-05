class Solution {
public:
    bool checkValidString(string s) {
        stack<int>st1;
        stack<int>st2;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st1.push(i);
            }
            else if(s[i]==')'){
                if(!st1.empty()){
                    st1.pop();
                }
                else if(st2.empty()==false){
                    st2.pop();
                }
                else{
                    return false;
                }
            }
            else{
                st2.push(i);
            }
        }
        while(st1.empty()==false){
            if(st2.empty()){
                return false;
            }
            if(st1.top()<st2.top()){
                st1.pop();
                st2.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }
};