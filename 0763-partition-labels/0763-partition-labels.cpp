class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lastIndex = -1;
        unordered_map<char,int>freq;
        unordered_map<char,int>mp;
        int length = s.length();
        for(int i=0;i<length;i++){
            freq[s[i]]+=1;
        }
        int cnt= 0;
        vector<int>sol;
        for(int i=0;i<length;i++){
            mp[s[i]]++;
            freq[s[i]]--;
            if(freq[s[i]]==0){
                cnt++;
            }
            if(mp.size() == cnt){
                sol.push_back((i-lastIndex));
                mp.clear();
                cnt = 0;
                lastIndex = i;
            }
        }
        return sol;
        
    }
};