//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++



class Solution{
  public:
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
     int len = a[0].size();
     vector<int>dp1(len+1,0);
     vector<int>dp2(len+1,0);
     dp1[0] = e[0];
     dp2[0] = e[1];
     dp1[1] = e[0] + a[0][0];
     dp2[1] = e[1] + a[1][0];
     for(int i=2;i<=len;i++){
         dp1[i] = min((dp1[i-1]+ a[0][i-1]),(dp2[i-1]+T[1][i-1] + a[0][i-1]));
         dp2[i] = min((dp2[i-1] + a[1][i-1]),(dp1[i-1] + T[0][i-1] + a[1][i-1]));
        //  cout<<dp1[i]<<" "<<dp2[i]<<endl;
     }
     int sol = min((dp1[len]+x[0]),(dp2[len]+x[1]));
     return sol;
  }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(2,vector<int>(n)), T(2,vector<int>(n));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>T[i][j];
            }
        }   
        vector<int> e(2), x(2);
        for(int i=0;i<2;i++){
            cin>>e[i];
        }
        for(int i=0;i<2;i++){
            cin>>x[i];
        }
        
        Solution ob;
        int ans = ob.carAssembly(a,T,e,x);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends