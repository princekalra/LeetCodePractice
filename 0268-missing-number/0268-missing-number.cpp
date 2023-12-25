class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int length = nums.size();
        int xorsum = 0;
        for(int i=0;i<=length;i++){
            xorsum^=i;
            if(i<length){
                xorsum^=nums[i];
            }
        }
        return xorsum;
    }
};