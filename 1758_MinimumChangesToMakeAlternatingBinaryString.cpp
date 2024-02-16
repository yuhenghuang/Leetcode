#include <local_leetcode.hpp>

class Solution {
  public:
    int minOperations(string s) {
      int zero_start = 0;
      int one_start = 0;

      for (int i = 0; i < s.size(); ++i)
        if ((s[i] - '0') ^ (i & 1))
          ++zero_start;
        else
          ++one_start;

      return min(one_start, zero_start);
    }
};


int main() {
  EXECS(Solution::minOperations);
  return 0;
}