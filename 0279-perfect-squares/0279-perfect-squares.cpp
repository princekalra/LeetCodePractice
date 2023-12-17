class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(10001,INT_MAX);
	// for(int i=0;i<=10000;i++){
	// 	dp[i] = i;
	// }
        dp[0]=0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3]= 3;
	for(int i=2;i*i<=n;i++){
		for(int j = i*i;j<=n;j++){
		
		int square_number = i*i;
            
		dp[j] = min(dp[j],((dp[j-square_number]==INT_MAX?(j-square_number):(dp[j-square_number])) + 1));
	}
		
	}
	return dp[n];
    }
};
