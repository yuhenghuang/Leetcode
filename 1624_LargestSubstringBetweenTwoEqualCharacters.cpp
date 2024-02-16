#include <local_leetcode.hpp>

class Solution {
  public:
    int maxLengthBetweenEqualCharacters(string s) {
      int pos[26];
      for (int i = 0 ; i < 26; ++i)
        // stop using INT_MAX to avoid overflow
        pos[i] = 1000;

      int res = -1;

      for (int i = 0; i < s.size(); ++i) {
        int j = s[i] - 'a';

        res = max(res, i - pos[j] - 1);

        if (pos[j] == 1000)
          pos[j] = i;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxLengthBetweenEqualCharacters);
  return 0;
}