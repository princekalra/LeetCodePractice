class Solution {
public:
	int maxProfit(vector<int>&prices, bool buy, int cnt, int index, vector< vector< vector<int> > >&dp)
{
		if(cnt == 2){
			return 0;
		}
		if(index>=prices.size()){
			return 0;
		}
		if(dp[index][cnt][buy]!=-1){
			return dp[index][cnt][buy];
		}
		int take = 0;
		int not_take = 0;
		if(buy){
			take = max(maxProfit(prices,buy,cnt,index+1,dp), maxProfit(prices,!buy,cnt,index+1,dp)+-1*prices[index]);
			}
			else{
		not_take = max(maxProfit(prices, buy, cnt, index+1,dp), prices[index]+maxProfit(prices,!buy,cnt+1,index+1,dp));
			}
		return dp[index][cnt][buy] = max(take, not_take);
	}
    int maxProfit(vector<int>& prices) {
	vector< vector< vector<int> > >dp(prices.size(),vector<vector<int> >(2,vector<int>(2,-1)));
        int max_profit =  maxProfit(prices,true,0,0,dp);
	return max_profit;
    }
};

