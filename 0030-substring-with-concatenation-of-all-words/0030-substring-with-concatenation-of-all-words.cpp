class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        
        for(int i=0;i<words.size();i++){
            mp[words[i]] +=1;
        }
        vector<int>sol;
        int size = words.size()*words[0].length();
        for(int i=0;(i+size)<=s.length();i++){
            unordered_map<string,int>mp1;
            int j = i;
            int wordLen = words[0].length();
            while(j<(i+size)){
                string str = s.substr(j,wordLen);
                 if(mp1[str]<mp[str]){
                       mp1[str]+=1;
                    }
                    else{
                        break;
                    }
                j+=wordLen;  
            }
          
            if(j==(i+size)){
                sol.push_back(i);
            }
        }
        return sol;
    }
};