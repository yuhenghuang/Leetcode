#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
	public:
    string getHint(string secret, string guess) {
			int n=secret.size(), bulls=0, cows=0;

			vector<int> secrets(10, 0), guesses(10, 0);

			int i;
			for (i=0; i<n; ++i) {
				if (secret[i]==guess[i])
					++bulls;
				else {
					++secrets[secret[i]-'0'];
					++guesses[guess[i]-'0'];
				}
			}

			for (i=0; i<10; ++i) 
				cows += min(secrets[i], guesses[i]);

			stringstream ss;
			ss << bulls << 'A' << cows << 'B';
			return ss.str();
    }
};

int main() {
	Solution sol;
	cout << sol.getHint("1807", "7810") << endl;
	cout << sol.getHint("1123", "0111") << endl;
	return 0;
}