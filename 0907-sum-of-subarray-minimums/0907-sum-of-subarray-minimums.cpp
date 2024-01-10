class Solution {
public:
  
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7;
        stack<int>st1;
        int len = arr.size();
        vector<int>left(len,-1);
        vector<int>right(len,len);
        for(int i=0;i<len;i++)
        {
            while(st1.empty()==false && arr[st1.top()]>=arr[i]){
                st1.pop();
            }
            if(!st1.empty()){
                left[i] = i-st1.top();
            }
            else{
                left[i] = i+1;
            }
            st1.push(i);
        }
        while(st1.empty()==false){
            st1.pop();
        }
       for(int i=len-1;i>=0;i--){
           while(st1.empty()==false && arr[st1.top()]>arr[i]){
               st1.pop();
           }
           if(st1.empty()){
               right[i] = len-i;
           }
           else{
               right[i] = st1.top()-i;
           }
           st1.push(i);
       }
        int sol = 0;
        for(int i=0;i<len;i++){
         long long prod = (left[i]*right[i])%mod;
            prod = (arr[i]*prod)%mod;
            sol = (sol + prod)%mod;
        }
        return sol%mod;
    }
};