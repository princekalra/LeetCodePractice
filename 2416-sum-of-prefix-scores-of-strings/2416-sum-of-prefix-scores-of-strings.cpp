class Solution {
public:
class Node{
	private:
	int freq ;
	Node* links[26];
	public:
	bool isPresent(char c){
		return links[c-'a']!=NULL;
	}
	void insert(char c){
		links[c-'a'] = new Node();
	}
	Node* next(char c){
		return links[c-'a'];
	}
	void increaseFreq(){
		freq++;
	}
	int getFreqCount(){
		return freq;
	}
};









 class Trie {
	private:
		Node *root;
	public:
	Trie(){
		root = new Node();
		}
		void insert(string &word) {
			Node* node = root;
			for(auto c: word){
				if(!node->isPresent(c)){
					node->insert(c);
				}
				node = node->next(c);
				node->increaseFreq();
				}
		}
	int getCountPrefix(string &word){
		Node* node = root;
		int count = 0;
		for(auto c: word){
			if(!node->isPresent(c)){
				return count;
			}
			node = node->next(c);
			count+=node->getFreqCount();
		}
		return count;
	}
			
		
};
		
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
	vector<int>sumOfPrefixScores(words.size(),0);
	for(auto word: words){
		trie.insert(word);
	}
	for(int i=0;i<words.size();i++){
		sumOfPrefixScores[i] = trie.getCountPrefix(words[i]);
	}
return sumOfPrefixScores;
    }
};
