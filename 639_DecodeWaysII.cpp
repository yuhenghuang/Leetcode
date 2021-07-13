#include "utils3.hpp"


class Solution {
  public:
    int numDecodings(string s) {
      constexpr long mod = 1e9 + 7;

      long prev = 1;
      long curr = s[0] == '*' ? 9 : (s[0] != '0');
      for (int i = 1; i < s.size(); ++i) {
        long next = 0;

        char c = s[i-1];

        if (s[i] == '0') {
          if (c == '*')
            next += prev << 1;
          else if (c == '1' || c == '2')
            next += prev;
        }
        else if (s[i] == '*') {
          next += 9 * curr;

          if (c == '*')
            next += 15 * prev;
          else if (c == '1')
            next += 9 * prev;
          else if (c == '2')
            next += 6 * prev;
        }
        else {
          next += curr;

          if (s[i] >'6') {
            if (c == '1' || c == '*')
              next += prev;
          }
          else {
            if (c == '*')
              next += prev << 1;
            else if (c == '1' || c == '2')
              next += prev;
          }
        }

        prev = curr;
        curr = next % mod;
      }

      return curr;
    }
};


int main() {
  UFUNC(Solution::numDecodings);
  return 0;
}