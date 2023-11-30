//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int helper(int start, int end, int arr[], vector< vector<int> >&memo)
	{
	if(start == end) {
		return 0;
	}
	if(memo[start][end]!=-1) {
		return memo[start][end];
	}
	int mi = INT_MAX;
	for(int k = start; k<end;k++) {
		int steps = arr[start-1]*arr[k]*arr[end];
		mi = min( steps + helper(start,k,arr, memo) + helper(k+1,end,arr,memo), mi);
	}
	return memo[start][end] = mi;
	}
	
    int matrixMultiplication(int N, int arr[])
    {
	if(N<=1) {
		return 0;
	}
	vector< vector<int> >memo(N, vector<int>(N,-1) );
     return  helper(1,N-1,arr,memo);
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