class Solution {
public:
    void helperForPermute(vector<int>&nums, int index, vector< vector<int> >&sol) {
        if(index>=nums.size()) {
            sol.push_back(nums);
            return;
        }
        for(int i= index;i<nums.size();i++) {
            swap(nums[i],nums[index]);
            helperForPermute(nums, index+1,sol);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
     vector< vector<int> > sol;
        helperForPermute(nums,0,sol);
        return sol;
    }
};