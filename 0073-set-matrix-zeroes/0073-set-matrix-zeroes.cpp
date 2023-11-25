class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowLen = matrix.size();
        int colLen = matrix[0].size();
        bool firstrow = false;
        for(int i=0;i<rowLen; i++) {
            for(int j=0;j<colLen;j++) {
                if(matrix[i][j] == 0) {
                    if(i==0) {
                        firstrow = true; 
                    }
                    else {
                        matrix[i][0] = 0;
                    }
                    matrix[0][j] = 0;
                }
            }
        }
       for(int i=1;i<rowLen;i++){
           for(int j=1;j<colLen;j++) {
               if(matrix[i][j]!=0) {
                   if(matrix[i][0]==0 ||matrix[0][j]==0) {
                       matrix[i][j] = 0;
                   }
               }
           }
       }
        if(matrix[0][0]==0) {
            for(int i=1;i<rowLen;i++) {
                matrix[i][0] = 0;
            }
        }
        if(firstrow) {
            for(int j=0;j<colLen;j++) {
                matrix[0][j] = 0;
            }
        }
    }
};