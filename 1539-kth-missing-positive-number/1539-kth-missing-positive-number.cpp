class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
     
       int low = 0;
        int high = arr.size()-1;
        while(low<=high){
            int mid = (low+high)>>1;
            int missing = arr[mid] - (mid+1);
            if(missing>=k){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return high+k+1;
    }
};