//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int getMaxProfit(int A[], int k, int N, int index, bool canBuy,vector<vector<vector<int> > >&dp){
      if(index>=N||k<=0){
          return 0;
      }
      int byBuying = 0;
      int bySelling = 0;
      if(dp[index][k][canBuy]!=-1){
          return dp[index][k][canBuy];
      }
      if(canBuy){
          byBuying =  -1*A[index] + getMaxProfit(A,k,N,index+1,false,dp);
      }
      else {
          bySelling = A[index] + getMaxProfit(A,k-1,N,index+1,true,dp);
      }
      int bySkipping = getMaxProfit(A,k,N,index+1,canBuy,dp);
      return  dp[index][k][canBuy] = max({byBuying,bySelling, bySkipping});
  }
    int maxProfit(int K, int N, int A[]) {
        vector< vector< vector<int> > >dp(N+1,vector< vector<int> >(K+1,vector<int>(2,-1)));
        int profit = getMaxProfit(A,K,N,0,true,dp);
        return profit;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends