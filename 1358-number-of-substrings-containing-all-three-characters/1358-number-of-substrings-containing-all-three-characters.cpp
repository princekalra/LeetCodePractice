class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        unordered_map<char,int>mp;
        int right = 0;
        int sol = 0;
        int left = 0;
        while(right<len){
            
                mp[s[right]]+=1;
                right++;
            while(mp.size()==3){
                sol+=(len-right+1);
                mp[s[left]]--;
                if(mp[s[left]]==0){
                    mp.erase(s[left]);
                }
                left++;
            }
           
        }
        return sol;
    }
};