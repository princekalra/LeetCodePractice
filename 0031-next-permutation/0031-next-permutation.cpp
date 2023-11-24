class Solution {
public:
    void reverse(vector<int>&nums, int start, int end) {
        while(start<end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void nextPermutation(vector<int>& nums) {
     int len = nums.size();
        int i;
        for(i=len-2;i>=0;i--) {
            if(nums[i]<nums[i+1]) {
              break;   
            }
        }
       if(i==-1){
            reverse(nums, i+1, len-1);
           return;
       }
       int j= len-1;
        while(j>=0 ) {
            if(nums[j]>nums[i]) {
                swap(nums[j],nums[i]);
                break;
            }
            j--;
        }
        reverse(nums,i+1,len-1);
      
    }
};