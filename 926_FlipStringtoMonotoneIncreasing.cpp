#include <local_leetcode.hpp>

class Solution {
  public:
    int minFlipsMonoIncr(string s) {
      int n = s.size();
      int total = 0;
      for (char c : s)
        if (c == '1')
          ++total;

      // flip all 1 to 0
      int res = total;

      int ones = 0;
      for (int i = 0; i < n; ++i) {
        // num of ones in [0, i) and zeros in [i, n)
        res = min(res, 2 * ones + n - i - total);

        // num of ones in [0, i]
        if (s[i] == '1')
          ++ones;
      }


      return res;
    }

    int minFlipsMonoIncrIter(string s) {
      typedef pair<int, int> ii_t;

      int n = s.size();

      int total = count_if(s.begin(), s.end(), [](char c) { return c == '1'; });

      // unfinished

      return -1;
    }
};


int main() {
  EXECS(Solution::minFlipsMonoIncr);
  return 0;
}