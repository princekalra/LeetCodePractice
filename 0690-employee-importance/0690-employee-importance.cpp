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

        for(int i=0;i<employees.size();i++){
            mp[employees[i]->id] = employees[i];
        }
        queue<int>q;
        q.push(id);
        int sol = 0;
        vector<int>visited(2001,false);
        while(q.empty() == false){
            int node = q.front();
            cout<<node<<endl;
            q.pop();
        sol+=mp[node]->importance;
            visited[node]=true;
            for(auto x:mp[node]->subordinates){
                cout<<x<<endl;
                if(visited[x]==false){
                    q.push(x);
                }
            }
        }
        return sol;
    }
};