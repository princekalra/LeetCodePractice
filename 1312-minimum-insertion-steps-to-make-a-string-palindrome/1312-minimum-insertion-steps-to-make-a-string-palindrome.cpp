class Solution {
public:
	int findLCS(string &str, string &rev_string,int str_index,int rev_string_index, vector< vector<int> >&dp) {
		if(str_index<0||rev_string_index<0) {
			return 0;
		}
        if(dp[str_index][rev_string_index]!=-1) {
                return dp[str_index][rev_string_index];
        }
		if(str[str_index] == rev_string[rev_string_index]) {
			return dp[str_index][rev_string_index] = 1+ findLCS(str,rev_string,str_index-1,rev_string_index-1,dp);
		}
		return dp[str_index][rev_string_index] = max(findLCS(str,rev_string,str_index-1,rev_string_index,dp),
				findLCS(str,rev_string,str_index,rev_string_index-1,dp));

	}
		
    int minInsertions(string s) {
		int len = s.length();
		vector<vector<int> >dp(len+1,vector<int> (len+1,-1));
        string str = s;
		string rev_string = s;
		reverse(rev_string.begin(),rev_string.end());
		int lcs = findLCS(str,rev_string,str.length()-1,rev_string.length()-1,dp);
		return s.length()-lcs;
    }
};
