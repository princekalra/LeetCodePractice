class Solution {
public:
  
    vector<int> asteroidCollision(vector<int>& asteroids) {
       vector<int>sol;
        stack<int>st;
        for(auto asteroid: asteroids){
            if(asteroid>0){
                st.push(asteroid);
            }
            else{
                    bool isVanished = false;
                    while(st.empty()==false && isVanished == false){
                        int top_asteroid = st.top();
                        if(abs(top_asteroid)==abs(asteroid)){
                            st.pop();
                            isVanished = true;
                        }
                        else if(abs(top_asteroid)>abs(asteroid)){
                            isVanished = true;
                        }
                        else{
                            st.pop();
                        }
                    }
                    if(isVanished == false){
                        sol.push_back(asteroid);
                    }
                }
            }
           
        
        vector<int>temp;
        while(st.empty()==false){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        for(auto num:temp){
            sol.push_back(num);
        }
        return sol;
    }
};