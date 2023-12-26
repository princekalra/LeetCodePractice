class Solution {
public:
    int integerBreakHelper(int n, vector<int>&dp){
        if(n==0||n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int maxProduct = 1;
       for(int i=1;i<=n;i++){
          int prod = i*(integerBreakHelper(n-i,dp));
           maxProduct = max(prod,maxProduct);
       } 
        return dp[n] = maxProduct;
        
    }
    int integerBreak(int n) {
        vector<int>dp(60,-1);
        int mx = 1;
        for(int i=1;i<n;i++){
            int prod = i* integerBreakHelper(n-i,dp);
             mx = max(prod,mx);
        }
       return mx;
    }
};