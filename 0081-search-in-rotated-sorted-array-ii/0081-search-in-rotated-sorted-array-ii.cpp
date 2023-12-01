class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
		int high = nums.size()-1;
		int sol = -1;
		while(low<=high)	{
			int mid = (low+high)>>1;
			if(nums[mid]==target)	{
				return true;
			}
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }
			if(nums[low]<=nums[mid] ) {
				if(nums[mid]>=target && target>=nums[low]) {
high = mid-1;
}
else 
 {
low = mid+1;
}		
			}
			else {
				if(target>=nums[mid] && target <=nums[high])	{
					low = mid+1;
				}
				else {
					high = mid-1;
				}
			}
		}
        
		return false;
    }
};

