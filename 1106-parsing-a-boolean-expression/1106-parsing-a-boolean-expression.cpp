class Solution {
public:
    bool parseBoolExpr(string expression) {
        	
	int len = expression.length();
	stack<char>st1;
	stack<char>st2;
	for(int i=0;i<len;i++) {
		if(expression[i] == '(') {
			st1.push(expression[i]);
		}
		if(expression[i]==',') {
			continue;
		}
		if(expression[i]=='&'||expression[i]=='!'||expression[i]=='|') {
			st2.push(expression[i]);
		}
        if(expression[i]=='t'||expression[i]=='f') {
                st1.push(expression[i]);
        }
		if(expression[i]==')') {
		    char exp = st2.top();
			st2.pop();
			int res=-1;
			while(st1.top()!='(') {
				if(exp=='&') {
                    res = res==-1?1:res;
					res = res&(st1.top()=='t'?1:0);
				}
				else if(exp == '!') {
					res = !(st1.top()=='t'?1:0);
				}
				else {
                    res = res==-1?0:res;
					res = res|(st1.top()=='t'?1:0);
				}
				st1.pop();
			}
			st1.pop();
			st1.push(res==0?'f':'t');
		}
	}
	return st1.top()=='t';
    }
};
