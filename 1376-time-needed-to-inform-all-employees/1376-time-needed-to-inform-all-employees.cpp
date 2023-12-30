class Solution {
public:
    struct employee{
        int id;
        int time;
        employee(int id,int time){
            this->id = id;
            this->time = time;
        }
    };
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        queue<employee>q;
        vector<int>adj[n+1];
        for(int i=0;i<n;i++){
            if(manager[i]==-1){
                continue;
            }
            adj[manager[i]].push_back(i);
        }
        q.push(employee(headID,0));
        int numOfMinutes = 0;
        while(q.empty() == false){
            employee e = q.front();
            q.pop();
            numOfMinutes = max(numOfMinutes, e.time);
            for(auto x: adj[e.id]){
                q.push(employee(x,(e.time + informTime[e.id])));
            }
        }
        return numOfMinutes;
    }
};