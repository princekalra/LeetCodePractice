class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>sol;
        int mx = 0;
        
        deque<int>dq;
        for(int i=0;i<k;i++) 
        {
            while(dq.empty()==false && nums[dq.back()]<=nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if(nums[mx]<=nums[i]) {
                mx = i;
            }
        }
        sol.push_back(nums[mx]);
        for(int i=k;i<nums.size();i++) {
            while(dq.empty()==false && i-dq.front()>=(k)) {
                dq.pop_front();
            }
              while(dq.empty()==false && nums[dq.back()]<=nums[i]) {
                dq.pop_back();
            }
                         dq.push_back(i);

            mx = max(mx,dq.front());
            if(nums[mx]<=nums[i]) {
                mx = i;
            }
            sol.push_back(nums[mx]);
        }
        return sol;
    }
};