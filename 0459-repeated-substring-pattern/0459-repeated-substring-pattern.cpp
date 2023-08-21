class Solution {
public:
    bool helper(string &s, string &str) {
        int len = str.length();
        int i=0;
        for(i=0;i<s.length();i++){
            if(s[i]!=str[i%len]) {
                return false;
            }
        }
        cout<<len<<endl;
        if(i%len==0){
            return true;
        }
        return false;
    }
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        string str = "";
        for(int i=0;i<(len/2);i++) {
            str.push_back(s[i]);
          if(helper(s,str)){
              return true;
          }
        }
        return false;
    }
};