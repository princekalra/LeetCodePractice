class Solution {
public:
    int getGoodPair(int num){
        if(num==1){
            return 1;
        }
        return num + getGoodPair(num-1);
    }
    int numIdenticalPairs(vector<int>& nums) {
        int arr[101] = {0};
        for(auto x: nums) {
            arr[x]+=1;
        }
        int sol = 0;
        for(int i=1;i<=100;i++) {
            if(arr[i]>=2) {
                sol+=getGoodPair(arr[i]-1);
            }
        }
        return sol;
    }
};