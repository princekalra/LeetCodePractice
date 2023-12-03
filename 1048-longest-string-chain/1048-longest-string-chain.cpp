class Solution {
public:
    int abs(int x) {
        return x>0?x:-1*x;
    }
	bool isValid(string s1, string s2) 
		{
		if(abs(s1.length()-s2.length())!=1) {
			return false;
		}
        if(s1.length()<s2.length()) {
            return isValid(s2,s1);
        }
		int i=0;
        int cnt = 0;
        int j=0;
        while(i<s1.length() &&j<s2.length()) {
            if(s1[i]!=s2[j]) {
                i++;
                cnt++;
                continue;
            }
            else {
                i++;
                j++;
            }
        }
        while(i<s1.length()) {
            cnt++;
            i++;
        }
        while(j<s2.length()) {
            cnt++;
            j++;
        }
        return cnt==1;
        
	}
        static bool cmp(string a,string b) {
            return a.length()<b.length();
        }
    int longestStrChain(vector<string>& words) {
        int len = words.size();
		vector<int>dp(len+1,1);
        sort(words.begin(),words.end(),cmp);
       for(auto x: words) {
           cout<<x<<" ";
       }
        cout<<endl;
        cout<<endl;
		for(int i=0;i<len;i++) {
			for(int j=i+1;j<len;j++) {
				if(isValid(words[i],words[j]) && dp[j]<(1+dp[i])) {
			dp[j] = dp[i] +1;
			}
			}
		}
		int sol = 1;
		for(int i=0;i<len;i++) {
			sol = max(sol,dp[i]);
		}
		return sol;
    }
};

