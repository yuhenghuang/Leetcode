#include <local_leetcode.hpp>

class Solution {
  public:
    int countHomogenous(string s) {
      constexpr int mod = 1e9 + 7;

      int res = 1;
      for (int i = 1, c = 1; i < (int) s.size(); ++i) {
        if (s[i] == s[i-1])
          ++c;
        else
          c = 1;

        if ((res += c) >= mod)
          res -= mod;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::countHomogenous);
  return 0;
}