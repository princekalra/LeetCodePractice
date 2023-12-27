class Solution {
public:
    int getMax(vector<int>nums){
        int mx = 0;
        for(auto num:nums){
            mx = max(mx,num);
        }
        return mx;
    }
    int getSum(vector<int>&nums){
        int sum = 0;
        for(auto num:nums){
            sum+=num;
        }
        return sum;
    }
    bool isPossible(vector<int>& nums, int k, int subsum){
        int cnt = 1;
        int sum = 0;
        for(auto num:nums){
            sum+=num;
            if(sum>subsum){
                sum = num;
                cnt++;
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = getMax(nums);
        int high = getSum(nums);
        while(low<=high){
            int mid = (low+high)>>1;
            if(isPossible(nums,k,mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};