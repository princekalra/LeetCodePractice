class Solution {
public:
    int getSum(vector<int>&weights){
        int sum = 0;
        for(auto weight: weights){
            sum+=weight;
        }
        return sum;
    }
    int getMax(vector<int>&weights){
        int mx= 0;
        for(auto weight: weights){
            mx= max(weight,mx);
        }
        return mx;
    }
    bool isPossible(vector<int>&weights, int days, int shipWeight){
        int currentWeight = 0;
        int current_days = 1;
        for(auto weight:weights){
            currentWeight+=weight;
            if(currentWeight>shipWeight){
                current_days++;
                currentWeight = weight;
            }
        }
        return current_days<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high = getSum(weights);
        int low = getMax(weights);
        while(low<=high){
            int mid = (low+high)>>1;
            if(isPossible(weights,days,mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};