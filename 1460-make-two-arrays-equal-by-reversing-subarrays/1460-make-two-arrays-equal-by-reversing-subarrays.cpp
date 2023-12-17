class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
	int target_length = target.size();
	int arr_length = arr.size();
	if(target_length!=arr_length){
		return false;
	}
        int freq[1001]={0};
	for(int i=0;i<target_length;i++){
		freq[target[i]]++;
	}
	for(int i=0;i<arr_length;i++){
		freq[arr[i]]-=1;
	}
	for(int i=0;i<=1000;i++){
		if(freq[i]!=0){
			return false;
		}
	}

	return true;

    }
};
