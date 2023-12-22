class Solution {
public:
    string minWindow(string s, string t) {
        string sol = "";
        int right = 0;
        int left = 0;
        int length = s.length();
        unordered_map<char,int>mp;
        for(int j=0;j<t.length();j++){
            mp[t[j]]++;
        }
        int count = mp.size();
        int lastIndex = 0;
        int minLength = INT_MAX;
        while(right<length){
           if(mp.find(s[right])!=mp.end()){
               mp[s[right]]--;
               if(mp[s[right]]==0){
                   count--;
               }
              
           }
            while(count==0 ){
                if(minLength>(right-left+1)){
                    minLength = right-left+1;
                    lastIndex = left;

                }
                if(mp.find(s[left])!=mp.end()){
                    mp[s[left]]++;
                    if(mp[s[left]]>0){
                        count++;
                    }
                }
                left++;
            }
             right++;
        }
        if(minLength == INT_MAX){
            return "";
        }
        return s.substr(lastIndex,minLength);
    }
};