class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
                int len = nums.size();
        sort(nums.begin(),nums.end());
		vector<int>dp(len+1,1);
		for(int i=1;i<=len;i++)	{
		for(int j=i+1;j<=len;j++) {
			if(nums[j-1]%nums[i-1] == 0 ) {
dp[j] = max(dp[j],1+dp[i]);
}
         
}
        }
       
            int sol = 0;
            int index =-1;
            int prev = -1;
            for(int i=1;i<dp.size();i++) {
                    if(sol<dp[i]) {
                        sol = dp[i];
                        prev = nums[i-1];
                        index = i-1;
                    }
            }
        
            vector<int>ans;
        if(sol==1) {
            ans.push_back(nums[0]);
            return ans;
        }
        
            for(int j=index;j>=0;j--) {
                if(dp[j+1]==sol && (nums[j]%prev==0||prev%nums[j]==0)) {
                    ans.push_back(nums[j]);
                    sol -=1;
                    prev = nums[j];
                }
            }
            reverse(ans.begin(),ans.end());
                    return ans; 

        }
    
};

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int len = nums.size();
// 		vector<int>dp(len+1,1);
// 		dp[0] = 1;
// 		for(int i=1;i<=len;i++)	{
// 		for(int j=i+1;j<=len;j++) {
// 			if(nums[j-1]>nums[i-1] ) {
// dp[j] = max(dp[j],1+dp[i]);
// }
         
// }
             

//     }
//         int sol = 0;
//         for(auto x:dp) {
//             sol = max(sol,x);
//         }
//         return sol; 
//     }      
// };
