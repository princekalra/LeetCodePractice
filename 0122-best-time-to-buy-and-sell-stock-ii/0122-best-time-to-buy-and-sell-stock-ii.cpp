class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buying_price = INT_MAX;
        for(auto price: prices){
            if(buying_price == INT_MAX){
                buying_price = price;
                continue;
            }
           if(price>buying_price){
               max_profit+=(price-buying_price);
           }
            buying_price = price;
        }
        return max_profit;
    }
};