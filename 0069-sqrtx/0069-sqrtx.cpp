class Solution {
public:
    int mySqrt(int x) {
        if(x==1||x==0){
            return x;
        }
        int low = 0;
        int high = x/2;
        int sol = 0;
        while(low<=high){
            long long mid = (low+high)>>1;
            if((mid*mid <= x)){
                sol = mid;
                low = mid+1;
            }
             else{
                 high=mid-1;
             }
        }
        
               return sol;
    }
};