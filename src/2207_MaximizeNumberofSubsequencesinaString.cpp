#include <local_leetcode.hpp>

class Solution {
  public:
    long long maximumSubsequenceCount(string text, string pattern) {
      char f = pattern.front();
      char b = pattern.back();

      int count_f = 0;
      int count_b = 0;

      long long res = 0;
      for (char c : text) {
        if (c == f)
          ++count_f;
        else if (c == b) {
          res += count_f;
          ++count_b;
        }
      }

      if (f == b)
        return (static_cast<long long>(count_f) * (count_f + 1)) / 2;

      return res + max(count_f, count_b);
    }
};


int main() {
  EXECS(Solution::maximumSubsequenceCount);
  return 0;
}