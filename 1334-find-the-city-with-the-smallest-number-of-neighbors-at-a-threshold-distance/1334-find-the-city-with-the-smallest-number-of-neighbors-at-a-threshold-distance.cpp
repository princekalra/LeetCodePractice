class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector< vector<int> >weights(n,vector<int>(n,1000000));
	   for(auto edge: edges){
			int src = edge[0];
			int destination = edge[1];
			int weight = edge[2];
			weights[src][destination] = weight;
			weights[destination][src] = weight;
			}
		for(int k=0;k<n;k++) {
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(weights[i][j]>(weights[i][k] +weights[k][j])){
						weights[i][j] =weights[i][k] +weights[k][j];
					}
				}
			}
		}
		int sol = -1;
		int max_count = INT_MAX;
		for(int i=0;i<n;i++){
			int cnt = 0;
			for(int j=0;j<n;j++) {
				if(i!=j){
					if(weights[i][j]<=distanceThreshold)	{
						cnt++;
}	
				}
			}
			if(max_count>cnt){
				max_count = cnt;
				sol = i;
			}
			else if(max_count == cnt){
				sol = i;
			}

		
		
	
    }
	return sol;
	}
};
