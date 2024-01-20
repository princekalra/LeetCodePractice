class Solution {
public:
    void merge(vector<pair<int,int>>&nums,int low, int mid, int high, vector<int>&sol){
        int left = low;
        int right = mid;
        vector<pair<int,int> >vec(high-low+1);
        int index = 0;
        int cnt = 0;
        while(left<mid && right<=high){
            if(nums[left].first<=nums[right].first){
                sol[nums[left].second] += cnt;
                vec[index++] = nums[left];
                left++;
            }
            else{
                cnt++;
                vec[index++] = nums[right];
                right++;
            }
        }
        while(left<mid){
            sol[nums[left].second]  += cnt;
            vec[index++] = nums[left];
            left++;
        }
        while(right<=high){
            vec[index++] = nums[right];
            right++;
        }
        for(int i = low;i<=high;i++){
            nums[i] = vec[i-low];
        }
        
    }
    void mergeSort(vector<pair<int,int>>&nums, int low, int high,vector<int>&sol){
        if(low<high){
            int mid = (low+high)>>1;
            mergeSort(nums,low,mid,sol);
            mergeSort(nums,mid+1,high,sol);
            merge(nums,low,mid+1,high,sol);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int> >vec;
        int length_num = nums.size();
        vector<int>sol(length_num,0);
        for(int i=0;i<length_num;i++){
            vec.push_back({nums[i],i});
        }
        mergeSort(vec,0,length_num-1,sol);
        return sol;
    }
};