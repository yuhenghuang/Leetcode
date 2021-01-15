#include "utils.hpp"

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int n = s.length();

      int res = 0;

      int cnt[256] = {0};
      int l = 0, r = 0;
      while (r<n) {
        while (r<n && !cnt[s[r]]) 
          ++cnt[s[r++]];

        res = max(res, r-l);

        while (r<n && s[l]!=s[r]) 
          --cnt[s[l++]];

        --cnt[s[l++]];
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::lengthOfLongestSubstring);
  return 0;
}