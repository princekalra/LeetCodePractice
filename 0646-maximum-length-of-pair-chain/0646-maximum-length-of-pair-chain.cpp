class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](vector<int>&a,vector<int>&b){
            if(a[1]<b[1]){
                return true;
            }
            if(a[1]==b[1]){
                return a[0]<b[0];
            }
            return false;
        });
        int cnt=1;
        int last = 0;
        for(int i=1;i<pairs.size();i++){
            if(pairs[last][1]<pairs[i][0]){
                cnt++;
                last = i;
            }
        }
        return cnt;
    }
};