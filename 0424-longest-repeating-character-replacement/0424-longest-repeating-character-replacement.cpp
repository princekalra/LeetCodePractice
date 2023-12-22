class Solution {
public:
    int characterReplacement(string s, int k) {
       
        int len = s.length();
        int sol = 0;
        for(char c='A';c<='Z';c++){
        int start = 0;
            int end = 0;
            int cnt = 0;
            int flip = 0;
            while(start<len && end<len){
                if(s[end]==c){
                    cnt++;
                    end++;
                }
                else{
                    if(flip<k){
                        flip++;
                        cnt++;
                        end++;
                    }
                    else{
                        if(s[start]!=c){
                            flip--;
                            cnt--;
                        }
                        else{
                            cnt--;
                        }
                        start++;
                    }
                }
                sol = max(cnt,sol);
                
            }
        }
        return sol;
    }
};