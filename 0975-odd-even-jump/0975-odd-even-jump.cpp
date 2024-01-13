class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int size = arr.size();
        vector<int>odd_jump(size,-1);
        vector<int>even_jump(size,-1);
        odd_jump[size-1] = 1;
        even_jump[size-1] = 1;
        map<int,int>value_to_idx;
        value_to_idx[arr[size-1]] = size-1;
        int count = 1;
        for(int i=size-2;i>=0;i--){
            map<int,int>::iterator  it1 = value_to_idx.upper_bound(arr[i]);
            map<int,int>::iterator it2 = value_to_idx.lower_bound(arr[i]);
            if(it2!=(value_to_idx.end())){
                odd_jump[i] = even_jump[it2->second];
                if(odd_jump[i]==1){
                    count++;
                }
            }
            if(it1!=value_to_idx.begin()){
                it1--;
                even_jump[i] = odd_jump[it1->second];
            }
            value_to_idx[arr[i]] = i;
            
        }
        return count;
    }
};