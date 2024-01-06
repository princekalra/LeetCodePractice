class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
         int left_max = height[left];
        int right_max = height[right];
        int max_water = 0;
        while(left<=right){
            left_max = max(height[left],left_max);
            right_max = max(height[right],right_max);
            if(height[left]>height[right]){
                max_water+=max((min(left_max,right_max)-height[right]),0);
                right--;
            }
            else{
                 max_water+=max((min(left_max,right_max)-height[left]),0);
                left++;
            }
        }
        return max_water;
    }
};