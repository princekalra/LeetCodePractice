class Solution {
public:
	    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
		for(auto num: nums) {
			sum+=num;
		}
		int targetSum = (target + sum);
		if(targetSum%2!=0 || targetSum<0) {
			return 0;
		}
		targetSum/=2;
		vector< vector<int> >dp(nums.size()+1, vector<int>(targetSum+1,0));
            int n = nums.size();
            dp[0][0]=1;
		for(int i=1;i<=n;i++) {
			for(int j=0;j<=targetSum;j++) {
				
				
				if(nums[i-1]<=j) {
					dp[i][j] = (dp[i-1][j-nums[i-1]] + dp[i-1][j]);
}
else {
	dp[i][j] = dp[i-1][j];
}
			}
		}
 	return dp[n][targetSum];
		
		
    }
};

