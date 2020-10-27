#include<bits/stdc++.h>
using namespace std;

struct bin_tree {
	long long val;
	bin_tree *left, *right;
};
bin_tree *root = NULL;
long long solve(bin_tree *c_node, long long z) {
	if(c_node->left == NULL && c_node->right == NULL)
		return 0;
	if(c_node->left == NULL)
		return solve(c_node->right, z);
	if(c_node->right == NULL) 
		return solve(c_node->left, z);
	if(abs(c_node->val - c_node->left->val) == z && abs(c_node->val - c_node->right->val) == z) {
		return c_node->val + (solve(c_node->left, z) + solve(c_node->right, z));
	}
	return (solve(c_node->left, z) + solve(c_node->right, z));
}
int main() {
    long long n, val;
    cin >> n;
    cin >> val;
    bin_tree *node = (bin_tree*)(malloc(sizeof(bin_tree)));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
  	root = node;
    n--;
    string s;
    long long ans = 0;
    while(n--) {
    	cin >> s >> val;
    	bin_tree *node = (bin_tree*)(malloc(sizeof(bin_tree)));
    	node->val = val;
    	bin_tree *curr_node = root;
    	node->right = NULL;
    	node->left = NULL;
    	for(int i = 0; i < s.size() - 1; i++) {
    		if(s[i] == 'L') {
    			curr_node = curr_node->left;
    		}
    		else
    			curr_node = curr_node->right;
    	}
    	if(s[s.size() - 1] == 'L') {
    		curr_node->left = node;
    	}
    	else {
    		curr_node->right = node;
    	}
    }
    long long z;
    cin >> z;
    cout << solve(root, z);
}