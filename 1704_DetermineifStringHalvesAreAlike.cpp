#include <local_leetcode.hpp>

class Solution {
  public:
    bool halvesAreAlike(string s) {
      bool is_vowel[26] = {0};
      is_vowel[0] = is_vowel[4] = is_vowel[8] = is_vowel[14] = is_vowel[20] = true;

      const int n = s.size();

      int diff = 0;
      for (int i = 0, j = n - 1; i < j; ++i, --j) {
        if (is_vowel[s[i] - (s[i] >= 'a' ? 'a' : 'A')])
          ++diff;

        if (is_vowel[s[j] - (s[j] >= 'a' ? 'a' : 'A')])
          --diff;
      }

      return diff == 0;
    }
};


int main() {
  EXECS(Solution::halvesAreAlike);
  return 0;
}