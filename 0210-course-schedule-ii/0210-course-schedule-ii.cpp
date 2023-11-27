class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      	int len = prerequisites.size();
	vector<int>adj[numCourses];
	vector<int>indegree(numCourses,0);
	for(auto edge:prerequisites) {
		int a = edge[0];
		int b = edge[1];
		adj[b].push_back(a);
		indegree[a]++;
    }
	queue<int>q;
	vector<int>sol;
        vector<int>vis(numCourses,0);
        int cnt=0;
	for(int i=0;i<numCourses;i++) {
		if(indegree[i]==0) {
			q.push(i);
		}
	}
	while(q.empty() == false) {
		int node = q.front();
		cnt++;
		vis[node] = 1;
sol.push_back(node);
        q.pop();
		for(auto x:adj[node]) {
			indegree[x]--;
			if(indegree[x]==0) {
				q.push(x);
			}
}
}
if(cnt==numCourses) {
	return sol;
}
return {};
				
    }
	
};
