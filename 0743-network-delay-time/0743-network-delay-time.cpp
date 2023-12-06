class Solution {
public:
	struct node {
 		int data;
		int weight;
		node(int node_data, int node_weight) 
			{
			data = node_data;
			weight = node_weight;
			} 
	};
	struct cmp {
 		bool operator()(const node &node1, const node &node2) {
				return node1.weight<node2.weight;
		}
	};
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<node>adj[n+1];
		for(auto time: times) {
			int src = time[0];
			int destination = time[1];
			int weight = time[2];
			adj[src].push_back(node(destination,weight));
		}
		priority_queue<node, vector<node>,cmp>pq;
		vector<int>minDistance(n+1,INT_MAX);
		minDistance[k] = 0;
		pq.push(node(k,0));
		while(pq.empty()==false) {
			int source = pq.top().data;
			int weight = pq.top().weight;		


				pq.pop();




			for(auto x: adj[source]) {
				if(minDistance[x.data]>minDistance[source] + x.weight)	{
			minDistance[x.data] = minDistance[source] + x.weight;
pq.push(node(x.data,minDistance[x.data]));		
}
}
}
int sol = -1;
		for(int i=1;i<=n;i++) {
            cout<<minDistance[i]<<" ";
			sol = max(sol,minDistance[i]);
		}
		return sol==INT_MAX?-1:sol;
    }
};
