#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

class Solution {
  public:
    vector<int> sequentialDigits(int low, int high) {
      string digits = "123456789";

      vector<int> res;

      for (int i=1; i<10; ++i) 
        for (int j=0; j<10-i; ++j) {
          int&& temp = stoi(digits.substr(j, i));
          if (low > temp) continue;
          if (high < temp) return res;
          res.push_back(temp);
        }

      return res;
    }
};

int main() {
  Solution sol;

  fstream f("Inputs/1291_SequentialDigits.txt");
  string line;
  int low, high;
  while (getline(f, line)) {
    istringstream ss(line);
    ss >> low >> high;
    vector<int>&& res = sol.sequentialDigits(low, high);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
  }

  return 0;
}