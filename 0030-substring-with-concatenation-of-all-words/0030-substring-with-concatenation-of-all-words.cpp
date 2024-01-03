class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]] +=1;
        }
        vector<int>sol;
        unordered_set<string>st;
        int size = words.size()*words[0].length();
                    int wordLen = words[0].length();
        for(int i=0;(i+size)<=s.length();i++){
            if(st.find(s.substr(i,size))!=st.end()){
                sol.push_back(i);
            }
            else{
                 unordered_map<string,int>mp1;
            int j = i;
            while(j<(i+size)){
               string str = s.substr(j,wordLen);
                 if(mp1[str]<mp[str]){
                       mp1[str]+=1;
                    }
                    else{
                        break;
                    }
                j+=wordLen;  
            }
          
            if(j==(i+size)){
                sol.push_back(i);
                st.insert(s.substr(i,size));
            }
            }
        }
        return sol;
    }
};
// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
        
//         unordered_map<string, int> M, temp;
//         vector<int> Ans;
//         int N = words.size();
//         int L = words[0].size();
        
//         // Store all the frequencies of all strings
//         // in the array words[]
//         for(auto &it : words) {
//             M[it]++;
//         }
//         int size = s.length();
        
//         // Loop till possible number of starting
//         // index of the valid indices
//         for(int i = 0; i < size - N*L + 1; i++) {
            
//             // Iterate the current window of
//             // length N*L over the range
//             // [i, i + N*L] and extract the
//             // substring of length L and store
//             // it's frequency
//             for(int j = i; j < i + N*L; j+= L) {
//                 string ans = s.substr(j, L);
//                 if(M.find(ans)!= M.end()) // string exists hance check for next word else this window is usless
//                     temp[ans]++;
//                 else
//                     break;
//             }
            
//             if(temp==M) //given at max  of words are 36. hence tat max takes 36 iterations
//                 Ans.push_back(i);
            
//             // Clear the temp for another window
//             temp.clear();
//         }
        
//         // Return the resultant vector of indices
//         return Ans;
//     }
// // };
// class Solution {
// public:
//     bool check_string(string &s , int word_len , unordered_map<string,int> mapi ){
//         for (int i = 0 ; i<s.length() ; i+=word_len){
//             string temp = s.substr(i,word_len) ;
//             if(mapi.find(temp)!=mapi.end()){
//                if(--mapi[temp]==-1){
//                    return(false);
//                } 
//             }
//             else{
//                 return(false);
//             }
//         }
//         return(true) ;
//     }

//     vector<int> findSubstring(string s, vector<string>& words) {
//         unordered_map<string,int> mapi ;
//         int n = words.size() ;
//         set<string> seti;
//         for (int i = 0 ; i< n ; i++) {
//             mapi[words[i]]++ ;
//         }
//         int word_len = words[0].length() ;
//         int word_size = word_len*n ;
//         n = s.length() ;
//         vector<int> ans;
//         for (int i=0 ; i<=n-word_size ; i++){
//             string word_send = s.substr(i,word_size) ;
//             if(seti.find(word_send)!=seti.end()){
//                 ans.push_back(i);
//             }
//             else if(check_string(word_send,word_len,mapi)){
//                 ans.push_back(i);
//                 seti.insert(word_send);
//             }        
//         }
//         return(ans);
//     }
// };