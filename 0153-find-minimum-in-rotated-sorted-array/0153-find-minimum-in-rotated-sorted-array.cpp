class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0;
    int high = arr.size()-1;
    if(arr[low]<=arr[high]) {
        return arr[0];
    }
    while(low<=high) {
        int mid = (low+high)>>1;
        if(arr[mid]>=arr[0]) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return arr[low];
    }
};