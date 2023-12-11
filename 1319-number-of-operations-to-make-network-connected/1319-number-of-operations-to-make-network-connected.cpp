class Solution {
public:
	class disjointSet {
        public:
		vector<int>parent, size;
		disjointSet(int num)	{
			parent.resize(num+1);
			size.resize(num+1);
			for(int i=0;i<num;i++){
				size[i] = 1;
				parent[i] = i;
			}
		}
		int findParent(int a) {
			if(parent[a] ==a){
				return a;
			}
			return parent[a] = findParent(parent[a]);
		}
		void unionBySize(int a,int b) {
			int parent_a = findParent(a);
			int parent_b = findParent(b);
			if(parent_a == parent_b){
				return;
			}
			if(size[parent_a]>size[parent_b]){
				parent[parent_b] = parent_a;
				size[parent_a]+=size[parent_b];
			}
			else {
				parent[parent_a] = parent_b;
				size[parent_b]+=size[parent_a];
			}
		}
	};
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len = connections.size();
	if(len<(n-1)){
		return -1;
	}
	disjointSet ds(n);
	for(int i=0;i<len;i++)	{
		int a = connections[i][0];
		int b = connections[i][1];
		ds.unionBySize(a,b);
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
        // cout<<i<<" "<<ds.parent[i]<<endl;
		if(ds.parent[i]==i){
			cnt++;
		}
	}
	return cnt-1;
	
    }
};
