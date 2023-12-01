class Solution {
public:
	int getSol(vector<int>&nums, int target, bool isFirst) {
		int low = 0;
		int high = nums.size()-1;
		int sol = -1;
		while(low<=high) {
			int mid = (low +high)>>1;
			if(nums[mid]==target) {
				sol = mid;
				if(isFirst) {
					high = mid-1;
				}
				else {
					low = mid+1;
				}
			}
			else if(nums[mid]>target) {
				high = mid-1;
			}
			else {
				low = mid+1;
			}
		}
		return sol;
	}
					
				
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = getSol(nums, target, true);
		int second = getSol(nums, target, false);
		return {first,second};
	
    }
};

