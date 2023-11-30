// class Solution {
// public:
//    int minDistanceUtil(string &word1, string &word2, int i, int j, vector< vector<int> >&dp) {
// 	if(i==word1.length()) {
// 		return word2.length()-j;
// 	}
// 	if(j==word2.length()) {
// 		return word1.length()-i;
// 	}
// 	if(dp[i][j]!=-1) {
// 		return dp[i][j];
// 	}
// 	if(word1[i] == word2[j]) {
// 		return dp[i][j] =  minDistanceUtil(word1, word2,i+1,j+1, dp);
// 	}
// 	return dp[i][j] = 1 + min({minDistanceUtil(word1,word2,i,j+1, dp),minDistanceUtil(word1,word2,i+1,j, dp), minDistanceUtil(word1,word2,i+1,j+1, dp)});
// 	}
	
//     int minDistance(string word1, string word2) {
// 	int n = word1.length();
// 	int m = word2.length();
// 	vector< vector<int> >dp(n, vector<int>(m, -1) );
// 	int sol = minDistanceUtil(word1,word2,0,0, dp);

// 	return sol;
        
//     }
// };
class Solution {
public:
  
    int minDistance(string word1, string word2) {
	int n = word1.length();
	int m = word2.length();
	vector<int>dp(m+1,1);
        for(int j=0;j<=m;j++) {
            dp[j] = j;
        }
	for(int i=1;i<=n;i++) {
        int prev = dp[0]; // Stores the value of the previous diagonal element
            dp[0] = i;
		for(int j=1;j<=m;j++) {
			int temp = dp[j];
			if(word1[i-1] == word2[j-1]) {
				dp[j] = prev;
			}
			else {
				dp[j] = 1 + min({dp[j-1],dp[j],prev});
			}
            prev = temp;
		}
	}

	return dp[m];
				
		
    }
};






