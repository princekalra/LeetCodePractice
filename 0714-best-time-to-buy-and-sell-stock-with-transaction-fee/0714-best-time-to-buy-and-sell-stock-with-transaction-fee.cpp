// class Solution {
// public:
//     int getSol(vector<int>&prices, int index, int fee, int buy, vector< vector<int> >&dp){
//         if(index == prices.size()){
//             return 0;
//         }
//         int profit = 0;
//         if(dp[index][buy]!=-1){
//             return dp[index][buy];
//         }
//         if(buy==0){
//             profit = max(getSol(prices,index+1,fee,buy,dp), -1*prices[index] + getSol(prices,index+1,fee,1,dp));
//         }
//         else{
//             profit = max(getSol(prices, index+1,fee,buy,dp), -1*fee + prices[index] + getSol(prices,index+1,fee,0,dp));
//         }
//         return dp[index][buy] = profit;
//     }
//     int maxProfit(vector<int>& prices, int fee) {
//         vector< vector<int> >dp(prices.size()+1,vector<int>(2,-1));
//         int sol = getSol(prices,0,fee,0,dp);
//         return sol;
//     }
// };
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
        vector< vector<int> >dp(prices.size()+1,vector<int>(2,0));
        int len = prices.size();
        int lastBuy = 0;
        int lastSell = 0;
        for(int i=len-1;i>=0;i--){
            for(int buy =0;buy<=1;buy++){
                if(buy==0){
                    dp[i][buy] = max(dp[i+1][buy], -1*prices[i] + lastSell);
                }
                else{
                    dp[i][buy] = max(dp[i+1][buy], -1*fee + prices[i] + lastBuy);
                }
            }
            lastBuy = dp[i][0];
            lastSell = dp[i][1];
        }
        return lastBuy;
    }
};