class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       
        int len = nums.size();
         vector<int>sol(len,-1);
        stack<int>st;
        
      for(int i=(2*len-1);i>=0;i--) {
        while(st.empty()==false && st.top()<=nums[i%len]) {
            st.pop();
        }
         if(st.empty()==false) {
             sol[i%len] = st.top();
         }
          st.push(nums[i%len]);
      }
        return sol;
    }
};