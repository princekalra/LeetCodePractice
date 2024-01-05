class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_of_five = 0;
        int count_of_ten = 0;
        for(auto bill:bills){
            if(bill == 5){
                count_of_five++;
            }
            else if(bill == 10){
                if(count_of_five>0){
                    count_of_five--;
                    count_of_ten++;
                }
                else{
                    return false;
                }
            }
            else{
                if((count_of_five>=3)||(count_of_five>0 && count_of_ten>0)){
                    if(count_of_ten>0){
                        count_of_ten--;
                        count_of_five--;
                    }
                    else{
                        count_of_five-=3;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};