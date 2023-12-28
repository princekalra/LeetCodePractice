class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int len1 = nums1.size();
        int len2 = nums2.size();
        int median = (len1+len2+1)>>1;
        int low = 0;
        int  high = nums1.size();
        cout<<median<<endl;
        while(low<=high){
            int cut1 = (low+high)>>1;
            int cut2 = median-cut1;
            int left1 = cut1==0?INT_MIN:nums1[cut1-1];
            int left2 = cut2==0?INT_MIN:nums2[cut2-1];
            int right1 = cut1==len1?INT_MAX:nums1[cut1];
            int right2 = cut2 == len2?INT_MAX:nums2[cut2];
            if(left1<=right2&& left2<=right1){
                if((len1+len2)%2==1){
                    return max(left1,left2);
                }
                else{
                    return (max(left1,left2) + min(right1,right2))/2.0;
                }
            }
            else if(left1>right2){
                high = cut1-1;
            }
            else{
                low = cut1+1;
            }
        }
        return 0.0;
    }
};