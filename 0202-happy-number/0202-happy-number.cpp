class Solution {
public:
    int getSum(int num){
        int newnum = 0;
        while(num!=0){
            newnum += ((num%10)*(num%10));
            num/=10;
        }
        return newnum;
    }
    bool isHappy(int n) {
        unordered_map<int,int>mp;
        while(1){
            if(mp.find(n)!=mp.end()) return false;
            mp[n]=1;
            int newnum  = getSum(n);
            n = newnum;
            
            if(n==1){
                break;
            }
            
            // cout<<n<<" ";
        }
        return true;
    }
};