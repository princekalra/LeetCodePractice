class Solution {
public:
	void DFS(int row, int col, vector< vector<int> >&grid){
		if(row<0||col<0||row>=grid.size()||col>=grid[0].size()||grid[row][col]==0||grid[row][col]==2){
			return;
		}
        // cout<<grid[row][col]<<"#"<<endl;
		grid[row][col] = 2;
		DFS(row+1,col,grid);
		DFS(row-1,col,grid);
		DFS(row,col+1,grid);
		DFS(row,col-1,grid);
	}
	
		
		
    int shortestBridge(vector<vector<int>>& grid) {
        
	int row_length = grid.size();
	int col_length = grid[0].size();
        bool key = false;
	for(int i=0;i<row_length;i++){
		for(int j=0;j<col_length;j++){
            if(key){
                break;
            }
			if(grid[i][j] == 1){
				DFS(i,j,grid);
                key = true;
			}
		}
        if(key){
            break;
        }
	}
	queue<pair<int,int> >q;
	for(int i=0;i<row_length;i++){
		for(int j=0;j<col_length;j++){
            cout<<grid[i][j]<<" ";
			if(grid[i][j]==1){
				q.push({i,j});
			}
		}
	}
	int number_of_flips = -1;
	vector<pair<int,int> >adj = {{-1,0},{1,0},{0,-1},{0,1}};
	while(q.empty() == false){
        cout<<"!";
		int size = q.size();
		number_of_flips++;
        // cout<<number_of_flips;
		while(size--){
		int row = q.front().first;
		int col = q.front().second;
		
		q.pop();
		for(int i=0;i<4;i++){
			int new_row = row + adj[i].first;
			int new_col = col + adj[i].second;
			if(new_row>=0 && new_row<row_length && new_col>=0 && new_col<col_length ){
				if( grid[new_row][new_col]==0 ){
					
				grid[new_row][new_col] = 1;
				q.push({new_row,new_col});

				}
				else if(grid[new_row][new_col]==2)
					{
return number_of_flips;					
					}
				}

			
}


		
		}
}
		
		
	return number_of_flips;

    }
};

