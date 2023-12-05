class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
		if(len==1) {
			return nums[0];
		}
		if(len == 2) {
			return max(nums[0],nums[1]);
		}
	
    vector<int>dp1(len+1,0);
vector<int>dp2(len+1,0);


	dp1[1] = nums[0];
	for(int i=2;i<len;i++) {
	dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i-1]);
	}
dp2[2] = nums[1];
	for(int i=3;i<=len;i++) {
	dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i-1]);
	}


	
	return max(dp1[len-1],dp2[len]);

    }
};
