class Solution {
public:
	// int calculateMinCost(int indexStart, int indexEnd, vector<int>&cuts, int rodStart, int rodEnd, vector< vector<int> >&dp) {
	// 	int mi = INT_MAX;
	// 	if(indexStart>=indexEnd) {
	// 		return 1000001;
	// 	}
	// 	if(rodStart>=rodEnd) 	{
	// 		return 1000001;
	// 	}
	// 	for(int k=indexStart;k<=indexEnd;k++) {
	// 		int sol = rodEnd-rodStart;
	// 		sol += min(calculateMinCost(indexStart,k-1,cuts,rodStart,cuts[k],dp),
	// 				calculateMinCost(k+1,indexEnd, cuts, cuts[k], rodEnd,dp));
	// 		mi = min(mi,sol);
	// 	}
	// 	return mi;
	// 	}
  int calculateMinCost(vector<int>&arr, int start, int end, int stickStart, int stickEnd, vector< vector<int> >&dp) {
	
if(start>end) {
	return 0;
	}
      if(dp[start][end]!=-1) {
          return dp[start][end];
      }

		int cost  = INT_MAX;
	for(int k=start;k<=end;k++) {
		cost  = min(cost,((stickEnd-stickStart) + calculateMinCost(arr, start,k-1, stickStart, arr[k],dp) + calculateMinCost(arr,k+1,end, arr[k], stickEnd,dp)));
		}
		return dp[start][end] = cost;
	}
		
int minCost(int n, vector<int>& cuts) {
      int len = cuts.size();
	sort(cuts.begin(),cuts.end());
    vector< vector<int> >dp(len+1,vector<int>(len+1,-1));
int sol = calculateMinCost(cuts,0,len-1,0,n,dp);   	
	return sol;
    }


};
