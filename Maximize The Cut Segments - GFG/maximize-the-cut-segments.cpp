//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,0);
        for(int i=x;i<=n;i++){
            if(i-x==0||dp[i-x]!=0)
            dp[i] = max(dp[i],dp[i-x]+1);
        }
        
          for(int i=y;i<=n;i++){
               if(i-y==0||dp[i-y]!=0)
            dp[i] = max(dp[i],dp[i-y]+1);
        }
        
    
          for(int i=z;i<=n;i++){
               if(i-z==0||dp[i-z]!=0)
            dp[i] = max(dp[i],dp[i-z]+1);
        }
        //  for(int i=0;i<=n;i++){
        //     cout<<dp[i]<<" ";
        // }
        // cout<<endl;
        // dp[n]-=1;
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends