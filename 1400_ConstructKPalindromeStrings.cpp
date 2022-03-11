#include <local_leetcode.hpp>

class Solution {
  public:
    bool canConstruct(string s, int k) {
      if (s.size() < k)
        return false;
      else if (k > 26)
        return true;

      int count[26] = {0};
      for (char c : s)
        ++count[c - 'a'];

      int rem = 0;
      for (int i = 0; i < 26; ++i)
        rem += count[i] & 1;

      return rem <= k;
    }
};


int main() {
  EXECS(Solution::canConstruct);
  return 0;
}