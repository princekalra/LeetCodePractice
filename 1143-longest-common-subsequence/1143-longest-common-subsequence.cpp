class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int text1Len = text1.length();
        int text2Len = text2.length();
        vector<int>dp(text2Len+1,0);
        int sol = 0;
        for(int i=1;i<=text1Len;i++) {
            int prev = 0;
            for(int j=1;j<=text2Len;j++) {
                int temp = dp[j];
                if(text1[i-1] ==  text2[j-1]) {
                    dp[j] = 1 + prev;
                }
                else {
                    dp[j] = max(dp[j-1],dp[j]);
                }
                sol = max(sol,dp[j]);
                prev = temp;
            }
        }
        return sol;
    }
};