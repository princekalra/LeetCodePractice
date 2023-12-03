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

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int len = nums.size();
	  vector<int>dp(len+1,INT_MAX);
	  for(int i=0;i<len;i++) {
		int idx = lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
		dp[idx] = nums[i];
		}
	int sol = 0;
for(int i=0;i<=len;i++) {
if(dp[i]!=INT_MAX) {
sol = i+1;
}
else {
break;
}
}
return sol;	
    }      
};

