//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
       
       vector<int>height_diff(n,0);
      int last = 0;
       for(int i=0;i<n;i++){
          last = max(arr[i],last);
          height_diff[i] = last;
       }
       
       last = 0;
       for(int i=n-1;i>=0;i--){
           last = max(last,arr[i]);
         height_diff[i] = min(height_diff[i],last) - arr[i];
       }
       long long sol =0;
       for(int i=0;i<n;i++){
           sol+=height_diff[i];
       }
       return sol;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends