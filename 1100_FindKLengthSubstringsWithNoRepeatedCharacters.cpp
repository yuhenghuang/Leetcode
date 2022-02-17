#include <local_leetcode.hpp>

class Solution {
  public:
    int numKLenSubstrNoRepeats(string s, int k) {
      if (s.size() < k)
        return 0;

      int16_t count[26] = {0};
      int unique = 0;
      
      int i = 0;
      for (; i < k; ++i)
        if (++count[s[i] - 'a'] == 1)
          ++unique;

      int res = unique == k ? 1 : 0;

      for (; i < s.size(); ++i) {
        if (++count[s[i] - 'a'] == 1)
          ++unique;

        if (--count[s[i - k] - 'a'] == 0)
          --unique;

        if (unique == k)
          ++res;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::numKLenSubstrNoRepeats);
  return 0;
}
