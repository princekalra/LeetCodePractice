class Solution {
public:
    string reverseWords(string s) {
        string sol = "";
        string word = "";
        for(auto ch: s) {
            if(ch == ' ')
            {
                sol = sol + " " + word;
                word = "";
            }
            else{
                word = ch + word;
            }
        }
        sol = sol + " " + word;
        
        return sol.substr(1);
    }
};