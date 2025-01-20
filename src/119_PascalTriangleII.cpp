#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
  public:
    vector<int> getRow(int rowIndex) {
      vector<int> res(rowIndex+1, 0);
      res[0] = 1;
      for (int i=0; i<rowIndex; ++i) 
        for (int j=i; j>=0; --j)
          res[j+1] = res[j] + res[j+1];

      return res;
    }
};

int main() {
  Solution sol;
  vector<int> res = sol.getRow(0);
  copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
  return 0;
}