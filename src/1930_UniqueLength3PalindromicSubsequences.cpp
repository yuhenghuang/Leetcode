#include <local_leetcode.hpp>

class Solution {
  public:
    int countPalindromicSubsequence(string s) {
      bool dp1[26] = {0};
      bool dp2[1024] = {0};
      bool dp3[1 << 15] = {0};

      for (char c : s) {
        int b = c - 'a';
        for (int i = 0; i < 26; ++i) 
          if (dp2[(b << 5) | i])
            dp3[(b << 10) | (i << 5) | b] = true;

        for (int i = 0; i < 26; ++i)
          if (dp1[i])
            dp2[(i << 5) | b] = true;

        dp1[b] = true;
      }

      int res = 0;
      for (int i = 0; i < (1 << 15); ++i)
        if (dp3[i])
          ++res;

      return res;
    }
};


int main() {
  EXECS(Solution::countPalindromicSubsequence);
  return 0;
}