class Solution {
public:
       int min(int a,int b) {
        return a<b?a:b;
    }
	int calculateMaxSum(vector<int>&arr, int k, int index, vector<int>&dp) {
	if(index>=arr.size()) {
		return 0;
	}
	if(dp[index]!=-1) {
		return dp[index];
	}
	int mx = arr[index];
	int sol = 0;
	for(int i=index;i<min(arr.size(),index+k);i++) {
		mx = max(arr[i],mx);
		sol = max(sol,(mx*(i-index+1) + calculateMaxSum(arr, k, i+1,dp)));
	}
	return dp[index] = sol;
	}
		
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
		vector<int>dp(arr.size()+1,-1);
        int sol = calculateMaxSum(arr,k,0,dp);
		
		return sol;
    }
};
