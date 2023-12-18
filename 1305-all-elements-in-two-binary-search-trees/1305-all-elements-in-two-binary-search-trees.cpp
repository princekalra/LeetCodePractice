class Solution {
public:
	class stackIterator{
		public:
		stack<TreeNode*>st;
		stackIterator(TreeNode*root){
			pushAll(root);
}
void pushAll(TreeNode* root){
while(root!=NULL){
st.push(root);
root = root->left;
}	
}
int top() {
	return st.top()->val;
}
bool empty() {
	return st.empty();
}
void pop(){
TreeNode* node = st.top();
st.pop();
pushAll(node->right);	
}
};
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stackIterator first_iterator(root1);
	stackIterator second_iterator(root2);
	vector<int>sol;
	while(first_iterator.empty() == false && second_iterator.empty() == false){
		if(first_iterator.top()<second_iterator.top()){
			sol.push_back(first_iterator.top());
			first_iterator.pop();
		}
		else{
			sol.push_back(second_iterator.top());
			second_iterator.pop();
		}
}
	while(first_iterator.empty() == false){
		sol.push_back(first_iterator.top());
		first_iterator.pop();
	}
	while(second_iterator.empty() == false){
		sol.push_back(second_iterator.top());
		second_iterator.pop();
	}
	return sol;

    }
};
