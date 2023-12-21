class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        int left = 0;
        int right = len-1;
        int sum = 0;
        int sol = 0;
        while(left<k){
            sum+=cardPoints[left];
            left++;
        }
        sol = max(sol,sum);
        left-=1;
        while(left>=0){
            sum-=cardPoints[left];
            sum+=cardPoints[right];
            right--;
            left--;
            sol = max(sol,sum);
        }
        return sol;
        
    }
};