class Solution {
public:
    void merge(vector<pair<int,int> >&numbers,vector<int>&sol,int low,int mid,int high){
        int left = low;
        int right = mid;
        int count= 0;
        vector<pair<int,int> >merged_array;
        int index = 0;
        while(left<mid && right<=high){
            if(numbers[left].first<=numbers[right].first){
               int a = numbers[left].first;
                int b = numbers[left].second;
                merged_array.push_back({a,b});
                sol[numbers[left].second]+=(count);
                left++;
            }
            else
            {
                int a = numbers[right].first;
                int b = numbers[right].second;
                                merged_array.push_back({a,b});

                right++;
                count++;
            }
        }
        while(left<mid){
           int a = numbers[left].first;
          int b = numbers[left].second;
             merged_array.push_back({a,b});
            sol[numbers[left].second]+=(count);
            left++;
        }
        while(right<=high){
           int a = numbers[right].first;
            int b = numbers[right].second;
            merged_array.push_back({a,b});
            right++;
        }
        for(int i=low;i<=high;i++){
            numbers[i].first = merged_array[i-low].first;
            numbers[i].second = merged_array[i-low].second;
        }
        
    }
    void merge_sort(vector<pair<int,int> >&numbers, vector<int>&sol, int low, int high){
        if(low>=high){
            return ;
        }
        int mid = (low+high)>>1;
        merge_sort(numbers,sol,low,mid);
        merge_sort(numbers,sol,mid+1,high);
        merge(numbers,sol,low,mid+1,high);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int> >numbers;
        for(int i=0;i<nums.size();i++){
            numbers.push_back({nums[i],i});
        }
        vector<int>sol(nums.size(),0);
        merge_sort(numbers,sol,0,nums.size()-1);
            return sol;
    }
};