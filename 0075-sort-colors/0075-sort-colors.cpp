class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int low = 0;
        int high = len-1;
        int i =0;
         while(i<=high && low < high){
            if(nums[i]==0) {
                swap(nums[low],nums[i]);
                low++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[high]);
                high--;
                i--;
            }
             for(auto x: nums) {
                 cout<<x<<" ";
             }
             cout<<endl;
             i++;
        }
    }
};