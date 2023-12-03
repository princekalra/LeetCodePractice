class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
     int len = nums.size();
     vector<int>dp(len,1);
     vector<int>cnt(len,1);
        int mx = 1;
        for(int i=0;i<len;i++){
            for(int prev = i+1;prev<len;prev++) {
                if(nums[prev]>nums[i] && dp[prev]<(1+dp[i])) {
                    dp[prev] = 1 + dp[i];
                    cnt[prev] = cnt[i];
                }
                else if(nums[prev]>nums[i] && dp[prev]==(1+dp[i])) {
                    cnt[prev] += cnt[i];
                }
            }
            mx = max(mx,dp[i]);
        }
        int sol = 0;
        for(int i=0;i<len;i++) {
            if(dp[i] == mx) {
                sol += cnt[i];
            }
        }
        return sol;
    }
};