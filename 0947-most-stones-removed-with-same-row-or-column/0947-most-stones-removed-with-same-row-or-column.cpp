
class DisjointSet {
    
    public:
    vector<int>parent,size;
    DisjointSet(int num) {
        parent.resize(num+1);
        size.resize(num+1,0);
        for(int i=0;i<=num;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int num){
        if(parent[num] == num){
            return num;
        }
        return parent[num] = findParent(parent[num]);
    }
    void unionBySize(int numa, int numb){
        int a = findParent(numa);
        int b = findParent(numb);
        if(a == b){
            return;
        }
        if(size[a]>size[b]){
                parent[b] = a;
            size[a]+=size[b];
        }
        else{
            parent[a] = b;
            size[b]+=size[a];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        for(auto it: stones) {
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
         for(auto it: ds.parent){
            cout<<it<<" ";
        }
        cout<<endl;
        unordered_map<int,int>mp;
        for(auto it:stones){
            int row = it[0];
            int col = it[1] + maxRow+1;
            cout<<row<<" "<<col<<endl;
            ds.unionBySize(row,col);
            mp[row] = 1;
            mp[col] = 1;
        }
       for(auto it: ds.parent){
            cout<<it<<" ";
        }
        cout<<endl;
        int cnt = 0;
        for(auto it: mp){
            if(ds.findParent(it.first) == it.first){
                cnt++;
            }
        }
        // for(auto it: ds.parent){
        //     cout<<it<<" ";
        // }
        return stones.size()-cnt;
        
    }
};