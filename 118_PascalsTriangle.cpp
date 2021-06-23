#include "utils2.hpp"

class Solution {
  public:
    vector<vector<int>> generate(int n) {
      vector<vector<int>> res(n);

      // fill the vector of length n with 1
      vector<int> temp(n, 1);
      for (int i = 0; i < n; ++i) {
        // update each row in-place
        for (int j = i - 1; j >= 1; --j)
          temp[j] += temp[j - 1];

        // copy if not last row, else replace(swap)
        if (i < n - 1)
          res[i].assign(temp.begin(), temp.begin() + i + 1);
        else
          swap(res[i], temp);
      }
      
      return res;
    }
};


int main() {
  UFUNC(Solution::generate);
  return 0;
}