	class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
	unordered_map<int,int>mp;
	for(auto num: changed){
		mp[num] +=1;
	}
	vector<int>sol;
	for(auto num:changed){
		if(mp[2*num]>0 && mp[num]>0){
			sol.push_back(num);
			mp[num]--;
			mp[2*num]--;
		}
	}
	for(auto num:changed){
		if(mp[num]!=0){
			return {};
		}
	}
		return sol;
	
	
        
    }
};


