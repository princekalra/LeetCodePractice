class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        vector<bool>dp(2*10000+100,false);
	int baseCosts_length = baseCosts.size();
	for(int i=0;i<baseCosts_length;i++){
		dp[baseCosts[i]] = true;
	}
	int toppingCosts_length = toppingCosts.size();
	for(int i=0;i<toppingCosts_length;i++){
		for(int j=2*10000+100;j>=1;j--){
			if(2*toppingCosts[i]<=j && dp[j-2*toppingCosts[i]]==true)
				{
					dp[j] = true;
				}
				else if(toppingCosts[i]<=j && dp[j-toppingCosts[i]]==true){
					dp[j] = true;
				}
		}
	}
int closest_cost=-1;
int min_diff = INT_MAX;
for(int i=2*10000+100;i>=0;i--){
	if(dp[i]==true){
		if(min_diff>=abs(i-target)){
			min_diff = abs(i-target);
			closest_cost = i;
		}
	}
}
		return closest_cost;
    }
};
