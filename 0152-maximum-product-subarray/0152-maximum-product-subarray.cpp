class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int prod1 = nums[0];
        int prod2 = nums[0];
        int result = nums[0];
        for(int i=1;i<len;i++) {
            int temp = max({nums[i], prod1*nums[i], prod2*nums[i]});
            prod2 = min({nums[i], prod1*nums[i], prod2*nums[i]});
            prod1 = temp;
            result = max(prod1,result);
        }
        return result;
    }
};