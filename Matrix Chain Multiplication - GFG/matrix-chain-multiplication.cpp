//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     int matrixMultiplication(int N, int arr[])
    {
vector< vector<int> >dp(N+1, vector<int>(N+1,INT_MAX));
for(int i=0;i<=N;i++) {
dp[i][i] = 0;
}

for(int len = 2;len<=N-1;len++) {
	for(int i = 1;i<N-len+1;i++) 
{
    int	j = i+len-1;
	int mi = INT_MAX;
for(int k=i;k<j;k++) {
int steps = arr[i-1]*arr[k]*arr[j];
mi = min(mi, dp[i][k] + dp[k+1][j] + steps);
}
dp[i][j] = mi;
}
	}
	return dp[1][N-1];
    }
};







//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends