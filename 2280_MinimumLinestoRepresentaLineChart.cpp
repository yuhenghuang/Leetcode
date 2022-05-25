#include <local_leetcode.hpp>

class Solution {
  public:
    int minimumLines(vector<vector<int>>& stockPrices) {
      int n = stockPrices.size();
      if (n < 2)
        return n - 1;

      sort(stockPrices.begin(), stockPrices.end());

      int64_t w1 = stockPrices[1][0] - stockPrices[0][0];
      int64_t h1 = stockPrices[1][1] - stockPrices[0][1];

      int res = 1;
      for (int i = 2; i < n; ++i) {
        int64_t w2 = stockPrices[i][0] - stockPrices[i-1][0];
        int64_t h2 = stockPrices[i][1] - stockPrices[i-1][1];

        if (w1 * h2 != w2 * h1) {
          w1 = w2;
          h1 = h2;

          ++res;
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minimumLines);
  return 0;
}