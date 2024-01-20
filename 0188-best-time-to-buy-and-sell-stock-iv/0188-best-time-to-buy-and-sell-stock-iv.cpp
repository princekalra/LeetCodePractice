class Solution {
public:
    int getSol(int k, vector<int>&prices, vector< vector< vector<int> > >&dp, int buy, int cap,int index){
        if(cap==k||index==prices.size()){
            return 0;
        }
        int profit = 0;
        if(dp[index][cap][buy]!=-1){
            return dp[index][cap][buy];
        }
        if(buy == 1){
             int opt1 = getSol(k,prices,dp,buy,cap,index+1);
            int opt2 = prices[index] + getSol(k,prices,dp,0,cap+1,index+1);
            profit = max(opt1,opt2);
        }
        else{
            int opt1 = getSol(k,prices,dp,buy,cap,index+1);
            int opt2 = -1*prices[index] + getSol(k,prices,dp,1,cap,index+1);
            profit = max(opt1,opt2);
        }
        return dp[index][cap][buy] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int length_prices = prices.size();
        vector< vector< vector<int> > >dp(length_prices +1 ,vector< vector<int> >(k+1,vector<int>(2,-1)) );
        int sol = getSol(k,prices,dp,0,0,0);
        return sol;
    }
};