// class Solution {
// public:
// 	    int findTargetSumWays(vector<int>& nums, int target) {
//         int sum = 0;
// 		for(auto num: nums) {
// 			sum+=num;
// 		}
// 		int targetSum = (target + sum);
// 		if(targetSum%2!=0 || targetSum<0) {
// 			return 0;
// 		}
// 		targetSum/=2;
// 		vector< vector<int> >dp(nums.size()+1, vector<int>(targetSum+1,0));
//             int n = nums.size();
//             dp[0][0]=1;
// 		for(int i=1;i<=n;i++) {
// 			for(int j=0;j<=targetSum;j++) {
				
				
// 				if(nums[i-1]<=j) {
// 					dp[i][j] = (dp[i-1][j-nums[i-1]] + dp[i-1][j]);
// }
// else {
// 	dp[i][j] = dp[i-1][j];
// }
// 			}
// 		}
//  	return dp[n][targetSum];
		
		
//     }
// };


// class Solution {
// public:
// 	    int findTargetSumWays(vector<int>& nums, int target) {
//         int sum = 0;
// 		for(auto num: nums) {
// 			sum+=num;
// 		}
// 		int targetSum = (target + sum);
// 		if(targetSum%2!=0 || targetSum<0) {
// 			return 0;
// 		}
// 		targetSum/=2;
// 		vector< vector<int> >dp(2, vector<int>(targetSum+1,0));
// 		dp[0][0]=1;
//         int n = nums.size();
// 		for(int i=1;i<=n;i++) {
// 			int current = i%2;
// 			int prev = 1-current;
// 			for(int j=0;j<=targetSum;j++) {
// 				if(nums[i-1]<=j) {
// 					dp[current][j] = (dp[prev][j-nums[i-1]] + dp[prev][j]);
// }
// else {
// 	dp[current][j] = dp[prev][j];
// }
// 			}
// 		}
//  	return dp[n%2][targetSum];
		
		
//     }
// };



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
		vector<int>dp(targetSum+1,0);
		dp[0]=1;
        int n = nums.size();
		for(int i=1;i<=n;i++) {
			for(int j=targetSum;j>=0;j--) {
									if(nums[i-1]<=j) {
					dp[j] = (dp[j] + dp[j-nums[i-1]]);
}
			}
		}
 	return dp[targetSum];
		
		
    }
};

