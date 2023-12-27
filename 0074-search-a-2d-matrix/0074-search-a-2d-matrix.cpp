class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size()*matrix[0].size();
        high-=1;
        int row = matrix.size();
        int col = matrix[0].size();
        while(low<=high){
            int mid = (low+high)>>1;
            if(matrix[(mid)/col][(mid)%col]==target){
                return true;
            }
            else if(matrix[(mid)/col][(mid)%col]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
};