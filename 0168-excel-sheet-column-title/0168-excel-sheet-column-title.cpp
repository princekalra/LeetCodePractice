class Solution {
public:
    string convertToTitle(int columnNumber) {
        string sol = "";
        while(columnNumber!=0){
            columnNumber--;
            int last_digit = columnNumber%26;
            cout<<last_digit<<endl;
            char c = last_digit + 'A';
            cout<<c<<endl;
            sol =   c + sol;
            columnNumber/=26;
        }
        return sol;
    }
};