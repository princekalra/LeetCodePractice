class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
    	int len = prerequisites.size();
	vector<int>adj[numCourses];
	vector<int>indegree(numCourses,0);
        queue<int>q;
		for(int i=0;i<len;i++) {
			int a = prerequisites[i][0];
			int b = prerequisites[i][1];
			adj[a].push_back(b);
			indegree[b]++;
}
for(int i=0;i<numCourses;i++) {
	if(indegree[i]==0) {
		q.push(i);
 	}
}
int cnt = 0;
vector<int>vis(numCourses,0);
while(q.empty()==false) {
	int node = q.front();
	cnt++;
      	vis[node]=  1;
	q.pop();
	for(auto x:adj[node]) {
		indegree[x]-=1;
		if(vis[x]==0 && indegree[x]==0) {
q.push(x);
}
                                     }
                          }
                         if(cnt==numCourses) {
			return true;
		}
		return false; 
    }
};
