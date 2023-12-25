class Solution {
public:
    int find_dis(pair<int,int>a,pair<int,int>b){
        int dis = ((b.first-a.first)*(b.first-a.first) + (b.second-a.second)* (b.second-a.second));
        return dis;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
       vector<pair<int,int> >vec;
        vec.push_back({p1[0],p1[1]});
                vec.push_back({p2[0],p2[1]});
        vec.push_back({p3[0],p3[1]});
        vec.push_back({p4[0],p4[1]});
        sort(vec.begin(), vec.end(),[](pair<int,int>&a,pair<int,int>&b){
            if(a.first<b.first)
            {
                return true;
            }
            if(a.first == b.first){
                return a.second< b.second;
            }
            return false;
        });
        // if(vec[0].first!=vec[1].first || vec[2].first!=vec[3].first){
        //     return false;
        // }
        // if(vec[0].second==vec[1].second || vec[2].second == vec[3].second){
        //     return false;
        // }
        int dist1 = find_dis(vec[0],vec[1]);
        int dist2 = find_dis(vec[0],vec[2]);
        int dist3 = find_dis(vec[0],vec[3]);
        int dist4 = find_dis(vec[1],vec[2]);
        cout<<dist1<<" "<<dist2<<" "<<dist3<<" "<<dist4<<endl;
        return dist1!=0 && dist3!=0 && dist1==dist2&&dist3==dist4;
        
        

        
    }
};