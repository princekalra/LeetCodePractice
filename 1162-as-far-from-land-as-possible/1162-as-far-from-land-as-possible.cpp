class Solution {
public:
    void bfs(queue<pair<int,int> >&q,vector<vector<int> >&maxDistance,vector<vector<int> >&grid){
        vector<pair<int,int>>vec = {{0,-1},{-1,0},{0,1},{1,0}};
        while(q.empty()==false){
            int curr_x = q.front().first;
            int curr_y = q.front().second;
            q.pop();
            for(int j=0;j<4;j++){
                int new_x = curr_x + vec[j].first;
                int new_y = curr_y + vec[j].second;
                if(new_x>=0 && new_y>=0 && new_x<grid.size() && new_y<grid.size() && (maxDistance[new_x][new_y]>maxDistance[curr_x][curr_y]+1)){
                    q.push({new_x,new_y});
                    maxDistance[new_x][new_y] = maxDistance[curr_x][curr_y]+1;
                }
            }
            
        }
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int> >maxDistance(n,vector<int>(n,INT_MAX));
        queue<pair<int,int> >q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    maxDistance[i][j] = 0;
                }
            }
        }
        bfs(q,maxDistance,grid);
        int sol = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // cout<<maxDistance[i][j]<<" ";
                if(maxDistance[i][j]!=0 && maxDistance[i][j]!=INT_MAX){
                    sol = max(sol,maxDistance[i][j]);
                }
            }
            // cout<<endl;
        }
        return sol;
    }
};