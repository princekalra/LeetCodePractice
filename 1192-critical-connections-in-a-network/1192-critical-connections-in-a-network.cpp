class Solution {
public:
    void DFS(int src, vector<int>adj[], vector<bool>&visited, vector<int>&tin, vector<int>&low, int parent, vector< vector<int> >&sol, int& timer){
        visited[src] = 1;
        low[src] = timer;
        tin[src] = timer;
        timer++;
        for(auto x:adj[src]){
            if(x == parent){
                continue;
            }
            if(visited[x]==false)
            {
                DFS(x, adj, visited, tin, low, src, sol, timer);
                low[src] = min(low[src],low[x]);
                if(low[x]>tin[src]){
                    sol.push_back({src,x});
                }
            }
            else{
                low[src] = min(low[src], low[x]);
            }
            
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            vector< vector<int> >sol;
            vector<int>tin(n,0);
            vector<int>low(n,0);
            vector<int>adj[n];
            for(auto connection: connections){
                    adj[connection[0]].push_back(connection[1]);
                    adj[connection[1]].push_back(connection[0]);
            }
            int timer = 1;
            vector<bool>visited(n,false);
            for(int i=0;i<n;i++){
                if(visited[i]==false){
                    DFS(i,adj, visited, tin,low,-1,sol,timer);
                }
            }
            return sol;
    }
};