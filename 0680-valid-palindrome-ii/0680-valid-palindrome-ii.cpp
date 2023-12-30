class Solution {
public:
    bool isPlaindrome(string s,int left,int right){
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;
        bool key = false;
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else{
               
                   return isPlaindrome(s,left+1,right)||isPlaindrome(s,left,right-1);
                
            }
        }
        return true;
    }
};