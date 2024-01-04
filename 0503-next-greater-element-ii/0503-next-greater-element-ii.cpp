class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int>sol(len,-1);
        stack<int>st;
        for(int i=0;i<2*len;i++){
            while(st.empty()==false && nums[st.top()]<nums[i%len]){
                sol[st.top()] = nums[i%len];
                st.pop();
            }
                st.push(i%len);
        }
        return sol;
    }
};