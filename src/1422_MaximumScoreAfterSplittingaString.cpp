#include <local_leetcode.hpp>

class Solution {
  public:
    int maxScore(string s) {
      int ones = count(s.begin(), s.end(), '1');

      int res = 0;
      int zeros = 0;
      for (int i = 0; i + 1 < s.size(); ++i) {
        if (s[i] == '0')
          ++zeros;
        else
          --ones;

        res = max(res, zeros + ones);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxScore);
  return 0;
}