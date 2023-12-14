class Solution {
public:
	int gcd(int a,int b){
		
		if(b==0){
			return a;
		}
		return gcd(b,a%b);
	}
	int get_gcd(pair<int,int>&pair_of_number){
		int first_number = pair_of_number.first;
		int second_number = pair_of_number.second;
		return gcd(first_number,second_number);
	}
    int getFirstDigit(int num){
        while(num>=10){
            num/=10;
        }
        return num;
        
    }
    int countBeautifulPairs(vector<int>& nums) {
     	int count_of_beautiful_pairs = 0;
	int length_of_nums = nums.size();
for(int i=0;i<length_of_nums;i++){
for(int j=i+1;j<length_of_nums;j++){
	int first_digit = getFirstDigit(nums[i]);
    int last_digit = nums[j]%10;
	if(gcd(first_digit,last_digit)==1){
        // cout<<nums[i]<<" "<<nums[j]<<endl;
		count_of_beautiful_pairs++;
	}
}
}
return count_of_beautiful_pairs;
 
    }
};
