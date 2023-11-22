class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> sol;
        deque<int> dq;

        for (int i = 0; i < nums.size(); ++i) {
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            if (i - dq.front() >= k)
                dq.pop_front();

            if (i >= k - 1)
                sol.push_back(nums[dq.front()]);
        }

        return sol;
    }
};