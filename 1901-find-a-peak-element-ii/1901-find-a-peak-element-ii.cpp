class Solution {
public:
int getMaxIndex(vector<vector<int>>&arr,int col){
	int index = 0;
	int ele = INT_MIN;
	for(int i=0;i<arr.size();i++){
		if(arr[i][col]>ele){
			index = i;
			ele = arr[i][col];
		}
	}
	return index;
	}

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0;
	int high = mat[0].size()-1;
	while(low<=high){
		int mid = (low+high)>>1;
		int maxIndex = getMaxIndex(mat,mid);
		int left = (mid-1)>=0?mat[maxIndex][mid-1]:-1;
		int right = (mid+1)<mat[0].size()?mat[maxIndex][mid+1]:-1;
		if(mat[maxIndex][mid]>left && mat[maxIndex][mid]>right){
			return {maxIndex,mid};
		}
		else if(mat[maxIndex][mid]<left){
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	return {-1,-1};
    }
};

