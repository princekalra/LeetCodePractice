class StockSpanner {
public:
    stack<pair<int,int>>st;
    int cnt = -1;
    StockSpanner() {
       st.push({cnt++,INT_MAX});
       
    }
    
    int next(int price) {
       while(st.top().second<=price) {
           st.pop();
       }
        int sol;
        sol = cnt-st.top().first;
        st.push({cnt++,price});
        return sol;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */