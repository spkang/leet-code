#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode (int x ) : val (x), left (NULL), right (NULL) {}
};

class Solution {
public :
	int index;
	Solution () : index (0){
		
	}
	~Solution () {}

	bool hasPathSum (TreeNode * root , int sum ) {
		return isExists (root, sum, 0);
	}
	bool isExists (TreeNode * root, int sum, int cur_sum) {
		if (root) {
			if (root->left == NULL && root->right == NULL && sum == cur_sum + root->val) {
				return true;
			}
			return ( isExists (root->left, sum, cur_sum + root->val) || isExists (root->right, sum, cur_sum + root->val) );
		}
		return false;
	}
	TreeNode * createTree (TreeNode * root, vector<int> num) {
		if (root == NULL) {
			int t  = num.at(index);
			++index;
			cout << "input node val >>> " << t << endl ;
			
			if (t > 0) {
				root = new TreeNode (t);
				root->left = createTree (root->left, num);
				root->right = createTree (root->right, num);
				return root;
			}
			else 
				return NULL;
		}
		return root;
	}

		

	void delTree (TreeNode * root) {
		if (root) {
			delTree (root->left);
			delTree (root->right);
			cout << "del node : " << root->val << endl;
			delete root;
			root = NULL;
		}
	} 
};

int main () {
	Solution s;
	int  a[] = {5, 4, 11, 7, -1, -1, 2, -1, -1, -1, 8, 13, -1, -1, 4, -1, 1, -1, -1};
	vector <int> v(a, a + sizeof (a) / sizeof(a[0]));
	TreeNode * root = NULL;
	root = s.createTree (root, v);
	int sum ;
	cout << "input sum >>>>>>>";
	while  (cin >> sum && sum > 0) {
		cout << "has path sum " << s.hasPathSum (root, sum) << endl;
		cout << "input sum >>>>>>>";
	}
	s.delTree (root);

	return 0;
}
