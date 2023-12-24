class Solution {
public:
	int getWidth(int num){
        string str = to_string(num);
        return str.length();
		int width = 0;
		if(num<0){
			width++;
			num*=-1;
		}
		while(num!=0){
			num/=10;
			width++;
		}
		return width;
}		
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
       int row_length = grid.size();
	int col_length = grid[0].size();
	vector<int>column_width(col_length,0);
	for(int col= 0;col<col_length;col++){
		int max_width =  0;
		for(int row = 0;row<row_length;row++){
			int width = getWidth(grid[row][col]);
			max_width = max(max_width,width);
		}
		column_width[col] = max_width;
	}
	return column_width;
    }
};

