class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
	int sol = 0;
	int len = customers.size();
	for(int i=0;i<len;i++) {
		if(grumpy[i]==0) {
			sol+=customers[i];
		}
	}
	int end = 0;
	int start = 0;
	int mxAdd = 0;
	int add=0;
	while(end<len) {
		if(end-start<minutes) {
if(grumpy[end]){
add+=customers[end];
}
end++;
}
else {
if(grumpy[start]) {
add-=customers[start];
}
start++;
}
mxAdd = max(add,mxAdd);	
}
sol+=mxAdd;
return sol;
    }
};

