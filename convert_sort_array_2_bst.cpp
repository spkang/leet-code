#include <iostream>
#include <vector>

using namespace std;


//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public :
		TreeNode *sortedArrayToBST(vector<int> &num) {
	        // Note: The Solution object is instantiated only once and is reused by each test case.
			if (num.empty ())
				return NULL;
			return createTree (num, 0, num.size()-1);		
		}
		TreeNode * createTree (const vector <int> & num, int lhs, int rhs ) {
			if (lhs > rhs )
				return NULL;
			int mid = lhs + ((rhs - lhs) >> 1);
			TreeNode * node = new TreeNode (num.at(mid));
			node->left = createTree (num, lhs, mid - 1);
			node->right = createTree (num, mid + 1, rhs);
			return node;
		}
		void delTree (TreeNode * tree) {
			if (tree == NULL)
				return ;
			delTree (tree->left);
			delTree (tree->right);
			cout << "delete : " << tree->val << endl;
			delete tree;
			tree = NULL;
		}
		void inOrder (TreeNode * p) {
			if (p) {
				inOrder (p->left);
				cout << "traverse : " << p->val << endl;;
				inOrder (p->right);
			}
		}
};

int main () {
	Solution s;
	int  a[] = {1, 2, 3, 4, 5, 6};

	vector<int> v (a, a + sizeof(a) / sizeof (a[0]));

	TreeNode * tree = s.sortedArrayToBST (v);
		
	s.inOrder (tree);

	s.delTree (tree);

	return 0;
}
