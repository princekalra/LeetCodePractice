class Solution {
public:
	bool calculateWordBreak(string &s, int start, int end, unordered_map<string,int>&mp, vector<int>&dp) {
	if(start>end) {
		return true;
	}
    
string str = "";
bool sol = false;
        if(dp[start]!=-1) {
            return dp[start];
        }
	for(int k=start;k<=end;k++) {
		str.push_back(s[k]);
		if(mp[str]==1) {
			sol = sol||calculateWordBreak(s,k+1,end,mp,dp);
		}
		if(sol) {
			break;
		}
			
			
}
return dp[start] = sol?1:0;
}
    bool wordBreak(string s, vector<string>& wordDict) {
    vector<int>dp(s.length()+1,-1);

       unordered_map<string,int>mp;
	 for(auto word: wordDict) {
		mp[word]=1;
	 }
	 return calculateWordBreak(s,0,s.length()-1,mp, dp);
    }
};
