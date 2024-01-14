class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int length_row = matrix.size();
        int length_col = matrix[0].size();
        int count = 0;
        for(int i=0;i<length_row;i++){
            for(int j=0;j<length_col;j++){
                int diagonal = 0;
                int left = 0;
                int up = 0;
                if(i>0){
                    up = matrix[i-1][j];
                }
                if(j>0){
                    left = matrix[i][j-1];
                }
                if(i>0 && j>0){
                    diagonal = matrix[i-1][j-1];
                }
                if(matrix[i][j]==1)
                matrix[i][j] += min({left,up,diagonal});
                count+=matrix[i][j];
                // cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        return count;
    }
};