#include <local_leetcode.hpp>

class Solution {
  public:
    string repeatLimitedString(string s, int repeatLimit) {
      // wrong answer

      // char, count
      int count[26] = {0};
      for (char c : s)
        ++count[c - 'a'];

      string res;
      res.reserve(s.size());

      int i = 25;

      while (i >= 0) {
        if (count[i] > 0 && (res.empty() || res.back() != (char) ('a' + i))) {
          int repeat = min(count[i], repeatLimit);
          count[i] -= repeat;

          for (int j = 0; j < repeat; ++j)
            res.push_back((char) (i + 'a'));

          i = 25;
        }
        else
          --i;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::repeatLimitedString);
  return 0;
}