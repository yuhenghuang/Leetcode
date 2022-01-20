#include <local_leetcode.hpp>

class Solution {
  public:
    string convert(string s, int numRows) {
      if (numRows == 1)
        return s;

      int mod = numRows * 2 - 2;

      string rows[numRows];
      for (int i = 0; i < s.size(); ++i) {
        int r = i % mod;
        if (r >= numRows)
          r = mod - r;

        rows[r].push_back(s[i]);
      }

      string res;
      for (int i = 0; i < numRows; ++i)
        res += rows[i];

      return res;
    }
};


int main() {
  EXECS(Solution::convert);
  return 0;
}