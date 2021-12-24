#include <local_leetcode.hpp>

class Solution {
  public:
    bool canConvert(string str1, string str2) {
      int n = str1.size();

      int m[26];
      memset(m, -1, sizeof(m));

      for (int i = 0; i < n; ++i) {
        int x = str1[i] - 'a';
        int y = str2[i] - 'a';

        if (m[x] < 0)
          m[x] = y;
        else if (m[x] != y)
          return false;
      }

      return true;
    }
};


int main() {
  EXECS(Solution::canConvert);
  return 0;
}