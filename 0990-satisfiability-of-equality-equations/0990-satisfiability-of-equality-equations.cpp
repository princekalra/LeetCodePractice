class Solution {
public:
    class disjointSet {
        public:
        vector<int>parent,size;
        disjointSet(int n){
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        int find_parent(int src){
            if(parent[src]==src){
                return src;
            }
            return parent[src] = find_parent(parent[src]);
        }
        void union_by_size(int src, int des){
            int src_parent = find_parent(src);
            int des_parent = find_parent(des);
            if(src_parent==des_parent){
                return;
            }
            if(size[src_parent]>size[des_parent]){
                parent[des_parent] = src_parent;
                size[src_parent]+=size[des_parent];
            }
            else{
                parent[src_parent] = des_parent;
                size[des_parent]+=size[src_parent];
            }
        }
    };
    bool equationsPossible(vector<string>& equations) {
        disjointSet ds(27);
        sort(equations.begin(),equations.end(),[](string &a, string &b){
           return a.substr(1,2)=="=="&&b.substr(1,2)=="!=";
        });
        for(auto equation: equations){
            int src = equation[0]-'a';
            int des = equation[3]-'a';
            if(equation[1]=='!'){
                if(ds.find_parent(src)==ds.find_parent(des)){
                    return false;
                }
            }
            else{
                ds.union_by_size(src,des);
            }
        }
        return true;
    }
};