#include <iostream>
#include <vector>


using namespace std;


class Solution {
	public :
		int minDistance (string word1, string word2) {
			int len1 = word1.length ();
			int len2 = word2.length ();
			if (len1 == 0 || len2 == 0 )
				return max(len1, len2);
			vector<vector<int> > mp(len1 + 1, vector<int>(len2 + 1, 0));
			
			for (int i = 0; i < len1 + 1; ++i)
				mp[i][0] = i;
			for (int i = 0; i < len2 + 1; ++i)
				mp[0][i] = i;
			for (int i = 1; i < len1 + 1; ++i ) {
				for (int j = 1; j < len2 + 1; ++j ) {
					if (word1.at(i-1) == word2.at(j-1)) {
						mp[i][j] = mp[i-1][j-1];
					}
					else {
						mp[i][j] = min (min (mp[i-1][j] , mp[i][j-1]), mp[i-1][j-1]) + 1;
					}
				}
			}
			return mp[len1][len2];
		}
};

int main () {
	Solution s;
	string lhs,  rhs;
	while (cin >> lhs >> rhs ) 
		cout << s.minDistance (lhs, rhs) << endl;
	return 0;
}
