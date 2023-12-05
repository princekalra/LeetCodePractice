class Solution {
public:
    int climbStairs(int n) {
    vector<int>dp(n+1,0);
    if(n==0||n==1||n==2) {
        return  n;
    }
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
    int prev = 2;
    int second_prev = 1;
    int sol = prev;
	for(int i=3;i<=n;i++) {
		sol = prev + second_prev;
        second_prev = prev;
        prev = sol;
        
	}
	return sol;
    }
};
