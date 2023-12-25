class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
    unordered_map<int,int>mp;
        mp[0]=1;
        int length = nums.size();
        int cnt = 0;
        for(int i=0;i<length;i++){
            if(nums[i]%2!=0){
                cnt++;
            }
            nums[i] = cnt;
            mp[nums[i]]++;
        }
        if(nums[length-1]<k){
            return 0;
        }
        int mx = nums[length-1];
        int sol = 0;
        for(int i=k;i<=mx;i++){
            sol+=(mp[i]*mp[i-k]);
        }
        return sol;
    }
};

