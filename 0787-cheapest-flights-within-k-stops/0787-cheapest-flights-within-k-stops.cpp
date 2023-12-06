class Solution {
public:
    struct node {
		int price;
		int stops;
		int src;
		node(int flight_price, int flight_stops, int flight_src) {
			price = flight_price;
			stops = flight_stops;
			src =  flight_src;
		}
	};
	struct cmp {
		bool operator()(const node &flight1, const node &flight2) {
			return flight1.price < flight2.price;
		}
	};
			
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<node>adj[n+1];
	  for(auto flight: flights) {
		int src = flight[0];
		int des = flight[1];
		int price = flight[2];
		adj[src].push_back(node(price,0,des));
	  }
		priority_queue< node, vector<node> , cmp >pq;
		pq.push(node(0,0,src));
	      vector<int>distance(n+1,INT_MAX);
		distance[src] = 0;
		while(pq.empty() == false) {
			node flight = pq.top();
			pq.pop();
			int source = flight.src;
			int price = flight.price;
			int stops = flight.stops;
            if(stops>k) {
                continue;
            }
            cout<<source<<" "<<price<<" "<<stops<<endl;
			for(auto x: adj[source]) {
                cout<<x.src<<" "<<x.price<<" "<<x.stops<<endl;
				if(distance[x.src]>distance[source] + x.price && (stops)<=k) {
				distance[x.src] = distance[source] + x.price;
				pq.push(node(distance[x.src], stops +1, x.src));
		}
	}
}
        for(auto x: distance) {
            cout<<x<<" ";
        }
	return distance[dst]==INT_MAX?-1:distance[dst];


    }
};
