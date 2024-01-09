class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,1e4+1);
        dp[0] = 0;
        sort(coins.begin(),coins.end(),greater<int>());
        for(int i=0;i<coins.size();i++){
            cout<<coins[i]<<endl;
            for(int j=1;j<=amount;j++){
                if(coins[i]<=j && dp[j]>(1+dp[j-coins[i]])){
                    dp[j] = 1+dp[j-coins[i]];
                }
            }
          
            }
        
        if(dp[amount]>=1e4+1){
           
            return -1;
        }
        return dp[amount];
    }
};