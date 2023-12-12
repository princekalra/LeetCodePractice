class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int sell = INT_MIN;
        int profit = 0;
        for(auto price: prices){
            buy = min(price, buy);
           
            profit = max(profit,price-buy);
        }
        return profit;
    }
};