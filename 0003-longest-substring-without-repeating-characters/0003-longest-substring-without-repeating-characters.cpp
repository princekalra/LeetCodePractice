class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len =s.length();
        unordered_map<char,int>mp;
        int sol = 0;
        int j = 0;
        for(int i=0;i<len;i++){
            mp[s[i]]++;
            while(mp[s[i]]>1 && j<i){
                mp[s[j]]--;
                j++;
            }
            sol = max(sol,i-j+1);
        }
        return sol;
    }
};