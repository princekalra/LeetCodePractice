class Solution {
public:
    int minOperations(int n) {
	int newn = n/2 ;
       	int sol = newn*(2*(n-1) + (newn-1)*-2);
	sol/=2;
	return sol;
    }
};
