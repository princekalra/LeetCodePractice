class Solution {
public:
int getMaxProfit(vector<int>&prices, int index, bool buy, bool cooldown,vector<vector<vector<int> > >&dp){
	if(index==prices.size()){
		return 0;
	}
	int profit_by_buy=0;
	int profit_by_sell = 0;
	if(dp[index][buy][cooldown]!=-1){
		return dp[index][buy][cooldown];
	}
	if(buy){
		profit_by_buy = max(getMaxProfit(prices,index+1,buy,false,dp), cooldown?0: -prices[index] + getMaxProfit(prices,index+1,false,cooldown,dp));
	}
	else{
		profit_by_sell = max(getMaxProfit(prices,index+1,buy,cooldown,dp), prices[index] + getMaxProfit(prices,index+1,true,true,dp));
	}
	return dp[index][buy][cooldown] =  max(profit_by_buy,profit_by_sell);
}	
	    int maxProfit(vector<int>& prices) {
	int len = prices.size();
	vector< vector< vector<int> > >dp(len,vector<vector<int> >(2,vector<int>(2,-1)));
        	int sol = getMaxProfit(prices, 0, true,false,dp);
	return sol;
    }
};
