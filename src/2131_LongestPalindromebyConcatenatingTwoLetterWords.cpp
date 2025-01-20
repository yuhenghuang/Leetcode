#include <local_leetcode.hpp>

class Solution {
  public:
    int longestPalindrome(vector<string>& words) {
      int dp1[26] = {0};
      int dp2[1024] = {0};

      for (auto& w : words) {
        if (w[0] == w[1])
          ++dp1[w[0] - 'a'];
        else 
          ++dp2[((w[0] - 'a') << 5) | (w[1] - 'a')];
      }

      constexpr int mask = 31; // 0b11111
      int res = 0;

      // 'xy' + 'yx'
      for (int i = 0; i < 1024; ++i) {
        int j = (i >> 5) | ((i & mask) << 5);
        // avoid duplicate
        if (i < j)
          res += min(dp2[i], dp2[j]) << 2;
      }

      // 'xx'
      for (int i = 0; i < 26; ++i)
        res += (dp1[i] >> 1) << 2; // dp1[i] / 2 * 4

      // one 'xx' located at center
      for (int i = 0; i < 26; ++i)
        if (dp1[i] & 1) {
          res += 2;
          break;
        }

      return res;
    }
};


int main() {
  EXECS(Solution::longestPalindrome);
  return 0;
}