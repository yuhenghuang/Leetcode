#include <local_leetcode.hpp>

class Solution {
  public:
    int minimumDeletions(string s) {
      int a = 0; // remaining a on right half
      for (char c : s)
        if (c == 'a')
          ++a;

      int b = 0; // remaining b on left half

      int res = INT_MAX;
      for (char c : s) {
        if (c == 'a')
          --a;

        res = min(res, a + b);

        if (c == 'b')
          ++b;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minimumDeletions);
  return 0;
}