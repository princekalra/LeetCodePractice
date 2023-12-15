class Solution {
public:
    int longestSubsequence(string s, int k) {
        int string_length = s.length();
	int max_string_count = 0;
	
	for(int i=string_length-1;i>=0;i--){
		if(s[i] == '0'){
			max_string_count++;
		}
		else{
			if(max_string_count<=30){
			if(k>=(1<<max_string_count)){
				k-=(1<<max_string_count);
				max_string_count++;
			
			}

			
			
		}
        }
    }
	
    
		return max_string_count;
	}
};
