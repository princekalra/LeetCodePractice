class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
       int length = nums.size();
	int k = nums.size();
        	int mx = INT_MIN;
	priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>> >pq;
	for(int i=0;i<k;i++){
		pq.push({nums[i][0],i});
        mx = max(nums[i][0],mx);
	}
	vector<int>vec(k,0);
	vector<int>sol={0,1000000};
	while(pq.empty()==false){
		int ele = pq.top().first;
		int index = pq.top().second;
		if((sol[1]-sol[0])>(mx-ele)){
			sol[1] = mx;
			sol[0] = ele;
		}
		pq.pop();
		if((vec[index]+1)<nums[index].size()){

			vec[index]+=1;
			pq.push({nums[index][vec[index]],index});
            		mx = max(mx,nums[index][vec[index]]);
		}
		else{
			break;
		}
    }
	return sol;
    }
};
