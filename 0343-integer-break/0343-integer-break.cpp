class Solution {
public:
    int helper(vector<int>&dp, int n) {
         if(n==1||n==2){
          return 1;
      }
        if(dp[n]!=-1){
            return dp[n];
        }
         int sol = 1;
      for(int i=1;i<=(n/2);i++) {
          sol = max(sol,(max(i,helper(dp,i))*max(n-i,helper(dp,n-i))));
      }
        return dp[n] = sol;
    }
    int integerBreak(int n) {
      vector<int>dp(n+1,-1);
        return helper(dp,n);
    }
};

