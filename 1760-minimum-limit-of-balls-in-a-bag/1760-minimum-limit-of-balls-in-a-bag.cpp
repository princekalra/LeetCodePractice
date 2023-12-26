class Solution {
public:
    bool isPossible(vector<int>&nums, int maxOperations, int mid){
        cout<<mid<<endl;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=mid){
                continue;
            }
            int cnt = nums[i]/mid;
            if(nums[i]%mid){
                cnt+=1;
            }
            cnt-=1;
            if(cnt>maxOperations){
                return false;
            }
            maxOperations-=cnt;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int mx = 0;
        for(auto num:nums){
            mx = max(num,mx);
        }
        int high = mx;
        while(low<=high){
            int mid = (low+high)>>1;
            if(isPossible(nums,maxOperations,mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};