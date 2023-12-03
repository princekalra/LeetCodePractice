class Solution {
public:
	bool isPalindrome(string &s, int start, int end) {	
		while(start<end) {
			if(s[start]!=s[end]) {
				return false;
			}
			start++;
			end--;
		}
		return true;
	}
	int calculateMinCut(string &s, int index, vector<int>&dp) {
		if(index>=s.length()-1) {
			return 0;
			}
		if(isPalindrome(s,index,s.length()-1)) {
			return 0;
		}
		if(dp[index]!=-1) {
			return dp[index];
		}
		int sol = INT_MAX;
		for(int k=index;k<s.length();k++) {
			if(isPalindrome(s,index,k)) {
				sol = min(sol,1 + calculateMinCut(s,k+1, dp));
			}
		}
		return dp[index] = sol;
	}
			
		
    int minCut(string s) {
		vector<int>dp(s.length(),-1);
        int sol = calculateMinCut(s,0,dp);
		return sol;
    }
};

