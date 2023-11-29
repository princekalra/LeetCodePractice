class Solution {
public:
  bool isSafe(int row,int col,vector<vector<int> >&grid) {
    if(row<0||col<0||row>=grid.size()||col>=grid[0].size()||grid[row][col]==0||grid[row][col]==2) {
	return false;
	}
	return true;
 }
    int orangesRotting(vector<vector<int>>& grid) {
     int row = grid.size();
int col = grid[0].size();
queue<pair<int,int> >q;
for(int i=0;i<row;i++) {
for(int j=0;j<col;j++) {
if(grid[i][j]==2) {
q.push({i,j});
}
}
}
int cnt = 0;
vector<pair<int,int> >vec = {{0,-1},{-1,0},{0,1},{1,0}};
while(q.empty()==false) {
int n = q.size();
    bool key = false;
while(n--) {
int r = q.front().first;
int c = q.front().second;
    q.pop();
for(auto x:vec) {
	if(isSafe(r+x.first, c+x.second,grid)) {
		q.push({r+x.first, c+x.second});
		grid[r+x.first][c+x.second]=2;
        key = true;
	}
}
}
    if(key)
    cnt++;


}
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j]==1) {
                    return -1;
                }
            }
        }
return cnt;
   
    }
};
