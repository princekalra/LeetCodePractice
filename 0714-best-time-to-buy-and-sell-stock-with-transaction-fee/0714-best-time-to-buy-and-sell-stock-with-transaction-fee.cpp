class Solution {
public:
    int getSol(vector<int>&prices, int index, int fee, int buy, vector< vector<int> >&dp){
        if(index == prices.size()){
            return 0;
        }
        int profit = 0;
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        if(buy==0){
            profit = max(getSol(prices,index+1,fee,buy,dp), -1*prices[index] + getSol(prices,index+1,fee,1,dp));
        }
        else{
            profit = max(getSol(prices, index+1,fee,buy,dp), -1*fee + prices[index] + getSol(prices,index+1,fee,0,dp));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector< vector<int> >dp(prices.size()+1,vector<int>(2,-1));
        int sol = getSol(prices,0,fee,0,dp);
        return sol;
    }
};