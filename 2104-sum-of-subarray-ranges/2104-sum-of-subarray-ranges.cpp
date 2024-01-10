class Solution {
public:
    // long long sumOfNumsWhichAreLargest(vector<int>&nums){
    //     stack<int>st;
    //     vector<long long>left(nums.size(),0);
    //     vector<long long>right(nums.size(),0);
    //     for(int i=0;i<nums.size();i++){
    //         while(st.empty()==false && nums[st.top()]<nums[i]){
    //             st.pop();
    //         }
    //         if(st.empty()){
    //             left[i] = i+1;
    //         }
    //         else{
    //             left[i] = i-st.top();
    //         }
    //         st.push(i);
    //     }
    //     while(st.empty()==false){
    //         st.pop();
    //     }
    //     for(int i=nums.size()-1;i>=0;i--){
    //         while(st.empty()==false && nums[st.top()]<=nums[i]){
    //             st.pop();
    //         }
    //         if(st.empty()){
    //             right[i] = nums.size()-i;
    //         }
    //         else{
    //             right[i] = st.top()-i;
    //         }
    //         st.push(i);
    //     }
    //     long long sum = 0;
    //     for(int i=0;i<nums.size();i++){
    //         // cout<<left[i]<<" "<<right[i]<<endl;
    //         long long prod = left[i]*right[i];
    //         prod = prod*nums[i];
    //         sum+=prod;
    //     }
    //     return sum;
    // }
     long long sumOfNumsWhichAreSmallest(vector<int>&nums,bool isLargest){
        stack<int>st;
        vector<int>left(nums.size(),0);
        vector<int>right(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            while(st.empty()==false && ((isLargest==false&&nums[st.top()]>nums[i]) ||(isLargest &&nums[st.top()]<nums[i]))){
                st.pop();
            }
            if(st.empty()){
                left[i] = i+1;
            }
            else{
                left[i] = i-st.top();
            }
            st.push(i);
        }
        while(st.empty()==false){
            st.pop();
        }
        for(int i=nums.size()-1;i>=0;i--){
            while(st.empty()==false && ((isLargest==false && nums[st.top()]>=nums[i])||(isLargest==true &&(nums[st.top()]<=nums[i]) ))){
                st.pop();
            }
            if(st.empty()){
                right[i] = nums.size()-i;
            }
            else{
                right[i] = st.top()-i;
            }
            st.push(i);
        }
        long long sum = 0;
         // cout<<"#"<<endl;
        for(int i=0;i<nums.size();i++){
            // cout<<left[i]<<" "<<right[i]<<endl;
            long long prod = left[i]*right[i];
            prod = prod*nums[i];
            sum+=prod;
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long sum1 = sumOfNumsWhichAreSmallest(nums,true);
        // cout<<sum1<<endl;
        long long sum2 = sumOfNumsWhichAreSmallest(nums,false);
        // cout<<sum2<<endl;
        return sum1-sum2;
        return 0;
    }
};