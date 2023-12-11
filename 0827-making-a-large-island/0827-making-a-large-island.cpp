class Solution {
public:
class disjointSet{
    public:
    	vector<int>parent,size;

	disjointSet(int num)	{
		parent.resize(num);
		size.resize(num);
		for(int i=0;i<num;i++){
			parent[i] = i;
			size[i] = 1;
		}
	}
	int findParent(int num)	{
		if(parent[num] == num){
			return num;
		}
		return parent[num] = findParent(parent[num]);
	}
	void unionBySize(int a,int b)	{
		int parent_a = findParent(a);
		int parent_b = findParent(b);
		if(parent_a==parent_b){
			return;
		}
		if(size[parent_a]>size[parent_b])	{
			parent[parent_b] = parent_a;
			size[parent_a]+=size[parent_b];
		}
		else {
			parent[parent_a] = parent_b;
			size[parent_b]+=size[parent_a];
		}
	}

};
	bool isValid(int row,int col,int n){
		return (row>=0 && row<n && col>=0 && col<n);
	}
    int largestIsland(vector<vector<int>>& grid) {
        int  n= grid.size();
	disjointSet ds(n*n);
	int cnt = 0;
	vector< vector<bool> >visited(n,vector<bool>(n,false));
	int sol = 0;
	for(int i=0;i<n;i++)	{
		for(int j=0;j<n;j++)	{
			if(grid[i][j]==0){
				continue;
			}
			if(visited[i][j] == true){
				continue;
			}
			
			if(visited[i][j] == false)	{
				visited[i][j]  = true;
				int node = i*n + j;
				cnt++;
				vector<pair<int,int> >adj = {{0,-1},{-1,0},{0,1},{1,0}};	
for(int k=0;k<4;k++)	{
	int newrow = i + adj[k].first;
	int newcol = j + adj[k].second;
	if(isValid(newrow,newcol, n)){
		if(visited[newrow][newcol]){
		 	cnt-=1;
			int newnode = newrow*n + newcol;
			ds.unionBySize(node,newnode);
		}
	}
}
}
		}
		}
		for(int i=0;i<n*n;i++){
			sol = max(sol,ds.size[i]);
		}



for(int i=0;i<n;i++){
for(int j=0;j<n;j++)
{
    if(grid[i][j]==0 && visited[i][j] == false){
                    int node = i*n + j;
                    vector<pair<int,int> >adj = {{0,-1},{-1,0},{0,1},{1,0}};	
                        int newsol = 1;
        unordered_set<int>st;
    for(int k=0;k<4;k++)	{
        int newrow = i + adj[k].first;
        int newcol = j + adj[k].second;
        if(isValid(newrow,newcol, n)){

            if(visited[newrow][newcol]){
                           
                int newnode = newrow*n + newcol;
                int parent_newnode = ds.findParent(newnode);
                if(st.count(parent_newnode)==0){
                     newsol+=ds.size[parent_newnode];
                    st.insert(parent_newnode);
                }
               

                // ds.unionBySize(node,newnode);
            }
        }
    }
    cout<<newsol<<endl;
    sol = max(sol,newsol);
		
					}
}
			}
		
	return sol;
    }
};
