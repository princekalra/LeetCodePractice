class Solution {
public:
    void getLps(vector<int>&lps, string &needle){
        int i=1;
        int j=0;
        while(i<needle.length()){
            if(needle[i]==needle[j]){
                lps[i] = j+1;
                j++;
                i++;
            }
            else{
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
    }
    vector<int>kmpSearch(vector<int>&lps, string &needle,string &haystack){
        int i=0;
        vector<int>sol;
        int j=0;
        while(i<haystack.length()){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
            if(j == needle.length()){
                sol.push_back(i-needle.length());
                j = lps[j-1];
                cout<<j<<endl;
            }
        }
        return sol;
    }
    int strStr(string haystack, string needle) {
        int needle_length = needle.length();
        vector<int>lps(needle_length,0);
        getLps(lps,needle);
       vector<int>sol =kmpSearch(lps,needle,haystack);
        for(auto x:sol){
            cout<<x<<" ";
        }
        if(sol.size()>0){
            return sol[0];
        }
        return -1;
    }
};