class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        stack<int> st;
        vector<int> left(len, -1), right(len, len);
        int sol = 0;

        for (int i = 0; i < len; ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                right[st.top()] = i;
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        for (int i = 0; i < len; ++i) {
            sol = max(sol, heights[i] * (right[i] - left[i] - 1));
        }

        return sol;
    }
};