class Solution {
public:
    vector<string>arr = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void helperForLetterCombinations(string &digits,int i,string str,vector<string>&sol) {
        if(i>=digits.length()){
            sol.push_back(str);
            return;
        }
        string substr = arr[digits[i]-'0'];
        for(auto c: substr)
        {
            str.push_back(c);
            helperForLetterCombinations(digits,i+1,str,sol);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string>sol;
        if(digits.length()==0){
            return sol;
        }
        helperForLetterCombinations(digits,0,"",sol);
        return sol;
    }
};