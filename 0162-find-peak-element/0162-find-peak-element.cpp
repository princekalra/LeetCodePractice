class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
		int high = nums.size()-1;
		while(low<=high)	{
			int mid = (low+high)>>1;
			if(mid==0) {
				if(mid==nums.size()-1) {
					return mid;
				}
				if(nums[mid]>nums[mid+1]) {
					return mid;
				}
                low = mid+1;
			 }
			else if(mid ==nums.size()-1) {
				if(nums[mid]>nums[mid-1]) {
					return mid;
				}
                high = mid-1;
			}
			else if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])	{
				return mid;
			}
			else if(nums[mid]> nums[mid-1]) {
				low = mid+1;
			}
			else {
				high = mid-1;
			}
		}
		return -1;
			
    }
};

