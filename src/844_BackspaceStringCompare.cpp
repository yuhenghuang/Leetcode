#include <local_leetcode.hpp>

class Solution {
  public:
    bool backspaceCompare(string s, string t) {
      // wrong answer

      int i = (int) s.size() - 1;
      int j = (int) t.size() - 1;

      while (i >= 0 && j >= 0) {
        int bs = 0;
        int bt = 0;

        while (i >= 0 && s[i] == '#') {
            ++bs;
            --i;
          }

        while (j >= 0 && t[j] == '#') {
          ++bt;
          --j;
        }

        i -= bs;
        j -= bt;

        if (i >= 0 && j >= 0) {
          if (s[i] == t[j]) {
            --i;
            --j;
          }
          else
            return false;
        }
      }

      return i < 0 && j < 0;
    }
};


int main() {
  EXECS(Solution::backspaceCompare);
  return 0;
}