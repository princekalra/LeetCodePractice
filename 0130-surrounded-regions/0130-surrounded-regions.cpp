class Solution {
public:
    void DFS(vector< vector<char> >&board, int row,int col){
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || board[row][col]!='O'){
            return;
        }
        board[row][col] = '#';
        DFS(board,row+1,col);
        DFS(board,row-1,col);
        DFS(board,row,col+1);
        DFS(board,row,col-1);
        
    }
    void solve(vector<vector<char>>& board) {
       int row = board.size();
        int column = board[0].size();
        for(int i=0;i<row;i++){
            if(board[i][0]=='O'){
                DFS(board,i,0);
            }
            if(board[i][column-1]=='O'){
                DFS(board,i,column-1);
            }
        }
        for(int j=1;j<(column-1);j++){
            if(board[0][j]=='O'){
                DFS(board,0,j);
            }
            if(board[row-1][j]=='O'){
                DFS(board,row-1,j);
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};