class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

	int len = nums.size();
	int start = 0;
	int sol = 0;

	int flips = 0;
	for(int end = 0;end<len;end++) {
		if(nums[end] == 0 ) {
		
			if(flips<k) {
flips++;
}
else {
		if(k!=0) {
		while(start<end and flips>=k) {
			if(nums[start]==0) {
flips--;
}
            
start++;	
}
            flips++;
		}
else {
start = end+1;
}
}
		
			
			
}
sol = max(sol,end-start+1);
}

return sol;
	
    
    }
};
