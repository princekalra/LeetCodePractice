class Solution {
public:
	bool isSafe(int row,int col, vector<vector<int> >&grid, vector<vector<int> >&distance,int current_distance){
       
		if(row>=0 && col>=0 && row< grid.size() && col< grid.size() && grid[row][col]==0 && distance[row][col]>(current_distance+1)){
			return true;
		}
		return false;
	}

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
	   vector< vector<int> >distance(n+1,vector<int>(n+1,INT_MAX));
		distance[0][0] = 0;
		queue<pair<int,pair<int,int> > >q;
		if(grid[0][0]!=0) {
			return -1;
		}
		q.push({1,{0,0}});
		vector<pair<int,int> >edge = {{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
		while(q.empty() == false) {
			int current_distance = q.front().first;
			int current_row = q.front().second.first;
			int current_col = q.front().second.second;
            cout<<current_row<<" "<<current_col<<endl;
            q.pop();
			if(current_row==(n-1) && current_col ==(n-1))	{
				return current_distance;
			}
			for(auto x: edge) {
				int new_row = current_row + x.first;
				int new_col = current_col + x.second;
				if(isSafe(new_row,new_col,grid,distance,current_distance))	{
				distance[new_row][new_col] = current_distance + 1;
			q.push({current_distance+1,{new_row,new_col}});
			}
			}
		}

return -1;			
    }
};
