class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long,int> >dq;
        long long sum = 0;
        int length_num = nums.size();
        int sol = INT_MAX;
        for(int i=0;i<length_num;i++){
            sum+=nums[i];
            if(sum>=k){
                sol = min(sol,i+1);
            }
             while(dq.empty() == false && sum-dq.front().first>=k){
                 sol = min(sol,i-dq.front().second);
                dq.pop_front();
            }
            while(dq.empty() == false && dq.back().first>=sum){
                dq.pop_back();
            }
           
            dq.push_back({sum,i});

        }
        if(sol==INT_MAX){
            sol = -1;
        }
        return sol;
    }
};