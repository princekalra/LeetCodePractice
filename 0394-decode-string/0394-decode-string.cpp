class Solution {
public:
    string get(string &str, int num){
        string newString = "";
        while(num!=0){
            num--;
            newString = newString+str;
        }
        return newString;
    }
    bool isdigit(char c){
        return c>='0' && c<='9';
    }
    string decodeString(string s) {
        stack<int>stack_for_num;
        stack<string>stack_for_char;
        string num = "";
        for(auto c:s){
            if(!isdigit(c)&&num!=""){
                stack_for_num.push(stoi(num));
                num = "";
            }
            if(c=='['){
                
                string ss = "";
                ss+=c;
                stack_for_char.push(ss);
                // cout<<stack_for_char.top()<<'$'<<endl;
            }
            else if(c==']'){
                string str = "";
                while(stack_for_char.empty()==false && stack_for_char.top()!="["){
                    str = stack_for_char.top() + str;
                    stack_for_char.pop();
                }
                if(stack_for_char.empty()==false && stack_for_char.top()=="["){
                    stack_for_char.pop();
                }
                
                int num =1;
                if(stack_for_num.empty()==false){
                     num = stack_for_num.top();
                stack_for_num.pop();
                }
                string newString = get(str,num);
                stack_for_char.push(newString);
            }
            else if(isdigit(c)){
                num+=c;
            }
            else{
                string ss = "";
                ss+=c;
                stack_for_char.push(ss);
                                // cout<<stack_for_char.top()<<'$'<<endl;

            }
        }
        string sol = "";
        while(stack_for_char.empty()==false){
            sol = stack_for_char.top()+sol;
            stack_for_char.pop();
        }
return sol;        
    }
};