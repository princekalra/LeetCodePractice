
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
	for(auto num: nums) {
		sum+=num;
	}
	if(sum%2!=0) {
		return false;
	}
	sum/=2;
	vector<bool>dp(sum+1,false);
	dp[0] = true;
	int len = nums.size();
	for(int i=0;i<len;i++) {
		for(int j =sum;j>=1;j--) {
            if(nums[i]<=j)
			dp[j] = dp[j] || dp[j-nums[i]];
		}
	}
	return dp[sum];
    }
};
