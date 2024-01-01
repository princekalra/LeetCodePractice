class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> >mp;
        for(auto str: strs){
            string newstr = str;
            sort(newstr.begin(),newstr.end());
            mp[newstr].push_back(str);
        }
        vector<vector<string> >sol;
        for(auto m:mp){
            sol.push_back(m.second);
        }
        return sol;
    }
};