class Solution {
public:
    int getCount(vector<int>&nums){
        int length = nums.size();
        int low = 0;
        int high = length-1;
        while(low<=high){
            int mid = (low + high)>>1;
            if(nums[mid]<0){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return nums.size()-low;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int length_grid = grid.size();
        for(int i=0;i<length_grid;i++){
            int negative_count = getCount(grid[i]);
            count+=negative_count;
        }
        return count;
    }
};