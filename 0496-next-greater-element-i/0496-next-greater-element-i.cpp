class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mp;
        for(auto num:nums2){
                while(st.empty()==false && st.top()<num){
                    mp[st.top()] = num;
                    st.pop();
                }
                st.push(num); 
        }
        while(st.empty()==false){
            mp[st.top()] = -1;
            st.pop();
        }
        vector<int>sol;
        for(auto num:nums1){
            sol.push_back(mp[num]);
        }
        return sol;
    }
};


