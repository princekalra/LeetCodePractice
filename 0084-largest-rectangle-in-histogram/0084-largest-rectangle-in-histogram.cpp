class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        stack<int>st;
        vector<int>vec(len, 0);
        int sol = 0;
        for(int i=0;i<len;i++) {
            while(!st.empty() && heights[st.top()]>=heights[i]) {
                st.pop();
            }
            if(st.empty()){
                vec[i] = -1;
            }
            else {
                vec[i] = st.top();
            }
            st.push(i);
        }
        while(st.empty() == false) {
            st.pop();
        }
        for(int i =len-1;i>=0;i--) {
            while(st.empty()==false && heights[st.top()]>=heights[i]) {
                st.pop();
            }
            if(st.empty()) {
                vec[i] = len-vec[i]-1;
            }
            else {
                vec[i] = st.top() - vec[i] -1;
            }
            st.push(i);
        }
        for(int i=0;i<len;i++) {
            sol = max(sol,heights[i]*vec[i]);
        }
        return sol;
    
    }
};