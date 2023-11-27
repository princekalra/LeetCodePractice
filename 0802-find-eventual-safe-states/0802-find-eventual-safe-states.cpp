class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int ver = graph.size();
	vector<int>adj[ver];
	vector<int>indegree(ver,0);
        for(int i=0;i<ver;i++) {
	for(auto x:graph[i]) {
		adj[x].push_back(i);
			indegree[i]++;
		}
           }
	queue<int>q;
	vector<int>sol;
	for(int i=0;i<ver;i++) {
		if(indegree[i]==0) {
			q.push(i);
		}
	}
 	
	while(q.empty() == false) {
		int node = q.front();
		q.pop();
		sol.push_back(node);
		for(auto x:adj[node]) {
			indegree[x]--;
			if(indegree[x]==0){
				q.push(x);
			}
		}	
    }
         sort(sol.begin(),sol.end());
    return sol;
}
   
};
