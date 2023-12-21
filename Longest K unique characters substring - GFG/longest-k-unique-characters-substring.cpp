//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

// aabacbebebe
// 3
class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int len = s.length();
        int j = 0;
        unordered_map<char,int>mp;
        int sol = -1;
        for(int i=0;i<len;i++){
            mp[s[i]]+=1;
            while(mp.size()>k && j<i){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    mp.erase(s[j]);
                }
                j++;
            }
            if(mp.size() == k)
            sol = max(sol,i-j+1);
        }
        return sol;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends