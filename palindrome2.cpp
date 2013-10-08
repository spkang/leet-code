// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
using namespace std;


class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length ();
        int dp[len  + 1];
        for (int i = 0; i <= len; ++i)
            dp[i] = len - i;
        bool isp[len][len];
        for (int i = 0 ; i < len; ++i ) {
            for (int j = 0; j < len; ++j ) {
                isp[i][j] = false;
            }                
        }

        for (int i = len - 1; i >= 0; --i ) {
            for (int j = i; j < len; ++j) {
                if (s.at(i) == s.at(j) && (j - i < 2 || isp[i+1][j - 1])) {
                    isp[i][j] = true;
                    dp[i] = std::min (dp[i], dp[j + 1] + 1);
                }           
            }
        }
        return dp[0] - 1;
    }
};


int main() {
    
    Solution s;
    string line;
    while (getline (std::cin, line)) {
        cout << "line : " << line << endl;
        std::cout << s.minCut (line) << endl;
    }
    return 0;
}