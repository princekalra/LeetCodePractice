class StockPrice {
public:
	unordered_map<int,int>mp;
	priority_queue<pair<int,int>>max_price;
	priority_queue<pair<int,int> ,vector<pair<int,int> >, greater<pair<int,int> > >min_price;
	int curr = -1;
    int latest = -1;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
       if(latest<=timestamp){
           latest = timestamp;
           curr = price;
       }
        mp[timestamp] = price;
	min_price.push({price,timestamp});
	max_price.push({price,timestamp});
    }
    
    int current() {
        return curr;
    }
    
    int maximum() {
        while(max_price.empty()==false){
		int price = max_price.top().first;
		int timestamp = max_price.top().second;
		if(mp[timestamp]==price){
			return price;
		}
		max_price.pop();
	}
	return -1;
    }
    
    int minimum() {
        while(min_price.empty()==false){
		int price = min_price.top().first;
		int timestamp = min_price.top().second;
		if(mp[timestamp] == price){
			return price;
		}
		min_price.pop();
	}
	return -1;
    }

};


/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */