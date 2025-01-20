#include <local_leetcode.hpp>

class Solution {
  public:
    string minWindow(string s, string t) {
      int count[256] = {0};
      int chars = 0;
      
      for (char c : t)
        if (count[c]++ == 0)
          ++chars;

      int st, len = INT_MAX;

      int n = s.size();
      int i = 0, j = 0;
      while (i < n) {
        if (j < n && chars > 0) {
          if (count[s[j++]]-- == 1)
            --chars;
        }
        else {
          if (++count[s[i++]] == 1)
            ++chars;
        }

        if (chars == 0 && j - i < len) {
          len = j - i;
          st = i;
        }
      }

      return len == INT_MAX ? "" : s.substr(st, len);
    }
};


int main() {
  EXECS(Solution::minWindow);
  return 0;
}