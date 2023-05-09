#include <local_leetcode.hpp>

class Solution {
  public:
    int maxVowels(string s, int k) {
      bool vowels[26] = {0};
      vowels[0] = true;
      vowels['e' - 'a'] = true;
      vowels['i' - 'a'] = true;
      vowels['o' - 'a'] = true;
      vowels['u' - 'a'] = true;

      int count = 0;
      int res = 0;
      for (int i = 0; i < (int) s.size(); ++i) {
        // extend window
        if (vowels[s[i] - 'a'])
          ++count;

        // shrink window if length is over k
        if (i >= k && vowels[s[i-k] - 'a'])
          --count;

        if (count > res)
          res = count;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxVowels);
  return 0;
}