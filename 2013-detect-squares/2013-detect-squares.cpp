class DetectSquares {
public:
	vector<vector<int> >dp;
    DetectSquares() {
        dp.resize(2005,vector<int>(2005,0));
    }
    
    void add(vector<int> point) {
        int x = point[0];
	int y = point[1];
	dp[x][y]+=1;
    }
    
    int count(vector<int> point) {
        int x = point[0];
	int y = point[1];
	int count = 0;
	for(int i=1;i<=1000;i++){
//upper-left
if(x-i>=0 && y-i>=0){
count+=(dp[x-i][y]*dp[x-i][y-i]*dp[x][y-i]);
}
//down-left
if(x-i>=0 && y+i<=1000){
count+=(dp[x-i][y+i]*dp[x-i][y]*dp[x][y+i]);
}
//upper-right
if(x+i<=1000 && y-i>=0){
count+=(dp[x][y-i]*dp[x+i][y]*dp[x+i][y-i]);
}
//DOWN-RIGHT
if(x+i<=1000 && y+i<=1000){
count+=(dp[x+i][y+i]*dp[x+i][y]*dp[x][y+i]);
}
}
return count;		
    }
};


/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */