class Solution {
public:
    int getMaxHistogram(vector<int>&heights){
        int length = heights.size();
        vector<int>left(length,-1);
        vector<int>right(length,length);
        stack<int>st;
        for(int i=0;i<length;i++){
            while(st.empty()==false && heights[st.top()]>heights[i]){
                right[st.top()] = i;
                st.pop();
            }
            if(st.empty()){
                left[i] = -1;
            }
            else{
                left[i] = st.top();
            }
            st.push(i);
        }
        int area = 0;
        for(int i=0;i<length;i++){
            area = max(area,(right[i]-left[i]-1)*heights[i]);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int length_col = matrix[0].size();
        int length_row = matrix.size();
        vector<int>heights(length_col,0);
        int max_area = 0;
        for(int i=0;i<length_row;i++){
            for(int j=0;j<length_col;j++){
                if(matrix[i][j]=='0'){
                    heights[j] = 0;
                }
                else{
                    heights[j]+=1;
                }
            }
            int area = getMaxHistogram(heights);
            max_area = max(area,max_area);
        }
        return max_area;
    }
};