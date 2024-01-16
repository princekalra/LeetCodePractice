class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        stack<pair<int,int> >st;
        int count = 0;
        for(int i=0;i<properties.size();i++){
            while(st.empty()==false && st.top().first<properties[i][0] && st.top().second<properties[i][1]){
                st.pop();
                count++;
            }
            st.push({properties[i][0],properties[i][1]});
        }
        return count;
    }
};