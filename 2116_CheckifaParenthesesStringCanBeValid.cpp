#include <local_leetcode.hpp>

class Solution {
  public:
    bool canBeValid(string s, string locked) {
      int n = s.size();

      if (n % 2)
        return false;

      int p = 0;
      int v = 0;
      for (int i = 0; i < n; ++i)
        if (locked[i] == '1') {
          p += s[i] == '(' ? 1 : -1;

          if (p < 0) {
            if (v < 0)
              return false;
            --v;
            ++p;
          }
        }
        else
          ++v;

      p = 0;
      v = 0;
      for (int i = n - 1; i >= 0; --i)
        if (locked[i] == '1') {
          p += s[i] == ')' ? 1 : -1;

          if (p < 0) {
            if (v < 0)
              return false;
            --v;
            ++p;
          }
        }
        else
          ++v;

      return true;
    }
};


int main() {
  EXECS(Solution::canBeValid);
  return 0;
}