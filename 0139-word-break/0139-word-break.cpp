class Solution {
public:
    unordered_map<string,bool>dp;
    bool helper(string &str, unordered_map<string,int>&mp, int index,string s) {
        if(index>=str.length()) {
            if(mp[s]==1) {
               return true;
            }
            return false;
        }
        string key = s+"-"+to_string(index);
        // cout<<key<<endl;
        bool ans = false;
        if(dp.find(key) != dp.end()) {
            return dp[key];
        }
        if(s!="" && mp[s]==1){
             ans = ans | helper(str,mp,index,"");
        }
        s.push_back(str[index]);
        ans= ans | helper(str,mp,index+1,s);
        return dp[key] = ans;
       
    } 
        
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        mp[""] = 1;
        for(auto word: wordDict) {
            mp[word] = 1;
        }
        return helper(s,mp,0,"");
    }
};