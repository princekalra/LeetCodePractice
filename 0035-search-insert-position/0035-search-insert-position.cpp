class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int x = target;
        int n = arr.size();
        int low = 0;
	int high = n-1;
	while(low<=high) {
		int mid = (low+high)>>1;
		if(arr[mid]>=x)	{
			high = mid-1;
		}
		else {
			low = mid+1;
		}
	}
	return low;

    }
};