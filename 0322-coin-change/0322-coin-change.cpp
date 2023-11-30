// class Solution {
// public:
// 	int coinChangeHelper(int index, vector<int>&coins, int amount, vector< vector<int> >&memo) 
// 	{
// 		if(amount<0) {
// 			return 10001;
// 		}
// 		if(amount==0) {
// 			return 0;
// 		}
// 		if(index>=coins.size()) {
// 			return 10001;
// 		}
// 		if(memo[index][amount]!=-1) {
// 			return memo[index][amount];
// 		}
// 		int take = 1 + coinChangeHelper(index, coins, amount-coins[index], memo);
// 		int notTake = coinChangeHelper(index+1, coins, amount, memo);
// 		return memo[index][amount] = min(take,notTake);
// 	}
//     int coinChange(vector<int>& coins, int amount) {
// 	int len = coins.size();
// 	vector<vector<int> >memo(len,vector<int>(amount+1,-1));
//       int sol =  coinChangeHelper(0,coins,amount, memo);
//         if(sol>=10001)  {
//             return -1;
//         }
//         return sol;
//     }
// };
class Solution {
public:
	
    int coinChange(vector<int>& coins, int amount) {
	int len = coins.size();
	vector< vector<int> >dp(len+1, vector<int>(amount+1,10001));
        
	for(int i=1;i<=len;i++) {
		for(int j=0;j<=amount;j++) {
            
            if(j==0) {
                dp[i][j] = 0;
                continue;
            }
          
			int take = 10001;
			if(coins[i-1]<=j ) {
				dp[i][j] = min(dp[i][j], 1+ dp[i][j-coins[i-1]]);
			}
				dp[i][j] = min(dp[i][j], dp[i-1][j]); 
		}
	}
        if(dp[len][amount]>=10001){
            return -1;
        }
return dp[len][amount];
			
	
    }
};







