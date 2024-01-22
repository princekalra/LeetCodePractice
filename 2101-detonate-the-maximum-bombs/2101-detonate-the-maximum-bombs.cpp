class Solution {
public:	
	bool isInRange(int x1, int y1, int r, int x2, int y2){
//         cout<<(sqrt((x2-x1)*(x2-x1) + (y2-y1)*
// (y2-y1)))<<endl;
        
			return (sqrt((long long)((long long)((long long)(x2-x1)*(long long)(x2-x1)) + (long long)((long long)(y2-y1)*
(long long)(y2-y1))))<=r); 
		}
    string getKey(int x,int y,int index){
        return to_string(x) + "#" + to_string(y) + "##" + to_string(index) +"###";
    }
	int DFS(int index,int x, int y, int r, unordered_map<int,int>&visited, vector< vector<int> >&bombs, int length_bombs){
        string key = getKey(x,y,index);
		visited[index] = 1;
		int count = 1;
        // if(dp[key]!=0){
        //     return dp[key];
        // }
		for(int i=0;i<length_bombs;i++){
			int new_x = bombs[i][0];
			int new_y = bombs[i][1];
			int new_r = bombs[i][2];
			if((visited[i]==0) && isInRange(x,y,r,new_x,new_y)){
				count+=DFS(i,new_x,new_y,new_r,visited,bombs,length_bombs);
			}
		}
		return count;
}
    int maximumDetonation(vector<vector<int>>& bombs) {
        int max_detonation = 1;
	int length_bombs = bombs.size();
                       
	for(int i=0;i<length_bombs;i++){
            unordered_map<int,int>visited;
		int count_of_bomb_blast = DFS(i,bombs[i][0], bombs[i][1], bombs[i][2],visited,bombs,length_bombs);
max_detonation = max(max_detonation,count_of_bomb_blast);	
	}
	return max_detonation;
    }   
};



