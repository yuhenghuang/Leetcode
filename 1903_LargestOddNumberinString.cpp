#include <local_leetcode.hpp>

class Solution {
  public:
    string largestOddNumber(string num) {
      const int n = num.size();

      int i = 0;
      // skip leading zeros
      for (; i < n and num[i] == '0'; ++i);

      int j = n;
      // skip trailing even digits
      for (; j > i and ((num[j-1] - '0') & 1) == 0; --j);

      // [i, j) over string `num`
      return string(num, i, j - i);
    }
};


int main() {
  EXECS(Solution::largestOddNumber);
  return 0;
}