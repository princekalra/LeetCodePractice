class Solution {
public:
    class disjointSet{
        public:
        vector<int>parent;
        vector<int>size;
      disjointSet(int n){
          parent.resize(n);
          size.resize(n);
          for(int i=0;i<n;i++){
              parent[i] = i;
              size[i]=1;
          }
      }  
        int find_parent(int node){
            if(parent[node]==node){
                return node;
            }
            return parent[node] = find_parent(parent[node]);
        }
        void union_by_size(int a,int b){
            int parent_a = find_parent(a);
            int parent_b = find_parent(b);
            if(parent_a==parent_b){
                return;
            }
            if(size[parent_a]>size[parent_b]){
                parent[parent_b] = parent_a;
                size[parent_a]+=size[parent_b];
            }
            else{
                parent[parent_a] = parent_b;
                size[parent_b]+=size[parent_a];
            }
        }
    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        disjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(isConnected[i][j]==1)
                {
                                    ds.union_by_size(i,j);
                }
            }
        }
        int cnt= 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                cnt++;
            }
        }
        return cnt;
    }
};