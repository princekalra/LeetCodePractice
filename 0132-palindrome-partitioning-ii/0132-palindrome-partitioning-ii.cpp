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
// 	int calculateMinCut(string &s, int index, vector<int>&dp) {
// 		if(index>=s.length()-1) {
// 			return 0;
// 			}
// 		if(isPalindrome(s,index,s.length()-1)) {
// 			return 0;
// 		}
// 		if(dp[index]!=-1) {
// 			return dp[index];
// 		}
// 		int sol = INT_MAX;
// 		for(int k=index;k<s.length();k++) {
// 			if(isPalindrome(s,index,k)) {
// 				sol = min(sol,1 + calculateMinCut(s,k+1, dp));
// 			}
// 		}
// 		return dp[index] = sol;
// 	}
			
		int calculateMinCutTab(string &s) {
			int len = s.length();
			vector<int>dp(len+1,0);
			for(int i=len-1;i>=0;i--) {
                    int sol = INT_MAX;
                if(isPalindrome(s,i,s.length()-1)) {
                    dp[i] = 0;
                    continue;
                }
				for(int j=i;j<len;j++) {
					if(isPalindrome(s,i,j)) {
				sol =  min(sol,1 + dp[j+1]);
					}
				}
                dp[i] = sol;
			}
			return dp[0];
		}

					
    int minCut(string s) {
        int sol = calculateMinCutTab(s);
		return sol;
    }
};
