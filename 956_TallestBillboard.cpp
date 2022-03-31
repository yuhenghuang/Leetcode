#include <local_leetcode.hpp>

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
      const int n = rods.size();
      const int N = 1 << n;

      vector<int> dp(N);

      for (int b = 1; b < N; ++b) {
      }

      int res = 0;

      return res;
    }
};


int main() {
  EXECS(Solution::tallestBillboard);
  return 0;
}