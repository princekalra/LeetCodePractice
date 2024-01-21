class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 1;
        int high = arr.size()-2;
        if(arr[low]<arr[low-1]){
            return low-1;
        }
        if(arr[high+1]>arr[high]){
            return high+1;
        }
        while(low<=high){
            int mid = (low+high)>>1;
            if(arr[mid]>arr[mid-1]&& arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(arr[mid]>arr[mid-1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
        
    }
};