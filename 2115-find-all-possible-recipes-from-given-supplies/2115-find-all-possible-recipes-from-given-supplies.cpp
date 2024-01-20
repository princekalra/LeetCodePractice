class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
	unordered_map<string,int>supply;
	for(auto sup: supplies){
		supply[sup] = 1;
	}
	queue<string>q;
	unordered_map<string,vector<string> >mp;
	int length_ingredients = ingredients.size();
	unordered_map<string,int>freq;
	for(int i=0;i<length_ingredients;i++){
		int cnt = 0;
		for(auto ingredient:ingredients[i]){
			
			if(supply[ingredient]==0){
				cnt++;
			}
mp[ingredient].push_back(recipes[i]);
		}
		freq[recipes[i]] = cnt;
		if(freq[recipes[i]]==0){
			q.push(recipes[i]);
		}
		
	}
	vector<string>sol;
	while(q.empty()==false){
		string recipe = q.front();
		q.pop();
		supply[recipe] = 1;
		sol.push_back(recipe);
		for(auto str:mp[recipe]){
			freq[str]--;
			if(freq[str]==0){
				q.push(str);
}
			}
		
	}
		return sol;
    }
};

