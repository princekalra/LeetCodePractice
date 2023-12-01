class Solution {
public:
	int calculateWays(vector<int>&nums, int index, int sum) {
		
		if(index==nums.size()) {
            if(sum!=0) {
			return 0;
		}
		if(sum==0) {
			return 1;
		}
        }
			
		int take = calculateWays(nums, index+1, sum-nums[index]);
		int notTake = calculateWays(nums, index+1, sum);
		return (take+notTake);
	}
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
		for(auto num: nums) {
			sum+=num;
		}
		int targetSum = (target + sum);
		if(targetSum%2!=0) {
			return 0;
		}
		targetSum/=2;
		int sol = calculateWays(nums, 0,targetSum);
		return sol;
    }
};
