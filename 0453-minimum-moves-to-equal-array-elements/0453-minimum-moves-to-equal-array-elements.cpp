class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int length = nums.size();
        int prev = 0;
        int sol = 0;
        for(int i=1;i<length;i++){
            int diff = nums[i]+prev-nums[i-1];
            sol+=diff;
            prev = diff;
        }
        return sol;
    }
};