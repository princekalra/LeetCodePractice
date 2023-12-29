/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*>mp;
        int maximum_id= 0;
        for(int i=0;i<employees.size();i++){
            mp[employees[i]->id] = employees[i];
            maximum_id = max(employees[i]->id,maximum_id);
        }
        queue<int>q;
        q.push(id);
        int sol = 0;
        vector<int>visited(maximum_id+1,false);
        while(q.empty() == false){
            int node = q.front();
            q.pop();
        sol+=mp[node]->importance;
            visited[node]=true;
            for(auto x:mp[node]->subordinates){
                if(visited[x]==false){
                    q.push(x);
                }
            }
        }
        return sol;
    }
};