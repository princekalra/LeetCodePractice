class Solution {
public:
    string add(string str1,string str2){
        string sol = "";
        int  i=  str1.length()-1;
        int j = str2.length()-1;
        int carry = 0;
    
        while(i>=0||j>=0||carry){
            int a = i>=0?str1[i]-'0':0;
            int b = j>=0?str2[j]-'0':0;
            int sum = a+b+carry;
            carry = sum/10;
            sum%=10;
            sol = to_string(sum) + sol;
            i--;
            j--;
        }
        return sol;
    }
    string multiplyHelper(string num1,string num2, int leadingzero){
        
        if(num1.length()==0||num2.length()==0){
            return "";
        }
        int length = num2.length();
        int i = length-1;
        int carry = 0;
        int last = num1[num1.length()-1]-'0';
        string sol = "";
        // cout<<num2<<" "<<last<<endl;
        while(i>=0){
            int a = i>=0?num2[i]-'0':1;
            int b = last;
            // cout<<"a"<<' '<<a<<"b "<<b<<endl;
            int prod = 0;
            
            prod= a*b;
            prod+=carry;
            carry = prod/10;
            prod%=10;
            sol = to_string(prod) + sol;
            i--;
            // cout<<a<<" "<<prod<<" "<<'#'<<sol<<endl;
        }
        if(carry!=0){
            sol = to_string(carry) + sol;
        }
        
        for(int i=0;i<leadingzero;i++){
            sol = sol+to_string(0);
        }
        // cout<<num1<<" "<<num2<<" "<<sol<<endl;
        string ans  =  add(sol,multiplyHelper(num1.substr(0,num1.length()-1),num2,leadingzero+1));
      
        // cout<<ans<<endl;
        return ans;
        
    }
    string multiply(string num1, string num2) {
      int leadingzero = 0;
        string sol = multiplyHelper(num1,num2,leadingzero);
        while(sol.length()!=1 && sol[0]=='0'){
            sol = sol.substr(1);
        }
        return sol;
    }
};