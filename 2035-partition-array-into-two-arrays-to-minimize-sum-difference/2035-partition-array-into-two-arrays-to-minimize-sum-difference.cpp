class Solution {
public:
	void getAllSumCombinations(vector<int>allCombinations[],vector<int>&nums, int start, int size,int count, int sum){
		if(start == size){
			allCombinations[count].push_back(sum);
			return;
		}
		getAllSumCombinations(allCombinations,nums,start+1,size,count+1,sum+nums[start]);
getAllSumCombinations(allCombinations,nums,start+1,size,count,sum);
	}

	int getSum(int first_sum, int index, vector<int>arr[]){
		if(index<0){
			return 0;
		}
        
		int sum = 0;
		int diff = INT_MAX;
		int lb = lower_bound(arr[index].begin(),arr[index].end(),first_sum)-arr[index].begin();
		int ub = upper_bound(arr[index].begin(),arr[index].end(),first_sum)-arr[index].begin();
		if(lb>=0 && lb<arr[index].size()){
			if(abs(first_sum-arr[index][lb])<diff){
			 	sum = arr[index][lb];
				diff = abs(first_sum-arr[index][lb]);

			}
		}
        ub--;
		if(ub>=0 && ub<arr[index].size()){
			if(abs(first_sum-arr[index][ub])<diff){
			 	sum = arr[index][ub];
				diff = abs(first_sum-arr[index][ub]);

			}

		}
		return sum;
	}
    int minimumDifference(vector<int>& nums) {
        int length = nums.size();
	vector<int>firstHalf[(length/2) + 1];
	vector<int>secondHalf[(length/2) + 1];
	int sum = 0;
        for(auto num:nums){
            sum+=num;
        }
	getAllSumCombinations(firstHalf,nums,0,length/2,0,0);
	getAllSumCombinations(secondHalf,nums,length/2,length,0,0);
	int sol = INT_MAX;
	for(int i=0;i<=(length/2);i++){
		sort(secondHalf[i].begin(), secondHalf[i].end());
	}
        // for(int i=0;i<=(length/2);i++){
        //     for(auto num:firstHalf[i]){
        //         cout<<num<<" ";}
        // }
        
        // for(int i=0;i<=(length/2);i++){
        //     cout<<i<<"$"<<endl;
        //     for(auto num:secondHalf[i]){
        //         cout<<num<<" ";}
        //}
	for(int i=0;i<=(length/2);i++){
	for(auto num: firstHalf[i]){
		int first_half_sum = num;
		int second_half_sum = getSum((sum/2)-first_half_sum,(length/2)-i,secondHalf);
        // cout<<first_half_sum<<" "<<second_half_sum<<endl;
		sol = min(sol,abs(sum - 2*(first_half_sum+second_half_sum)));
	}
		}
	return sol;
    }
                                     
};
