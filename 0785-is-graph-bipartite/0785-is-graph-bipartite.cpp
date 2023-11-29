class Solution {
public:
    bool BFS(queue<pair<int,int> >&q, int node, int col, vector<int>&colors, vector< vector<int> >&graph) {
        q.push({node,col});
        colors[node] = col;
        while(q.empty()==false) {
int node = q.front().first;
int col = q.front().second;
q.pop();
for(auto x:graph[node]) {
if( colors[x] ==-1) {
	colors[x] = !col;
	q.push({x,!col});
}
else if(colors[x] == col) {
return false;
}
}
	}
	return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
 	int n = graph.size();
queue<pair<int,int> >q;

int color = 0;
        
vector<int>colors(n,-1);
        for(int i=0;i<n;i++) {
            if(colors[i] == -1) {
                bool key = BFS(q,i,color,colors,graph);
                    if(!key) {
                        return false;
                    }
            }
        }
        
        return true;

    }
};

