class Solution {
public:
    // bool isValid(string &str){
    //     int cnt=0;
    //     for(int i=0;i<str.length();i++){
    //         if(str[i]=='('){
    //             cnt++;
    //         }
    //         else{
    //             if(cnt==0){
    //                 return false;
    //             }
    //             cnt--;
    //         }
    //     }
    //     return true;
    // }
    // void generateAll(string str, int n , vector<string>&sol,int index,unordered_set<string>&st){
    //     if(index == str.length()){
    //         if(st.count(str)==0&&isValid(str))
    //         {
    //             sol.push_back(str);
    //             st.insert(str);
    //         }
    //         return;
    //     }
    //     for(int i=index;i<str.length();i++){
    //         swap(str[i],str[index]);
    //         generateAll(str,n,sol,index+1,st);
    //         swap(str[i],str[index]);
    //     }
    // }
    void generateAll(string str,int cnt,int n,vector<string>&sol){
        if(str.length()==2*n && cnt==0){
            sol.push_back(str);
            return;
        }
        if(str.length()>(2*n)){
            return;
        }
        if(cnt>0){
            generateAll(str+"(",cnt+1,n,sol);
            generateAll(str+")",cnt-1,n,sol);
        }
        else{
            generateAll(str+"(",cnt+1,n,sol);
        }
    }
    vector<string> generateParenthesis(int n) {
      vector<string>sol;
        generateAll("",0,n,sol);
        return sol;
        
    }
};