class Solution {
public:
    vector<string>map = {"#","#","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void getAllCombination(string &digits, int index, vector<string>&sol, string str){
        if(index == digits.length()){
            sol.push_back(str);
            return;
        }
        string char_map_to_int = map[digits[index]-'0'];
        for(auto c:char_map_to_int){
            str.push_back(c);
            getAllCombination(digits,index+1,sol,str);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>sol;
        if(digits.length()==0){
            return sol;
        }
        getAllCombination(digits,0,sol,"");
        return sol;
    }
};