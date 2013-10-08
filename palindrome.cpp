#include <iostream>

using namespace std;

bool is_palindrome (const string & line) {
	int len = line.length ();
	bool p[len][len];
	for (int i = 0; i < len; ++i ) 
		for ( int j = 0; j < len; ++j ) 
			p[i][j] = false;
	int begin = 0, end = 0, max = 0;
	for (int i = len - 1; i >= 0; --i ) {
		for (int j = i; j < len ; ++j) {
			if (line.at(i) == line.at(j) && (i - j < 2 || p[i+1][j-1])) {
				p[i][j] = true;
				cout << "true " << "\t i : " << i << "\tj : " << j << endl;
				if (max < (j - i  + 1)) {
					max = j - i  + 1;
					begin = i;
					end = j;
					cout << "begin : " << begin << "\tend : " << end <<  "\tmax_len : " << max << endl;
				}
			}
		}
	}
	for (int i = 0; i < len; ++i ) {
		for (int j = 0; j < len; ++j ) {
			cout << p[i][j] << "\t";
		}
		cout << endl;
	}
	if (p[0][len - 1])
		return true;
	return false;
}

int main () {
	string line;
	while (getline(cin, line)) {
		cout << is_palindrome (line) << endl;
	} 
	return 0;
}
